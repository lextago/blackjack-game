#include <iostream>
#include <assert.h>
#include <time.h>

#include "game.h"

int main(int argc, char* argv[]){ //6 to 8 decks is standard for blackjack
    srand(time(0));

    std::cout << "Welcome to Blackjack!\n";
    std::cout << "Press ENTER to begin playing.\n";

    std::string temp;
    getline(std::cin, temp);

    Game myGame(1000, std::stoi(argv[1]));
    

    myGame.clearTable();
    myGame.playerBet();

    std::cout << "Blackjack is now in session.\n\n";

    myGame.dealCards();

    return 0;
}