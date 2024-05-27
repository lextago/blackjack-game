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

	std::cout << "The dealer's first card is: \n" << myGame.handToString(false) << "The second card is face down.\n";
	std::cout << myGame.totalToString(false) << "\n";

	std::cout << "Your cards: \n" << myGame.handToString(true);
	std::cout << myGame.totalToString(true) << "\n";

    return 0;
}