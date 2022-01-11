#include <gtest/gtest.h>
#include "../sudoku.h"

TEST(SudokuTest, SolutionFound)
{
  std::vector<std::vector<char>> board;

  Sudoku sudoku;
  EXPECT_TRUE(sudoku.solve(board));
}

TEST(SudokuTest, SolutionMatches)
{
  std::vector<std::vector<char>> board;
  std::vector<std::vector<char>> expected;

  Sudoku sudoku;
  sudoku.solve(board);

  EXPECT_TRUE(board == expected);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}