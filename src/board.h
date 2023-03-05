#pragma once

#include <cstddef>
#include <iostream>

#include "cell.h"
#include "board_iterators.h"


constexpr size_t BOARD_LENGTH = 9;

struct Board
{
  void load(char const * file_name);
  std::string toStr() const;
  void clear();

  ColIterator getColIter(uint8_t col);
  RowIterator getRowIter(uint8_t row);
  BoxIterator getBoxIter(uint8_t row);

  Cell* getNextEmptyCell(); // returns nullptr is Board is full

private:
  Cell cells[BOARD_LENGTH][BOARD_LENGTH]; // y, x

public:
  friend std::ostream& operator<<(std::ostream& os, Board const board);
};
