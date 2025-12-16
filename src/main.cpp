#include "Player.hpp"
#include <iostream>
#include <array>

char const DEFAULT_CHAR {'.'};
int const BOARD_SIZE {3};

void draw_game_board(std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE>& board) {
    for(size_t i=0; i<board.size(); i++) {
        std::cout << "| ";
        for(size_t j=0; j<board[i].size(); j++) {
            std::cout << board[i][j] << " | ";
        }
        std::cout << std::endl;
    }
}

bool is_row_complete(std::array<char, BOARD_SIZE> row) {
    for(size_t i = 1; i<row.size(); i++) {
        if(row[i] != row[i-1] || row[i] == '.') {
            return false;
        }
    }
    return true;
}

bool is_col_complete(std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE>& board, int col) {
    for(size_t i=1; i<board.size(); i++) {
        if(board[i-1][col] != board[i][col] || board[i][col] == '.') {
            return false;
        }
    }
    return true;
}

bool is_diagonal_complete(std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE>& board) {
    bool main_diag = true;
    for(size_t i=1; i<board.size(); i++) {
        if(board[i-1][i-1] != board[i][i] || board[i][i] == '.') {
            main_diag = false;
            break;
        }
    }
    if(main_diag) return true;

    bool anti_diag = true;
    for(size_t i=1; i<board.size(); i++) {
        if(board[i-1][board.size()-i] != board[i][board.size()-i-1] || board[i][board.size()-i-1] == '.') {
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

bool is_finish(std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE>& board) {
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
    
    if(is_board_full(board)) {
        return true;
    }
    
    return false;
}

void place_symbol(std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE>& board, char symbol) {
    int row {};
    int col {};

    do {
        std::cout << "Entrez le numéro de la ligne à laquelle vous voulez placer : ";
        std::cin >> row;
        std::cout << "Entrez le numéro de la colonne à laquelle vous voulez placer : ";
        std::cin >> col;

        if(board[row-1][col-1] != DEFAULT_CHAR) {
            std::cout << "La case est déjà prise, entrez en une autre" << std::endl << std::endl;
        }
    } while(board[row-1][col-1] != DEFAULT_CHAR);

    board[row-1][col-1] = symbol;
}

int main()
{
    std::cout << "Bienvenue dans le jeu du TicTacToe" << std::endl;

    int game_mode {};

    do {
        std::cout << std::endl << "Veuillez choisir un mode de jeu :" << std::endl;
        std::cout << "1. Deux joueurs" << std::endl;
        std::cout << "2. Un joueur contre l'IA" << std::endl;
        std::cin >> game_mode;

        if(game_mode != 1 && game_mode != 2) {
            std::cout << "Invalide" << std::endl;
        }
    } while(game_mode != 1 && game_mode != 2);

    std::cout << std::endl;

    Player player1;
    Player player2;

    if(game_mode == 1) {
        std::cout << std::endl << "Joueur 1 :" << std::endl;
        player1 = create_player();

        std::cout << std::endl << "Joueur 2 :" << std::endl;
        
        if(player1.symbol == 'X') {
            player2 = create_player('O');
        } else {
            player2 = create_player('X');
        }
    } else {
        Player player1 = create_player();
        Player player2;
        if(player1.symbol == 'X') {
            player2 = create_player("IA", 'O');
        } else {
            player2 = create_player("IA", 'X');
        }
    }

    std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE> board = {{{DEFAULT_CHAR, DEFAULT_CHAR, DEFAULT_CHAR}, {DEFAULT_CHAR, DEFAULT_CHAR, DEFAULT_CHAR}, {DEFAULT_CHAR, DEFAULT_CHAR, DEFAULT_CHAR}}};
    draw_game_board(board);

    Player *playing = &player2;

    while(!is_finish(board)) {
        std::cout << std::endl;

        if(playing == &player1) {
            playing = &player2;
        } else {
            playing = &player1;
        }

        std::cout << "Tour de " << playing->name << std::endl;
        place_symbol(board, playing->symbol);

        draw_game_board(board);
    }

    std::cout << std::endl;

    if(is_board_full(board) && !is_row_complete(board[0]) && !is_row_complete(board[1]) && !is_row_complete(board[2]) 
       && !is_col_complete(board, 0) && !is_col_complete(board, 1) && !is_col_complete(board, 2) 
       && !is_diagonal_complete(board)) {
        std::cout << "Match nul ! Personne n'a gagné." << std::endl;
    } else {
        std::cout << "Gagnant : " << playing->name << std::endl;
    }
    
    return 0;
}