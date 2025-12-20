#pragma once
#include "constants.hpp"
#include <array>

void place_symbol(std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE>& board, char symbol);
void place_symbol_robot(std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE>& board, char symbol);
