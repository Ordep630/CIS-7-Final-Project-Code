#include "PlayerActionInfo.h"
#include "Game.h"

PlayerActionInfo::PlayerActionInfo() {
    // Initialize 2D arrays based on the provided sizes
    hardTotalArray = new int*[hardTotalRows];
    for (int i = 0; i < hardTotalRows; ++i) {
        hardTotalArray[i] = new int[hardTotalCols];
    }

    softTotalArray = new int*[softTotalRows];
    for (int i = 0; i < softTotalRows; ++i) {
        softTotalArray[i] = new int[softTotalCols];
    }

    pairArray = new int*[pairRows];
    for (int i = 0; i < pairRows; ++i) {
        pairArray[i] = new int[pairCols];
    }
    // 'S' = Stand, 's' = Split, 'H' = hit, 'D' = double
    int hardValues [10][11] = {
        {0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11},
        {17, 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S'},
        {16, 'S', 'S', 'S', 'S', 'S', 'H', 'H', 'H', 'H', 'H'},
        {15, 'S', 'S', 'S', 'S', 'S', 'H', 'H', 'H', 'H', 'H'},
        {13, 'S', 'S', 'S', 'S', 'S', 'H', 'H', 'H', 'H', 'H'},
        {12, 'H', 'H', 'S', 'S', 'H', 'H', 'H', 'H', 'H', 'H'},
        {11, 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D'},
        {10, 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'H', 'H'},
        {9, 'H', 'D', 'D', 'D', 'D', 'H', 'H', 'H', 'H', 'H'},
        {5, 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H'},
    };
    for (int i = 0; i < hardTotalRows; ++i) {
        for (int j = 0; j < hardTotalCols; ++j) {
            hardTotalArray[i][j] = hardValues[i][j];
        }
    }
    int softValues[6][10] = {
        {'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S'},
        {'S', 'S', 'S', 'S', 'D', 'S', 'S', 'S', 'S', 'S'},
        {'D', 'D', 'D', 'D', 'D', 'S', 'S', 'H', 'H', 'H'},
        {'H', 'D', 'D', 'D', 'D', 'H', 'H', 'H', 'H', 'H'},
        {'H', 'H', 'D', 'D', 'D', 'H', 'H', 'H', 'H', 'H'},
        {'H', 'H', 'H', 'D', 'D', 'H', 'H', 'H', 'H', 'H'}
    };
    for (int i = 0; i < softTotalRows; ++i) {
        for (int j = 0; j < softTotalCols; ++j) {
            softTotalArray[i][j] = softValues[i][j];
        }
    }
    int pairs[11][13] = {
        {0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13},
        {11, 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's'},
        {10, 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S'},
        {9, 's', 's', 's', 's', 's', 's', 'S', 's', 'S', 'S', 'S', 'S'},
        {8, 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's'},
        {7, 's', 's', 's', 's', 's', 's', 'H', 'H', 'H', 'H', 'H', 'H'},
        {6, 's', 's', 's', 's', 's', 'H', 'H', 'H', 'H', 'H', 'H', 'H'},
        {5, 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'H', 'H', 'H', 'H'},
        {4, 'H', 'H', 'H', 's', 's', 'H', 'H', 'H', 'H', 'H', 'H', 'H'},
        {3, 's', 's', 's', 's', 's', 's', 'H', 'H', 'H', 'H', 'H', 'H'},
        {2, 's', 's', 's', 's', 's', 's', 'H', 'H', 'H', 'H', 'H', 'H'},
    };
    for (int i = 0; i < pairRows; ++i) {
        for (int j = 0; j < pairCols; ++j) {
            pairArray[i][j] = pairs[i][j];
        }
    }
}

PlayerActionInfo::~PlayerActionInfo() {
    // Deallocate memory for 2D arrays
    for (int i = 0; i < hardTotalRows; ++i) {
        delete[] hardTotalArray[i];
    }
    delete[] hardTotalArray;

    for (int i = 0; i < softTotalRows; ++i) {
        delete[] softTotalArray[i];
    }
    delete[] softTotalArray;

    for (int i = 0; i < pairRows; ++i) {
        delete[] pairArray[i];
    }
    delete[] pairArray;
}

bool PlayerActionInfo::getHardTotalAction(const std::vector<Card>& playerHand, const std::vector<Card>& houseHand) const {
    // Example logic: return the action based on the hard total
    // Customize this based on your game's rules for hard totals
    // For simplicity, return 0 for all values
    return 0;
}

bool PlayerActionInfo::getSoftTotalAction(const std::vector<Card>& playerHand, const std::vector<Card>& houseHand) const {
    // Example logic: return the action based on the soft total
    // Customize this based on your game's rules for soft totals
    // For simplicity, return 0 for all values
    return 0;
}

bool PlayerActionInfo::getPairAction(const std::vector<Card>& playerHand, const std::vector<Card>& houseHand) const {
    // Look at Array for pair moves, skip first row since that is house hand values
    int row = 0, col = 0;
    int i, j;
    for(i = 1; i < pairRows; i++){
        if(playerHand[0].value == pairArray[i][0]){
            row = i;
            for(j = 1; j < pairCols; j++){
                if(houseHand[1].value == pairArray[0][j]){
                    col = j;
                }
            }
        }
    }
    char action = static_cast<char>(pairArray[row][col]);
    switch(action){
        case 'H':
            std::cout << "Don't split!\n";
            return false;
            break;
        case 'S':
            std::cout << "Don't split!\n";
            return false;
            break;
        case 's':
            std::cout << "Best move is to split! ";
            break;
        case 'D':
            std::cout << " Don't split!";
            return false;
            break;
    }
}
