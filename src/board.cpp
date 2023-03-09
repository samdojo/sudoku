#include <fstream>
#include <assert.h>
#include <iostream>
#include <sstream>

#include "board.h"

namespace
{
  uint8_t x(uint8_t box) { return (box % 3) * 3; }
  uint8_t y(uint8_t box) { return (box / 3) * 3; }
}

Board::Board()
: boxIters({BoxIterator(cells[x(0)][y(0)]),
            BoxIterator(cells[x(1)][y(1)]),
            BoxIterator(cells[x(2)][y(2)]),
            BoxIterator(cells[x(3)][y(3)]),
            BoxIterator(cells[x(4)][y(4)]),
            BoxIterator(cells[x(5)][y(5)]),
            BoxIterator(cells[x(6)][y(6)]),
            BoxIterator(cells[x(7)][y(7)]),
            BoxIterator(cells[x(8)][y(8)])})
{
}

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

  for (int i = 0; i < BOARD_LENGTH; i++)
  {
    for (int j = 0; j < BOARD_LENGTH; j++)
    {
      if (cells[i][j] == 0)
      {
        emptyCells.push(&cells[i][j]);
      }
    }
  }
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
  return boxIters[box];
}

Cell* Board::getNextEmptyCell()
{
  if (!emptyCells.empty()) [[likely]]
  {
    Cell* ptr = emptyCells.top();
    emptyCells.pop();
    return ptr;
  }
  else
  {
    return nullptr;
  }
}

void Board::eraseCell(Cell* cell)
{
  *cell = uint8_t(0);
  emptyCells.push(cell);
}

std::ostream& operator<<(std::ostream& os, Board const board) {
  os << board.toStr();
  return os;
}
