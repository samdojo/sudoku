#pragma once

#include <cstddef>
#include <iostream>
#include <stack>
#include <array>

#include "cell.h"
#include "board_iterators.h"


constexpr size_t BOARD_LENGTH = 9;

struct Board
{
  Board();

  void load(char const * file_name);
  std::string toStr() const;
  void clear();

  ColIterator getColIter(uint8_t col);
  RowIterator getRowIter(uint8_t row);
  BoxIterator getBoxIter(uint8_t box);

  Cell* getNextEmptyCell(); // returns nullptr is Board is full
  void eraseCell(Cell* cell);

private:
  Cell cells[BOARD_LENGTH][BOARD_LENGTH]; // y, x
  std::stack<Cell*> emptyCells;
  std::array<BoxIterator, BOARD_LENGTH> boxIters;

public:
  friend std::ostream& operator<<(std::ostream& os, Board const board);
};
