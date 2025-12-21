#include "constants.hpp"
#include "board.hpp"
#include <terminal_ctrl.hpp>
#include <iostream>
#include <cstdlib>
#include <vector>

void place_symbol(std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE>& board, char symbol) {
    int row {};
    int col {};
    bool valid_input {false};

    do {
        std::cout << "Entrez le numéro de la ligne à laquelle vous voulez placer (1 à 3 de haut en bas) : ";
        std::cin >> row;
        
        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Entrée invalide" << std::endl << std::endl;
            continue;
        }

        std::cout << "Entrez le numéro de la colonne à laquelle vous voulez placer (1 à 3 de gauche à droite) : ";
        std::cin >> col;

        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Entrée invalide" << std::endl << std::endl;
            continue;
        }

        if(row < 1 || row > BOARD_SIZE || col < 1 || col > BOARD_SIZE) {
            std::cout << "Case invalide" << std::endl << std::endl;
            continue;
        }

        if(board[row-1][col-1] != DEFAULT_CHAR) {
            std::cout << "La case est déjà prise, entrez en une autre" << std::endl << std::endl;
            continue;
        }

        valid_input = true;
    } while(!valid_input);

    board[row-1][col-1] = symbol;
}

void place_symbol_robot(std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE>& board, char symbol) {
    std::cout << "En train de jouer..." << std::endl;
    terminal_ctrl::sleep(2000);

    std::vector<std::pair<int, int>> free_cells {};

    for(size_t i=0; i<board.size(); i++) {
        for(size_t j=0; j<board.size(); j++) {
            if(board[i][j] == DEFAULT_CHAR) {
                board[i][j] = symbol;
                if(is_won(board)) {
                    return;
                }
                board[i][j] = DEFAULT_CHAR;
            }
        }
    }

    for(size_t i=0; i<board.size(); i++) {
        for(size_t j=0; j<board.size(); j++) {
            if(board[i][j] == DEFAULT_CHAR) {
                if(symbol == 'X') {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
                if(is_won(board)) {
                    board[i][j] = symbol;
                    return;
                }
                board[i][j] = DEFAULT_CHAR;
                free_cells.push_back({i, j});
            }
        }
    }

    int index = std::rand() % free_cells.size();
    int row = free_cells[index].first;
    int col = free_cells[index].second;

    board[row][col] = symbol;
}