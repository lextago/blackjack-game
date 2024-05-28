#include "player.h"

Player::Player(size_t walletAmt){
    this->walletAmt = walletAmt;
}   

void Player::clear(){
    currBet = 0;
    playerHand.cards.clear();
    playerHand.totalValue = 0;
    playerHand.aceWeighted = false;
    playerHand.isBlackjack = false;
    playerHand.isBust = false;
}

std::string Player::handToString(){
    std::string output = "Your hand:\n";
    for(auto card : playerHand.cards){
        output += card.name + "\n";
    }
    return output;
}

std::string Player::totalToString(){
    std::string output = "Your total: ";
    output += std::to_string(playerHand.totalValue);
    if(playerHand.aceWeighted){
        output += "/" + std::to_string(playerHand.totalValue + 10);
    }
    return output + "\n";
}

void Player::addCard(Card newCard){
    playerHand.cards.push_back(newCard);
    playerHand.totalValue += newCard.value;
    playerHand.aceWeighted = (newCard.value == 11);
    playerHand.isBlackjack = (playerHand.totalValue == 21);
    playerHand.isBust = (playerHand.totalValue > 21);
}

void Player::bet(){
    std::cout << "Current Cash: " << walletAmt << "\n";
	std::cout << "How much would you like to bet? (5, 10, 100, 250, 500, 1000)\n";
    std::vector<size_t> validBets = {5,10,100,250,500,1000};
    size_t inputBet;
	std::cin >> inputBet;

    while(find(validBets.begin(), validBets.end(), inputBet) == validBets.end()){
        std::cout << "Choose one of the avaiable options.\n";
        std::cin >> inputBet;
	}
    while(inputBet > walletAmt){
        std::cout << "Insufficient cash in wallet.\n";
        std:: cin >> inputBet;
    }

    walletAmt -= inputBet;
    currBet = inputBet;
}

void Player::hit(){
    
}
