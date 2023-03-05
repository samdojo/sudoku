#include <fstream>
#include <assert.h>
#include <iostream>
#include <sstream>

#include "board.h"

void Board::load(char const * file_name)
{
  std::ifstream file(file_name);
  assert(file.is_open());
  std::string line;
  uint8_t row_num = 0;
  while(getline(file, line))
  {
    if (line.empty() || line.at(3) == '=')
    {
      continue;
    }
    for (int x = 0; x < BOARD_LENGTH; ++x)
    {
      uint8_t c = (x * 4) + 3;
      c += (c - 1) / 12;
      assert(row_num < 9);
      assert(x < 9);
      cells[row_num][x] = line.at(c);
    }
    row_num++;
  }
  file.close();
}

std::string Board::toStr() const
{
  std::stringstream ss;
  for (int y = 0; y < BOARD_LENGTH; ++y)
  {
    Cell const* row = cells[y];
    if (y % 3 == 0)
    {
      ss << "||=====================================||\n";
    }
    for (int x = 0; x < BOARD_LENGTH; ++x)
    {
      if (x % 3 == 0)
      {
        ss << '|';
      }
      ss << "| " << row[x] << " ";
    }
    ss << "||\n";
  }
  ss << "||=====================================||\n";
  return ss.str();
}

void Board::clear()
{
  for (int i = 0; i < BOARD_LENGTH; i++)
  {
    for (int j = 0; j < BOARD_LENGTH; j++)
    {
      cells[i][j] = ' ';
    }
  }
}

ColIterator Board::getColIter(uint8_t col)
{
  return ColIterator(cells[0][col]);
}

RowIterator Board::getRowIter(uint8_t row)
{
  return RowIterator(cells[row][0]);
}

BoxIterator Board::getBoxIter(uint8_t box)
{
  return BoxIterator(cells[(box / 3) * 3][(box % 3) * 3]);
}

std::ostream& operator<<(std::ostream& os, Board const board) {
  os << board.toStr();
  return os;
}
