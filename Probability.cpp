#include "Probability.h"

Game game;

Probability::Probability() : deck(), player(), card() {
    // Additional initialization if needed
}

double Probability::calculateProbability(const std::vector<Card>& playerHand, const std::vector<Card>& houseHand, char action) {
    std::vector<Card> remainingCards = deck.getRemainingCards();
    // std::cout <<action <<std::endl;
    switch (action) {
        case 'H':
            hitCount++;
            std::cout << "Probability the house wins after hitting: ";
            simulateHouseTurn(playerHand, houseHand, remainingCards, hitCount);
            std::cout << std::endl;
            break;
        case 'S':
            std::cout << "Probability the house wins after standing: ";
            simulateHouseTurn(playerHand, houseHand, remainingCards, hitCount);
            std::cout << std::endl;
            break;
        case 'D':
            std::cout << "Probability the house wins after doubling: ";
            simulateHouseTurn(playerHand, houseHand, remainingCards, hitCount);
            std::cout << std::endl;
            break;
    }

}

int Probability::simulateHouseTurn(const std::vector<Card>& playerHand, const std::vector<Card>& houseHand, const std::vector<Card> remainingCards, int hitCount) {

    int deckSize = 52 - playerHand.size() - houseHand.size() - hitCount;

    int houseValue = game.calculateHandValue(houseHand);

    int playerValue = game.calculateHandValue(playerHand);
    int value;
    int houseWins = 0;
    int countTotal = 0;
    int count = 0;
    int i;

    for (i = 0 + hitCount; i < deckSize; i++) {
        value = remainingCards[i].value;
        if (value + houseValue <= 21) {
            count++;
        }
    }
    if (playerValue < value + houseValue) {
        houseWins += count;
    }
    double probability = static_cast<double> (houseWins) / deckSize;
    std::cout << probability;

}
