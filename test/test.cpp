#include <gtest/gtest.h>
#include "../sudoku.h"
#include "../util.h"

class SudokuTest : public testing::Test {
protected:
    std::array<char, 81> const arrayBoard1 = {      '5', '3', '.', '.', '7', '.', '.', '.', '.', 
                                                    '6', '.', '.', '1', '9', '5', '.', '.', '.', 
                                                    '.', '9', '8', '.', '.', '.', '.', '6', '.', 
                                                    '8', '.', '.', '.', '6', '.', '.', '.', '3', 
                                                    '4', '.', '.', '8', '.', '3', '.', '.', '1', 
                                                    '7', '.', '.', '.', '2', '.', '.', '.', '6', 
                                                    '.', '6', '.', '.', '.', '.', '2', '8', '.', 
                                                    '.', '.', '.', '4', '1', '9', '.', '.', '5', 
                                                    '.', '.', '.', '.', '8', '.', '.', '7', '9' };

    std::array<char, 81> const arrayExpected1 = {   '5', '3', '4', '6', '7', '8', '9', '1', '2', 
                                                    '6', '7', '2', '1', '9', '5', '3', '4', '8', 
                                                    '1', '9', '8', '3', '4', '2', '5', '6', '7', 
                                                    '8', '5', '9', '7', '6', '1', '4', '2', '3', 
                                                    '4', '2', '6', '8', '5', '3', '7', '9', '1', 
                                                    '7', '1', '3', '9', '2', '4', '8', '5', '6', 
                                                    '9', '6', '1', '5', '3', '7', '2', '8', '4', 
                                                    '2', '8', '7', '4', '1', '9', '6', '3', '5', 
                                                    '3', '4', '5', '2', '8', '6', '1', '7', '9'};

    std::array<char, 81> const arrayBoard2 = {      '.', '.', '.', '.', '.', '.', '.', '.', '3', 
                                                    '.', '.', '5', '4', '.', '.', '2', '.', '.',
                                                    '4', '7', '.', '.', '3', '.', '.', '8', '.',
                                                    '.', '.', '.', '9', '8', '.', '.', '.', '.',
                                                    '7', '4', '9', '5', '.', '.', '.', '.', '.',
                                                    '8', '.', '1', '.', '.', '.', '5', '7', '.',
                                                    '1', '.', '.', '3', '5', '6', '.', '.', '.',
                                                    '6', '.', '.', '2', '.', '.', '.', '1', '.', 
                                                    '.', '.', '.', '.', '1', '.', '.', '.', '.' };

    std::array<char, 81> const arrayExpected2 = {   '2', '9', '8', '7', '6', '5', '1', '4', '3', 
                                                    '3', '1', '5', '4', '9', '8', '2', '6', '7',
                                                    '4', '7', '6', '1', '3', '2', '9', '8', '5',
                                                    '5', '6', '3', '9', '8', '7', '4', '2', '1',
                                                    '7', '4', '9', '5', '2', '1', '8', '3', '6',
                                                    '8', '2', '1', '6', '4', '3', '5', '7', '9',
                                                    '1', '8', '2', '3', '5', '6', '7', '9', '4',
                                                    '6', '5', '4', '2', '7', '9', '3', '1', '8', 
                                                    '9', '3', '7', '8', '1', '4', '6', '5', '2' };

	std::array<char, 81> const arrayBoardToSolve;
	std::array<char, 81> const arrayBoardSolution;
	std::vector<std::vector<char>> board;
	std::vector<std::vector<char>> expected;
	Sudoku sudoku;

	SudokuTest() 
		: arrayBoardToSolve(arrayBoard1), 
          arrayBoardSolution(arrayExpected1), 
          expected(arrayTo2DVec(arrayBoardSolution))
	{
		board = arrayTo2DVec(arrayBoardToSolve);		
	}
};

TEST_F(SudokuTest, Board1SolutionFound)
{
	EXPECT_TRUE(sudoku.solve(board));
}

TEST_F(SudokuTest, Board1SolutionMatches)
{
	sudoku.solve(board);
	EXPECT_TRUE(board == expected);
}

TEST_F(SudokuTest, Board2SolutionFound)
{
    board = arrayTo2DVec(arrayBoard2);
	EXPECT_TRUE(sudoku.solve(board));
}

TEST_F(SudokuTest, Board2SoltionMatches)
{
    board = arrayTo2DVec(arrayBoard2);
    expected = arrayTo2DVec(arrayExpected2);
    sudoku.solve(board);
	EXPECT_TRUE(board == expected);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}