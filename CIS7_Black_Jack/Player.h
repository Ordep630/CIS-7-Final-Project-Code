#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>

class Player {
private:
    
    int bet;    // Player's current bet

public:
    // Constructor with default initial money set to $1000
    Player(int initialMoney = 1000);
int money;  // Player's money or chips
    // Function to place a bet
    bool placeBet(int betAmount);

    // Getter for the current bet
    int getBet() const;

    // Function to reset the bet at the start of a new round
    void resetBet();

    
};

#endif