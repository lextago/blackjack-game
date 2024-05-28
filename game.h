#pragma once

#include <iostream>
#include <vector>

struct Card{
    std::string name;
    int value;
};

struct Hand{
    std::vector<Card> cards;
    size_t totalValue;
    bool aceWeighted;
    bool isBust;
    bool isBlackjack;
};