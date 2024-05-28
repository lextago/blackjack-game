#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <assert.h>

#include "game.h"
#include "player.h"

class Dealer{
    private:
        Hand dealerHand;
        std::vector<Card> dealerDeck;
        size_t numDecks;
    public:
        Dealer(size_t numDecks);

        void clear();

        std::string handToString();

        std::string totalToString();

        bool readDeck(std::string filename);

        Card drawRandomCard();

        void dealCards(Player &user);

        void addCard(Card newCard);

        size_t getNumCards();

};