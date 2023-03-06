#include <chrono>

#include "board.h"
#include "solver.h"

int main() {
  Board board;
  board.load("boards/puzzle-1.txt");
  std::cout << board << std::endl;

  Solver solver;

  auto start = std::chrono::high_resolution_clock::now();

  bool solved = solver.solve(board);

  auto finish = std::chrono::high_resolution_clock::now();
  std::cout << "solved puzzle in " << std::chrono::duration_cast<std::chrono::milliseconds>(finish-start).count() << "ms\n";
  //std::cout << std::chrono::duration_cast<std::chrono::microseconds>(finish-start).count() << "us\n";
  //std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << "ns\n";

  if (solved)
  {
    std::cout << solver.solvedBoard;
  }
  else
  {
    std::cout << "no solution" << std::endl;
  }

  return 0;
}
