#include <chrono>

#include "board.h"
#include "solver.h"

int main() {
  Board board;
  board.load("boards/puzzle-1.txt");
  std::cout << board << std::endl;

  auto start = std::chrono::high_resolution_clock::now();
  bool solved = Solver::solve(board);
  auto finish = std::chrono::high_resolution_clock::now();

  int duration = std::chrono::duration_cast<std::chrono::milliseconds>(finish-start).count();
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
