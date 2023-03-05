#pragma once

#include "cell.h"
#include "board.h"
#include "board_iterators.h"

struct Validator
{
  static bool isGroupValid(Iterator& it);
  static bool isBoardValid(Board& board);
};
