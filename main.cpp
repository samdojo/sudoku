#include "board.h"

int main() {
  Board board;
  board.clear();
  board.load("sudoku-puzzle-1.txt");
  std::cout << board;

  return 0;
}
