#include <gtest/gtest.h>

#include "board_iterators.h"
#include "validator.h"
#include "cell.h"

namespace {
  struct TestIt : public Iterator
  {
    TestIt(std::array<uint8_t, BOARD_LENGTH> seq)
      : Iterator(nullptr)
      , seq(seq)
    {
      cell = &realCell;
      *cell = seq[i];
    }
    void operator++(int) override
    {
      *cell = seq[++i];
    }
    Cell realCell;
    int i = 0;
    std::array<uint8_t, BOARD_LENGTH> seq;
  };
}

TEST(Validator, Empty)
{
  TestIt it({0, 0, 0, 0, 0, 0, 0, 0, 0});

  EXPECT_TRUE(Validator::isValid(it));
}

TEST(Validator, Simple)
{
  TestIt it({1, 2, 3, 4, 5, 6, 7, 8, 9});

  EXPECT_TRUE(Validator::isValid(it));
}

TEST(Validator, FullValid)
{
  TestIt it({7, 2, 8, 1, 6, 3, 5, 4, 9});

  EXPECT_TRUE(Validator::isValid(it));
}

TEST(Validator, HalfFullValid)
{
  TestIt it({9, 2, 0, 4, 6, 0, 5, 0, 0});

  EXPECT_TRUE(Validator::isValid(it));
}

TEST(Validator, FullInvalid)
{
  TestIt it({7, 2, 8, 1, 6, 3, 5, 4, 1});

  EXPECT_FALSE(Validator::isValid(it));
}

TEST(Validator, HalfFullInvalid)
{
  TestIt it({5, 2, 0, 4, 6, 0, 5, 0, 0});

  EXPECT_FALSE(Validator::isValid(it));
}
