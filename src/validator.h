#pragma once

#include "cell.h"
#include "board.h"
#include "board_iterators.h"

struct Validator
{
  static bool isValid(Iterator& it);
};
