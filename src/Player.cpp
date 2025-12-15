#include "Player.hpp"
#include <iostream>

Player create_player() {
    Player player {};

    std::cout << "Entrez votre nom : ";
    std::cin >> player.name;

    do {
        std::cout << "Entrez votre symbole (X ou O) : ";
        std::cin >> player.symbol;

        if(player.symbol != 'O' && player.symbol != 'X') {
            std::cout << "Invalide" << std::endl;
        }
    } while (player.symbol != 'O' && player.symbol != 'X');

    return player;
}

Player create_player(char symbol) {
    Player player {};

    std::cout << "Entrez votre nom : ";
    std::cin >> player.name;

    player.symbol = symbol;

    return player;
}

Player create_player(std::string name, char symbol) {
    Player player {name, symbol};
    return player;
}