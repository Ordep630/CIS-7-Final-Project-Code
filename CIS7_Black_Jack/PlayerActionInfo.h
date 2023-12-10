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
    int hardTotalRows = 9;
    int hardTotalCols = 10;
    int softTotalRows = 6;
    int softTotalCols = 10;
    int pairRows = 11;
    int pairCols = 13;
    
    Deck deck;
    Player player;

public:
    // Constructor
    PlayerActionInfo();

    // Destructor
    ~PlayerActionInfo();

    // Functions to get the action for a specific hand value
    bool getHardTotalAction(const std::vector<Card>& playerHand, const std::vector<Card>& houseHand) const;
    bool getSoftTotalAction(const std::vector<Card>& playerHand, const std::vector<Card>& houseHand) const;
    bool getPairAction(const std::vector<Card>& playerHand, const std::vector<Card>& houseHand) const;
};

#endif