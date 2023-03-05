#include "board.h"

int main() {
  Board board;
  board.load("boards/sudoku-puzzle-1.txt");
  std::cout << board;

  return 0;
}
