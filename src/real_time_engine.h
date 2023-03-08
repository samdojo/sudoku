#include <pthread.h>
#include <functional>
#include <cassert>
#include <sys/mman.h>
#include <atomic>
#include <chrono>


template<typename Function, typename... ArgTypes>
class RealTimeEngine
{
  static constexpr int priority = 80;
  static constexpr int policy = SCHED_FIFO;

  using FunctionReturnType = decltype(std::declval<Function>()(std::declval<ArgTypes>()...));
  static_assert(!std::is_same<FunctionReturnType, void>::value);

public:
  RealTimeEngine(Function& function, ArgTypes&... args)
    : function(function)
    , args(args...)
  {}

  std::pair<bool, int> run()
  {
    assert(mlockall(MCL_CURRENT | MCL_FUTURE) == 0);

    pthread_attr_t attr;
    assert(pthread_attr_init(&attr) == 0);
    assert(pthread_attr_setschedpolicy(&attr, policy) == 0);

    struct sched_param param;
    param.sched_priority = priority;
    assert(pthread_attr_setschedparam(&attr, &param) == 0);
    assert(pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED) == 0);
    assert(pthread_create(&thread, &attr, &RealTimeEngine::runThread, this) == 0 && "try running as root");
    assert(pthread_join(thread, NULL) == 0);

    return std::make_pair(this->return_value.load(), this->elapsed_us.load());
  }

private:
  static void* runThread(void* data) noexcept
  {
    RealTimeEngine* p_this = static_cast<RealTimeEngine*>(data);
  
    auto start = std::chrono::high_resolution_clock::now();
    p_this->return_value = p_this->function(p_this->getArgs());
    auto finish = std::chrono::high_resolution_clock::now();

    p_this->elapsed_us = std::chrono::duration_cast<std::chrono::microseconds>(finish-start).count();

    return NULL;
  }

  auto& getArgs()
  {
    return std::get<ArgTypes...>(args);
  }

  Function& function;
  std::tuple<ArgTypes&...> args;
  pthread_t thread;
  std::atomic<int> elapsed_us = 0;
  std::atomic<FunctionReturnType> return_value;
};
