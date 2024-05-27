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

}

Card Game::drawRandomCard(){
	Card randCard;
	int randNum = rand() % dealerDeck.size();
	randCard = dealerDeck.at(randNum);
	dealerDeck.erase(dealerDeck.begin() + randNum);
	return randCard;
}

std::string Game::handToString(bool isPlayer){
	std::string output = "";
	if(isPlayer){
		for(auto card : playerHand.handCards){
			output += card.name + "\n";
		}
	}else{
		if(dealerHand.handCards.size() > 2){
			for(auto card : dealerHand.handCards){
				output += card.name + "\n";
			}
		}else{
			output += dealerHand.handCards.at(0).name + "\n";
		}
	}
	return output;
}

std::string Game::totalToString(bool isPlayer){
	std::string output;
	if(isPlayer){
		output = "Your total: " + std::to_string(playerHand.totalValue);
		if(playerHand.aceWeighted){
			output += "/" + std::to_string(playerHand.totalValue + 10);
		}
	}else{
		if(dealerHand.handCards.size() == 2){
			output = "Dealer's total: " + std::to_string(dealerHand.handCards.at(0).value);
		}else{
			output =  "Dealer's total: " + std::to_string(dealerHand.totalValue);
		}

		if(dealerHand.handCards.at(0).value == 1 || (dealerHand.handCards.size() > 2 && dealerHand.aceWeighted)){
			output += "/" + std::to_string(dealerHand.totalValue + 10);
		}
	}
	return output + "\n";
}

//hit

//stand

//double

//split

//surrender