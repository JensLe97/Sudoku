#include "sudoku.h"

constexpr std::size_t getBox(std::size_t row, std::size_t col) noexcept
{
    return (row / 3) * 3 + col / 3;
}

constexpr std::size_t getNextRow(std::size_t row, std::size_t col) noexcept
{
    return row + (col + 1) / 9;
}

constexpr std::size_t getNextCol(std::size_t col) noexcept
{
    return (col + 1) % 9;
}

Sudoku::Sudoku() 
{
    rowContains = new std::bitset<9>[9]{0, 0, 0, 0, 0, 0, 0, 0, 0};
    colContains = new std::bitset<9>[9]{0, 0, 0, 0, 0, 0, 0, 0, 0};
    boxContains = new std::bitset<9>[9]{0, 0, 0, 0, 0, 0, 0, 0, 0};
}

Sudoku::~Sudoku() 
{
    delete[] rowContains;
    delete[] colContains;
    delete[] boxContains;
}

bool Sudoku::solve(std::vector<std::vector<char>> &board) const noexcept 
{
    // Set all given numbers from the board into the row, col and box contains arrays
    for (size_t row = 0; row < 9; row++)
    {
        for (size_t col = 0; col < 9; col++)
        {
            char number;
            // Cell contains a number -> Mark in the "contains"-Arrays
            if ((number = board.at(row).at(col)) != '.')
            {
                size_t index = number - '1';
                size_t box = getBox(row, col);
                rowContains[row].set(index);
                colContains[col].set(index);
                boxContains[box].set(index);
            }
        }
    }
    
    return solveRecursively(board, 0, 0);
}

constexpr std::pair<std::size_t, std::size_t> Sudoku::nextEmptyCell(
    std::vector<std::vector<char>> &board, 
    std::size_t row, 
    std::size_t col) const noexcept
{   
    while (row != 9)
    {
        // Empty cell
        if (board.at(row).at(col) == '.')
        {
            return {row, col};
        }
        row = getNextRow(row, col);
        col = getNextCol(col);
    }
    
    return {9, 0};
}

bool Sudoku::solveRecursively(
        std::vector<std::vector<char>> &board, 
        std::size_t const currentRow, 
        std::size_t const currentCol) const noexcept
{
    auto [row, col] = nextEmptyCell(board, currentRow, currentCol);

    // All cells are filled
    if (row == 9)
    {
        return true;
    }

    size_t const box = getBox(row, col);
    // All numbers that are present in the current row, column and box
    std::bitset<9> const containsNumbers = rowContains[row] | colContains[col] | boxContains[box];
    if (containsNumbers.all())
    {
        return false;
    }

    // Try all numbers from 1 to 9
    for (size_t index = 0; index < 9; index++)
    {
        // Start Backtracking if the number is not present yet
        if (!containsNumbers[index])
        {
            // Mark the cell with this number
            board.at(row).at(col) = static_cast<char>(index + '1');
            rowContains[row].set(index);
            colContains[col].set(index);
            boxContains[box].set(index);

            // Call the function recursively so it solves the Sudoku with one empty cell less
            if (solveRecursively(board, row, col))
            {   
                // Solution found for the board
                return true;
            } 
            else
            {   
                // Undo the marking 
                rowContains[row].reset(index);
                colContains[col].reset(index);
                boxContains[box].reset(index);
            }
        }
    }

    // None of the tries as lead to a solution
    // Reset the cell and proceed at an early stage
    board.at(row).at(col) = '.';
    return false;
}