#include "board_iterators.h"
#include "cell.h"

Iterator::Iterator(Cell* cell) : cell(cell)
{
}

Cell& Iterator::operator*()
{
  return *cell;
}

ColIterator::ColIterator(Cell& cell) : Iterator(&cell)
{
}

void ColIterator::operator++(int)
{
  cell += 9;
}

RowIterator::RowIterator(Cell& cell) : Iterator(&cell)
{
}

void RowIterator::operator++(int)
{
  cell++;
}

BoxIterator::BoxIterator(Cell& cell) : Iterator(&cell)
{
}

void BoxIterator::operator++(int)
{
  cell_num++;
  uint8_t const y = cell_num / 3;
  cell += 1 + (y * 6);
  cell_num -= y * 3;
}
