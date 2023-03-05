#pragma once
#include "board.h"

struct Solver
{
  static std::pair<bool, Board> solve(Board board);
};