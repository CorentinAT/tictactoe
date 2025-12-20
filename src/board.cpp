#include "board.hpp"
#include "constants.hpp"

void draw_game_board(std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE>& board) {
    for(size_t i=0; i<board.size(); i++) {
        std::cout << "| ";
        for(size_t j=0; j<board[i].size(); j++) {
            std::cout << board[i][j] << " | ";
        }
        std::cout << std::endl;
    }
}

bool is_row_complete(std::array<char, BOARD_SIZE>& row) {
    for(size_t i = 1; i<row.size(); i++) {
        if(row[i] != row[i-1] || row[i] == DEFAULT_CHAR) {
            return false;
        }
    }
    return true;
}

bool is_col_complete(std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE>& board, int col) {
    for(size_t i=1; i<board.size(); i++) {
        if(board[i-1][col] != board[i][col] || board[i][col] == DEFAULT_CHAR) {
            return false;
        }
    }
    return true;
}

bool is_diagonal_complete(std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE>& board) {
    bool main_diag = true;
    for(size_t i=1; i<board.size(); i++) {
        if(board[i-1][i-1] != board[i][i] || board[i][i] == DEFAULT_CHAR) {
            main_diag = false;
            break;
        }
    }
    if(main_diag) return true;

    bool anti_diag = true;
    for(size_t i=1; i<board.size(); i++) {
        if(board[i-1][board.size()-i] != board[i][board.size()-i-1] || board[i][board.size()-i-1] == DEFAULT_CHAR) {
            anti_diag = false;
            break;
        }
    }
    return anti_diag;
}

bool is_board_full(std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE>& board) {
    for(size_t i=0; i<board.size(); i++) {
        for(size_t j=0; j<board[i].size(); j++) {
            if(board[i][j] == DEFAULT_CHAR) {
                return false;
            }
        }
    }
    return true;
}

bool is_won(std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE>& board) {
    for(size_t i=0; i<board.size(); i++) {
        if(is_row_complete(board[i])) {
            return true;
        }
    }
    
    for(size_t i=0; i<board.size(); i++) {
        if(is_col_complete(board, i)) {
            return true;
        }
    }
    
    if(is_diagonal_complete(board)) {
        return true;
    }
    
    return false;
}