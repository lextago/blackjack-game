#include "game.h"

#include <algorithm>
#include <fstream>
#include <sstream>
#include <assert.h>

Game::Game(size_t playerWallet, size_t numDecks){
	this->playerWallet = playerWallet;
	this->numDecks = numDecks;
	for(size_t i = 0; i < numDecks; i++){
        std::ifstream ifile("cards.txt");
        std::string line;
        while(getline(ifile, line)){
            std::istringstream iss(line);
            Card newCard;

            getline(iss, newCard.name, ',');
            iss >> newCard.value;

            dealerDeck.push_back(newCard);
        }
        ifile.close();
    }
}

bool Game::walletEmpty(){
	return (playerWallet >= 0);
}

void Game::clearTable(){
	currBet = 0;
	playerHand.handCards.clear();
	playerHand.totalValue = 0;
	playerHand.aceWeighted = false;

	dealerHand.handCards.clear();
	dealerHand.totalValue = 0;
	dealerHand.aceWeighted = false;
}

void Game::playerBet(){
	std::cout << "Current Cash: " << playerWallet << "\n";
	std::cout << "How much would you like to bet? (5, 10, 100, 250, 500, 1000)\n";
	std::vector<size_t> validBets = {5,10,100,250,500,1000};
	size_t inputBet;
	std::cin >> inputBet;
	while(find(validBets.begin(), validBets.end(), inputBet) == validBets.end()){
			std::cout << "Invalid bet.\n";
			std::cin >> inputBet;
	}

	currBet = inputBet;
	playerWallet = playerWallet - currBet;
}

void Game::dealCards(){
	for(size_t i = 0; i < 2; i++){
		Card newCard = drawRandomCard();
		dealerHand.handCards.push_back(newCard);
		dealerHand.totalValue += newCard.value;
		if(newCard.value == 11){
			dealerHand.aceWeighted = true;
		}

		newCard = drawRandomCard();
		playerHand.handCards.push_back(newCard);
		playerHand.totalValue += newCard.value;
		if(newCard.value == 11){
			playerHand.aceWeighted = true;
		}
	}

	std::cout << "The dealer's first card is: \n" << dealerHand.handCards.at(0).name << "\nThe second card is face down.\n";
	if(dealerHand.handCards.at(0).name.find("Ace") != std::string::npos){
		std::cout << "Dealer's total: 1/11\n\n";
	}else{
		std::cout << "Dealer's total: " << dealerHand.handCards.at(0).value << "\n\n";
	}

	std::cout << "Your cards: \n" << handToString();
	if(playerHand.aceWeighted){
		std::cout << "Your total: " << playerHand.totalValue - 10 << "/" << playerHand.totalValue << "\n";
	}else{
		std::cout << "Your total: " << playerHand.totalValue << "\n";
	}
}

Card Game::drawRandomCard(){
	Card randCard;
	int randNum = rand() % dealerDeck.size();
	randCard = dealerDeck.at(randNum);
	dealerDeck.erase(dealerDeck.begin() + randNum);
	return randCard;
}

std::string Game::handToString(){
	std::string output = "";
	for(auto card : playerHand.handCards){
		output += card.name + "\n";
	}
	return output;
}

//hit

//stand

//double

//split

//surrender