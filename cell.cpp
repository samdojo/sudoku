#include <iostream>

#include "Cell.h"

void Cell::operator=(char c)
{
  value = (c < '9' && c > '0') ? c - '0' : 0;
}

void Cell::operator=(uint8_t i)
{
  value = i;
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
