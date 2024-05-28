#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <assert.h>

#include "game.h"

class Player{
    private:
        Hand playerHand;
        size_t walletAmt;
        size_t currBet;
    
    public:
        Player(size_t walletAmt);

        void clear();

        std::string handToString();

        std::string totalToString();

        void dealCards();

        void addCard(Card newCard);

        void bet();

        void hit();

        //stand

        void stand();

        //double

        void doubleBet();

        //split

        void split();

        //surrender

        void surrender();

        void addCard(int cardIndex, bool isPlayer);

        void choice();

};