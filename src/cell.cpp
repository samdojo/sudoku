#include <iostream>

#include "cell.h"

Cell::Cell()
{
}

Cell::Cell(char c)
{
  *this = c;
}

void Cell::operator=(char c)
{
  value = (c < '9' && c > '0') ? c - '0' : 0;
}

void Cell::operator=(uint8_t i)
{
  value = i;
}

bool Cell::operator==(uint8_t i)
{
  return value == i;
}

std::ostream& operator<<(std::ostream& os, Cell const cell)
{
  if (cell.value == 0)
  {
    os << ' ';
  }
  else
  {
    os << unsigned(cell.value);
  }
  return os;
}
