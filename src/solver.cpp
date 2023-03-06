#include "solver.h"
#include "validator.h"


std::pair<bool, Board> Solver::solve(Board board)
{
  if (!Validator::isBoardValid(board))
  {
    return std::make_pair(false, board);
  }
  Cell* cell = board.getNextEmptyCell();
  if (cell == nullptr)
  {
    return std::make_pair(true, board);
  }
  else
  {
    for (uint8_t i = 1; i < BOARD_LENGTH + 1; ++i)
    {
      *cell = i;
      auto [solved, new_board] = solve(board);
      if (solved)
      {
        return std::make_pair(solved, new_board);
      }
    }
    return std::make_pair(false, board);
  }
}
