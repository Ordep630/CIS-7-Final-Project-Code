#ifndef PLAYER_ACTION_INFO_H
#define PLAYER_ACTION_INFO_H

#include <vector>

#include "Player.h"
#include "Deck.h"

class PlayerActionInfo {
private:
        
    
    // Arrays to store information about actions for hard totals, soft totals, and pairs
    int** hardTotalArray;
    int** softTotalArray;
    int** pairArray;

    // Sizes of the arrays
    int hardTotalRows = 17;
    int hardTotalCols = 14;
    int softTotalRows = 9;
    int softTotalCols = 14;
    int pairRows = 11;
    int pairCols = 14;
    
    Deck deck;
    Player player;

public:
    // Constructor
    PlayerActionInfo();

    // Destructor
    ~PlayerActionInfo();

    // Functions to get the action for a specific hand value
    int getHardTotalAction(const std::vector<Card>& playerHand, const std::vector<Card>& houseHand, int playerHandValue) const;
    int getSoftTotalAction(const std::vector<Card>& playerHand, const std::vector<Card>& houseHand, int playerHandValue) const;
    bool getPairAction(int value, const std::vector<Card>& houseHand) const;
};

#endif