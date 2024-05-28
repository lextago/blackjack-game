#include <iostream>
#include <assert.h>
#include <time.h>

#include "game.h"
#include "player.h"
#include "dealer.h"

int main(int argc, char* argv[]){ //6 to 8 decks is standard for blackjack
    srand(time(0));

    std::cout << "Welnpce to Blackjack!\n";
    std::cout << "Dealer hits on 17. 3 to 2 payout for blackjacks.\n";
    std::cout << "Press ENTER to begin playing.\n";

    std::string strInput;
    int numInput;
    getline(std::cin, strInput);

    Player user(1000);
    Dealer npc(6);

    npc.readDeck("cards.txt");
    user.clear();
    npc.clear();

    user.bet();

    std::cout << "\nBlackjack is now in session.\n\n";

    npc.dealCards(user);

	std::cout << npc.handToString() << "The second card is face down.\n";
	std::cout << npc.totalToString() << "\n";

	std::cout << user.handToString();
	std::cout << user.totalToString() << "\n";

    return 0;
}