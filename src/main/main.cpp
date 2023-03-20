#include "board.h"
#include "solver.h"
#include "real_time_engine.h"


int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "please supply 1 board to solve" << std::endl;
    return 0;
  }

  Board board;
  board.load(argv[1]);
  std::cout << board << std::endl;

  auto solve = [] (Board& board)
  {
    return Solver::solve(board);
  };

  auto engine = RealTimeEngine<decltype(solve), Board&>(solve, board);
  auto [solved, duration] = engine.run();

  std::cout << "solved puzzle in " << duration << "us\n";

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
