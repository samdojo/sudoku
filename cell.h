#include <cstddef>
#include <stdint.h>


class Cell {
protected:
  uint8_t value;

public:
  void operator=(char c);
  void operator=(uint8_t c);
  friend std::ostream& operator <<(std::ostream& os, Cell const cell);
};

