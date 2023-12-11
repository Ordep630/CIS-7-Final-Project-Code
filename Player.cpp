#include "Player.h"

// Constructor
Player::Player(int initialMoney) : money(initialMoney), bet(0) {}

// Function to place a bet
bool Player::placeBet(int betAmount) {
    // Check if the player has enough money for the bet
    if (betAmount <= money) {
        bet = betAmount;
        money -= betAmount;
        return true;
    } else {
        std::cout << "Insufficient funds. Bet not placed.\n";
        return false;
    }
}

// Getter for the current bet
int Player::getBet() const {
    return bet;
}

// Function to reset the bet at the start of a new round
void Player::resetBet() {
    bet = 0;
}