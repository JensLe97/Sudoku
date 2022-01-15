#include "util.h"

void printBoard(const std::vector<std::vector<char>> &board) 
{
    for (size_t row = 0; row < 9; row++) 
    {
        for (size_t col = 0; col < 9; col++)
        {
            if (col == 3 || col == 6)
                std::cout << "| ";
            std::cout << board.at(row).at(col) << " ";
        }
        std::cout << std::endl; 
        if (row == 2 || row == 5) 
            std::cout << "---------------------" << std::endl;
    }
}

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