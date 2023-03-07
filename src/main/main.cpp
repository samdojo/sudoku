#include <chrono>

#include "board.h"
#include "solver.h"
#include "real_time_engine.h"


int main() {
  Board board;
  board.load("boards/puzzle-1.txt");
  std::cout << board << std::endl;

  auto solve = [] (Board& board)
  {
    return Solver::solve(board);
  };

  auto engine = RealTimeEngine<decltype(solve), Board&>(solve, board);
  auto [solved, duration] = engine.run();

  std::cout << "solved puzzle in " << duration << "ms\n";

  if (solved)
  {
    std::cout << board;
  }
  else
  {
    std::cout << "no solution" << std::endl;
  }

  return 0;
}
