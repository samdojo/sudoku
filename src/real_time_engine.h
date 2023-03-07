#include <pthread.h>
#include <functional>
#include <cassert>
#include <sys/mman.h>
#include <atomic>

template<typename Function, typename... ArgTypes>
class RealTimeEngine
{
  static constexpr int priority = 80;
  static constexpr int policy = SCHED_FIFO;

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

    return std::make_pair(this->solved.load(), this->elapsed_ms.load());
  }

private:
  static void* runThread(void* data) noexcept
  {
    RealTimeEngine* p_this = static_cast<RealTimeEngine*>(data);

    auto start = std::chrono::high_resolution_clock::now();
    p_this->solved = p_this->function(p_this->getArgs());
    auto finish = std::chrono::high_resolution_clock::now();

    p_this->elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish-start).count();

    return NULL;
  }

  auto& getArgs()
  {
    return std::get<ArgTypes...>(args);
  }

  Function& function;
  std::tuple<ArgTypes&...> args;
  pthread_t thread;
  std::atomic<int> elapsed_ms = 0;
  std::atomic<bool> solved = false;
};
