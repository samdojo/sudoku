#pragma once

#include "cell.h"


struct Iterator
{
  Iterator(Cell* cell);
  virtual void operator++(int) = 0; // do not call more than 8 times
  Cell& operator*();
protected:
  Cell* cell;
};

struct ColIterator : public Iterator
{
  ColIterator(Cell& cell);
  void operator++(int) override;
};

struct RowIterator : public Iterator
{
  RowIterator(Cell& cell);
  void operator++(int) override;
};

struct BoxIterator : public Iterator
{
  BoxIterator(Cell& cell);
  void operator++(int) override;
private:
  uint8_t cell_num = 0;
};
