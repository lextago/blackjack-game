#pragma once

#include <iostream>
#include <vector>

struct Card{
    std::string name;
    int value;
};

struct Hand{
    std::vector<Card> handCards;
    size_t totalValue;
    bool containsAce;
};

class Game{
    private:
        size_t playerWallet;
        size_t currBet;
        size_t numDecks;

        std::vector<Card> dealerDeck;

        Hand playerHand;
        Hand dealerHand;

    public:
        Game(size_t playerWallet, size_t numDecks);

        bool walletEmpty();

        //bet

        void clearTable();

        void playerBet();

        void dealCards();

        Card drawRandomCard();

        std::string handToString(bool isPlayer);

        //hit

        //stand

        //double

        //split

        //surrender
};