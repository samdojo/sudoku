#include "solver.h"
#include "validator.h"


bool Solver::solve(Board& board)
{
  if (!Validator::isBoardValid(board))
  {
    return false;
  }
  Cell* cell = board.getNextEmptyCell();
  if (cell == nullptr) [[unlikely]]
  {
    return true;
  }
  else
  {
    for (uint8_t i = 1; i < BOARD_LENGTH + 1; ++i)
    {
      *cell = i;
      bool solved = solve(board);
      if (solved) [[unlikely]]
      {
        return true;
      }
    }
    board.eraseCell(cell);
    return false;
  }
}
