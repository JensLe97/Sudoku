#pragma once

#include <vector>
#include <bitset>

/**
 * @brief Get the number of the box given a row and a column
 * 
 * @param row The row index (0 - 8)
 * @param col The column index (0 - 8)
 * @return constexpr std::size_t The number of the box (0 - 8)
 */
constexpr std::size_t getBox(std::size_t row, std::size_t col) noexcept;

/**
 * @brief Get the number of the next row given a row and a column
 * 
 * @param row The row index (0 - 8)
 * @param col The column index (0 - 8)
 * @return constexpr std::size_t The number of the next row
 */
constexpr std::size_t getNextRow(std::size_t row, std::size_t col) noexcept;

/**
 * @brief Get the number of the next column given a column
 * 
 * @param col The column index (0 - 8)
 * @return constexpr std::size_t The number of the next column
 */
constexpr std::size_t getNextCol(std::size_t col) noexcept;

class Sudoku {
private:
    // Dynamic arrays for practice:
    // For each row, column and box, the array contains a bitset
    // that stores the numbers currently present
    std::bitset<9>* rowContains;
    std::bitset<9>* colContains;
    std::bitset<9>* boxContains;

public:
    Sudoku();

    // Rule of Five
    virtual ~Sudoku();
    Sudoku (const Sudoku&) = delete; // copy constructor
    Sudoku& operator = (const Sudoku&) = delete; // copy assignment
    Sudoku (const Sudoku&&) = delete; // move constructor
    Sudoku& operator = (Sudoku&&) = delete; // move assignment

    /**
     * @brief Tries to find a solution for the given Sudoku board
     * 
     * @param board The Sudoku board to solve
     * @return true If a solution has been found
     * @return false If no solution could be found
     */
    bool solve(std::vector<std::vector<char>> &board) const noexcept; 

private:
    /**
     * @brief Return the position of the next empty cell starting from a given row and column
     * 
     * @param board The sudoku board
     * @param row The row start position
     * @param col The column start position
     * @return constexpr std::pair<std::size_t, std::size_t> The row, column in a pair
     */
    static constexpr std::pair<std::size_t, std::size_t> nextEmptyCell(
        std::vector<std::vector<char>> &board, 
        std::size_t row, 
        std::size_t col) noexcept;

    /**
     * @brief The actual logic of the backtracking algorithm
     * For the next empty cell all posible numbers are tried out
     * 
     * @param board The current board
     * @param currentRow The current row
     * @param currentCol The current column
     * @return true If no empty cells exist, so a solution is found
     * @return false No number fits in the next empty field
     */
    bool solveRecursively(
            std::vector<std::vector<char>> &board, 
            std::size_t const currentRow, 
            std::size_t const currentCol) const noexcept;
};