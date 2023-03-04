#include "validator.h"


bool Validator::isValid(Iterator& it)
{
  // TODO: see if using 9 values here instead of 10
  // and using index - 1 below improves or degrades
  // performance
  bool is_in_row[] = {
    false, false, false, false, false,
    false, false, false, false, false};

  for (int i = 0; i < BOARD_LENGTH; ++i)
  {
    uint8_t const & index = (*it).getValue();
    if (index != 0) // cell is not empty
    {
      if (is_in_row[index])
      {
        return false;
      }
      else
      {
        is_in_row[index] = true;
      }
    }
    it++;
  }
  return true;
}
