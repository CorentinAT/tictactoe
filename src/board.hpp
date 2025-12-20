#pragma once
#include "constants.hpp"
#include <array>
#include <iostream>

void draw_game_board(std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE>& board);
bool is_row_complete(std::array<char, BOARD_SIZE>& row);
bool is_col_complete(std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE>& board, int col);
bool is_diagonal_complete(std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE>& board);
bool is_board_full(std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE>& board);
bool is_won(std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE>& board);