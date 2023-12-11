#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>

class Player {
private:


public:
        // Constructor with default initial money set to $1000
        Player(int initialMoney = 1000);

        // Function to place a bet
        bool placeBet(int betAmount);

        // Getter for the current bet
        int getBet() const;

        // Function to reset the bet at the start of a new round
        void resetBet();
        int money; // Player's money or chips
        int bet; // Player's current bet
};

#endif