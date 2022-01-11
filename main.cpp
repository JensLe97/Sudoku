#include <iostream>
#include "sudoku.h"

void printBoard(const std::vector<std::vector<char>> &board) 
{
    for (size_t row = 0; row < 9; row++) 
    {
        for (size_t col = 0; col < 9; col++)
        {
            if(col == 3 || col == 6)
                std::cout << "| ";
            std::cout << board.at(row).at(col) << " ";
        }
        std::cout << std::endl; 
        if(row == 2 || row == 5) 
            std::cout << "---------------------" << std::endl;
    }
}

/**
 * Converts an array of char to a 2D vector (vector of vector of char)
 *
 * @param arrayBoard The reference to the flat array containing 81 values
 * @return A new board as a vector of vectors
 */
std::vector<std::vector<char>> arrayTo2DVec(const std::array<char, 81> &arrayBoard)
{
    std::vector<std::vector<char>> board;
    board.reserve(9);

    // All cells in the Sudoku board are pushed into the vector by extracting each row
    for (std::size_t row = 0; row < 9; row++) 
    {
        std::vector<char> currentRow;
        currentRow.reserve(9);
        for (std::size_t col = 0; col < 9; col++) 
        {
            currentRow.push_back(arrayBoard[row * 9 + col]);
        }
        board.push_back(currentRow);
    }
    return board;
}

int main(int, char**) 
{
    std::cout << "======== Sudoku Generator ========" << std::endl;
    std::array<char, 81> const arrayBoardToSolve = {    '5', '3', '.', '.', '7', '.', '.', '.', '.', 
                                                        '6', '.', '.', '1', '9', '5', '.', '.', '.', 
                                                        '.', '9', '8', '.', '.', '.', '.', '6', '.', 
                                                        '8', '.', '.', '.', '6', '.', '.', '.', '3', 
                                                        '4', '.', '.', '8', '.', '3', '.', '.', '1', 
                                                        '7', '.', '.', '.', '2', '.', '.', '.', '6', 
                                                        '.', '6', '.', '.', '.', '.', '2', '8', '.', 
                                                        '.', '.', '.', '4', '1', '9', '.', '.', '5', 
                                                        '.', '.', '.', '.', '8', '.', '.', '7', '9' };

    std::array<char, 81> const arrayBoardSolution = {   '5', '3', '4', '6', '7', '8', '9', '1', '2', 
                                                        '6', '7', '2', '1', '9', '5', '3', '4', '8', 
                                                        '1', '9', '8', '3', '4', '2', '5', '6', '7', 
                                                        '8', '5', '9', '7', '6', '1', '4', '2', '3', 
                                                        '4', '2', '6', '8', '5', '3', '7', '9', '1', 
                                                        '7', '1', '3', '9', '2', '4', '8', '5', '6', 
                                                        '9', '6', '1', '5', '3', '7', '2', '8', '4', 
                                                        '2', '8', '7', '4', '1', '9', '6', '3', '5', 
                                                        '3', '4', '5', '2', '8', '6', '1', '7', '9'};
    std::vector<std::vector<char>> board = arrayTo2DVec(arrayBoardToSolve);
    std::vector<std::vector<char>> const expected = arrayTo2DVec(arrayBoardSolution);

    std::cout << "======== Sudoku Solver ========" << std::endl;

    std::cout << "Board to solve: " << std::endl;
    printBoard(board);
    std::cout << std::endl;
    std::cout << "Expected solution: " << std::endl;
    printBoard(expected);
    std::cout << std::endl;

    Sudoku sudoku;
    
    if (sudoku.solve(board))
    {
        std::cout << "Own solution: " << std::endl;
        printBoard(board);
    }
    else
    {
        std::cout << "Could not solve the Sudoku!" << std::endl;
    }
    
    return 0;
}
