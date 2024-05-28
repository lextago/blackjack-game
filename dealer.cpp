#include "dealer.h"

Dealer::Dealer(size_t numDecks){
    this->numDecks = numDecks;
}

void Dealer::clear(){
    dealerHand.cards.clear();
    dealerHand.totalValue = 0;
    dealerHand.aceWeighted = false;
    dealerHand.isBlackjack = false;
    dealerHand.isBust = false;
}

std::string Dealer::handToString(){
    std::string output = "Dealer's hand:\n";
    if(dealerHand.cards.size() == 2){
        output += dealerHand.cards.at(0).name + "\n";
    }else{
        for(auto card : dealerHand.cards){
            output += card.name + "\n";
        }
    }
    return output;
}

std::string Dealer::totalToString(){
    std::string output = "Dealer's total: ";

    if(dealerHand.cards.size() == 2){
        output += std::to_string(dealerHand.cards.at(0).value);
        if(dealerHand.cards.at(0).value == 1){
            output += "/11";
        }
    }else{
        output += std::to_string(dealerHand.totalValue);
        if(dealerHand.aceWeighted){
            output += "/" + std::to_string(dealerHand.totalValue + 10);
        }
    }
    return output + "\n";
}

bool Dealer::readDeck(std::string filename){
    for(size_t i = 0; i < numDecks; i++){
        std::ifstream ifile(filename);
		if(!ifile.is_open()){
			std::cout << "Invalid filename.\n";
			return false;
		}

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
	return true;
}

Card Dealer::drawRandomCard(){
	Card randCard;
	int randNum = rand() % dealerDeck.size();
	randCard = dealerDeck.at(randNum);
	dealerDeck.erase(dealerDeck.begin() + randNum);
	return randCard;
}

void Dealer::dealCards(Player &user){
	for(size_t i = 0; i < 2; i++){
		Card newCard = drawRandomCard();
        addCard(newCard);
        newCard = drawRandomCard();
        user.addCard(newCard);
    }
}

void Dealer::addCard(Card newCard){
    dealerHand.cards.push_back(newCard);
    dealerHand.totalValue += newCard.value;
    dealerHand.aceWeighted = (newCard.value == 11);
    dealerHand.isBlackjack = (dealerHand.totalValue == 21);
    dealerHand.isBust = (dealerHand.totalValue > 21);
}

size_t Dealer::getNumCards(){
    return dealerDeck.size();
}