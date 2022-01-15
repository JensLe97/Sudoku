#pragma once

#include <vector>
#include <array>
#include <iostream>

/**
 * @brief Prints the Sudoku board on the command line in a formatted way
 * 
 * @param board The 2D values as char vectors
 */
void printBoard(const std::vector<std::vector<char>> &board);

/**
 * @brief Converts an array of char to a 2D vector (vector of vector of char)
 * 
 * @param arrayBoard The reference to the flat array containing 81 values
 * @return std::vector<std::vector<char>> A new board as a vector of vectors
 */
std::vector<std::vector<char>> arrayTo2DVec(const std::array<char, 81> &arrayBoard);