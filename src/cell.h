#pragma once

#include <cstddef>
#include <stdint.h>
#include <iostream>


struct Cell
{
  Cell();
  Cell(char c);
  inline uint8_t const & getValue() { return value; }

  void operator=(char c);
  void operator=(uint8_t c);
  bool operator==(uint8_t c);
  friend std::ostream& operator<<(std::ostream& os, Cell const cell);

protected:
  uint8_t value;
};
