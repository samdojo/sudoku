#include <cstddef>
#include <iostream>

#include "cell.h"


constexpr size_t BOARD_LENGTH = 9;

struct Board
{
  void load(char const * file_name);
  std::string to_str() const;
  void clear();

  Cell cells[BOARD_LENGTH][BOARD_LENGTH]; // y, x

  
  friend std::ostream& operator <<(std::ostream& os, Board const board);
};