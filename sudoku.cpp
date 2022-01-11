#include "sudoku.h"

Sudoku::Sudoku() 
{

}

Sudoku::~Sudoku() 
{
    
}

bool Sudoku::solve(std::vector<std::vector<char>> &board) const noexcept 
{
    return false;
}

constexpr std::pair<std::size_t, std::size_t> Sudoku::nextEmptyCell(
    std::vector<std::vector<char>> &board, 
    std::size_t row, 
    std::size_t col) noexcept
{
    return {9, 0};
}

bool Sudoku::solveStep(
        std::vector<std::vector<char>> &board, 
        std::size_t const currentRow, 
        std::size_t const currentCol,
        std::array<std::bitset<9>, 9> &rowContains,
        std::array<std::bitset<9>, 9> &colContains,
        std::array<std::bitset<9>, 9> &boxContains) noexcept
{
    return false;
}

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