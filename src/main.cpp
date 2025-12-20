#include "player.hpp"
#include "board.hpp"
#include "constants.hpp"
#include "actions.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <terminal_ctrl.hpp>

int main()
{
    terminal_ctrl::clear_screen();
    std::cout << "Bienvenue dans le jeu du TicTacToe" << std::endl << std::endl;
    while(true) {   
        int game_mode {};
    
        do {
            std::cout << "Veuillez choisir un mode de jeu :" << std::endl;
            std::cout << "1. Deux joueurs" << std::endl;
            std::cout << "2. Un joueur contre l'IA" << std::endl;
            std::cout << "3. Quitter le programme" << std::endl;
            std::cin >> game_mode;
    
            if(std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
    
            if(game_mode == 3) {
                return 0;
            }
    
            if(game_mode != 1 && game_mode != 2) {
                std::cout << "Invalide" << std::endl;
            }
        } while(game_mode != 1 && game_mode != 2);
        terminal_ctrl::clear_screen();
    
        std::cout << std::endl;
    
        Player player1;
        Player player2;
    
        if(game_mode == 1) {
            std::cout << "Joueur 1 :" << std::endl;
            player1 = create_player();
    
            terminal_ctrl::clear_screen();
            std::cout << "Joueur 2 :" << std::endl;
            
            if(player1.symbol == 'X') {
                player2 = create_player('O');
            } else {
                player2 = create_player('X');
            }
        } else {
            std::srand(std::time(nullptr));
            player1 = create_player();
            if(player1.symbol == 'X') {
                player2 = create_player("IA", 'O');
            } else {
                player2 = create_player("IA", 'X');
            }
        }
    
        std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE> board {};
        
        for (size_t i = 0; i < board.size(); i++) {
            for (size_t j = 0; j < board.size(); j++) {
                board[i][j] = DEFAULT_CHAR;
            }
        }
        terminal_ctrl::clear_screen();
    
        draw_game_board(board);
    
        Player *playing = &player2;
    
        while(!is_won(board) && !is_board_full(board)) {
            std::cout << std::endl;
    
            if(playing == &player1) {
                playing = &player2;
            } else {
                playing = &player1;
            }
    
            std::cout << "Tour de " << playing->name << std::endl << std::endl;
            
            if(game_mode == 2 && playing == &player2) {
                place_symbol_robot(board, playing->symbol);
            } else {
                place_symbol(board, playing->symbol);
            }
    
            terminal_ctrl::clear_screen();
            draw_game_board(board);
        }
    
        std::cout << std::endl;
    
        if(is_board_full(board) && !is_won(board)) {
            std::cout << "Match nul ! Personne n'a gagné." << std::endl;
        } else {
            std::cout << "Gagnant : " << playing->name << std::endl;
        }

        terminal_ctrl::sleep(4000);
        terminal_ctrl::clear_screen();
    }
}