#ifndef PROBABILITY_H
#define PROBABILITY_H

#include <vector>
#include <string>

#include "Player.h"
#include "Deck.h"
#include "Game.h"  // Include the full definition of the Game class

class Probability {
public:
    // Constructor
    Probability();

    // Function to calculate the winning probability for a player
    double calculateProbability(const std::vector<Card>& playerHand, const std::vector<Card>& houseHand, char action);

private:
    Deck deck;
    Player player;
    Card card;

    int hitCount = 0; // Keep track of all moves simulated


    // Helper functions
    int simulateHouseTurn(const std::vector<Card>& playerHand, const std::vector<Card>& houseHand, std::vector<Card> remainingCards, int hitCount);
    static int simulateOutcome(const std::vector<Card>& playerHand, const std::vector<Card>& houseHand);
};

#endif // PROBABILITY_H