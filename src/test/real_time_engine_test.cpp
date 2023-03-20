#include <gtest/gtest.h>

#include "real_time_engine.h"


TEST(RealTimeEngine, DISABLED_LambdaTypes) // this test only passes as root user
{
  auto fun1 = [] { return 0; };
  auto engine1 = RealTimeEngine<decltype(fun1)>(fun1);
  auto [a1, b1] = engine1.run();

  auto fun2 = [] { return 0.0; };
  auto engine2 = RealTimeEngine<decltype(fun2)>(fun2);
  auto [a2, b2] = engine2.run();

  auto fun3 = [] { return true; };
  auto engine3 = RealTimeEngine<decltype(fun3)>(fun3);
  auto [a3, b3] = engine3.run();

  auto fun4 = [] { struct {} a; return a; };
  auto engine4 = RealTimeEngine<decltype(fun4)>(fun4);
  auto [a4, b4] = engine4.run();

  auto fun5 = [] (int) { return 0; };
  int a;
  auto engine5 = RealTimeEngine<decltype(fun5), int>(fun5, a);
  auto [a5, b5] = engine5.run();

  auto fun6 = [] (int, double) { return 0; };
  int b;
  double c;
  auto engine6 = RealTimeEngine<decltype(fun6), int, double>(fun6, b, c);
  auto [a6, b6] = engine6.run();
}
