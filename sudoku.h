#pragma once

#include <vector>
#include <array>
#include <bitset>

class Sudoku {
public:
    Sudoku();

    // Rule of Five
    ~Sudoku();
    Sudoku (const Sudoku&) = delete; // copy constructor
    Sudoku& operator = (const Sudoku&) = delete; // copy assignment
    Sudoku (const Sudoku&&) = delete; // move constructor
    Sudoku& operator = (Sudoku&&) = delete; // move assignment

    bool solve(std::vector<std::vector<char>> &board) const noexcept; 

private:
    static constexpr std::pair<std::size_t, std::size_t> nextEmptyCell(
        std::vector<std::vector<char>> &board, 
        std::size_t row, 
        std::size_t col) noexcept;

    static bool solveStep(
            std::vector<std::vector<char>> &board, 
            std::size_t const currentRow, 
            std::size_t const currentCol,
            std::array<std::bitset<9>, 9> &rowContains,
            std::array<std::bitset<9>, 9> &colContains,
            std::array<std::bitset<9>, 9> &boxContains) noexcept;

    constexpr std::size_t getBox(std::size_t row, std::size_t col) noexcept;

    constexpr std::size_t getNextRow(std::size_t row, std::size_t col) noexcept;

    constexpr std::size_t getNextCol(std::size_t col) noexcept;
};