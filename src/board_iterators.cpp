#include "board_iterators.h"
#include "cell.h"
#include "board.h"

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
  // Increment box_y. box_y should only ever be 1-3 in the block below
  box_y++;
  // is_end_of_box is 1 if box_y is 3; otherwise it's 0
  uint8_t const is_end_of_box = box_y / BOX_LENGTH;
  // Increment 1 cell forward unless we are at the end of the box's row.
  // If we are, increment by 7 to the beginning of the next row down
  cell += 1 + (is_end_of_box * 6);
  // if is_end_of_box is 3, reset it to 0
  box_y -= is_end_of_box * BOX_LENGTH;
}
