#include <gtest/gtest.h>
#include "../sudoku.h"

TEST(SudokuTest, Solve)
{
  Sudoku sudoku;
  EXPECT_EQ(true, sudoku.solve());
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}