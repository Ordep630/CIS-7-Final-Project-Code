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


    for (int i = 17; i <= 21; ++i) {

        int count = 0;

        for (int j = 0 + hitCount; j < deckSize; j++) {
            
            value = remainingCards[j].value;
            
            if (value + houseValue <= i) {
                std::cout << count << std::endl;
                count++;
            }
        }
        if (i > playerValue && i <= 21) {
            houseWins += count;
            std::cout << houseWins << std::endl;
        }

    }
   double probability = static_cast<double> (houseWins) / deckSize;
    std::cout << probability;
    

}
//int Probability::simulateOutcome(int playerHandValue, int dealerUpcardValue, bool playerHits) {
/*
    // Determine the winner based on the final values
    if (playerFinalValue > 21) {
        return 0;  // Player busts, dealer wins
    } else if (dealerFinalValue > 21) {
        return 2;  // Dealer busts, player wins
    } else if (playerFinalValue > dealerFinalValue) {
        return 2;  // Player wins
    } else if (playerFinalValue < dealerFinalValue) {
        return 0;  // Dealer wins
    } else {
        return 1;  // It's a push (tie)
    }
 */

