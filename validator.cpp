#include "validator.h"


bool isValid(Iterator& it)
{
  bool is_in_row[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  for (int i = 0; i < BOARD_LENGTH; ++i)
  {
    uint8_t const & index = (*it).getValue();
    if (is_in_row[index])
    {
      return false;
    }
    else
    {
      is_in_row[index] = true;
    }
    it++;
  }
  return true;
}
