#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "Player.h"
#include "PlayerActionInfo.h"

class Game {
private:
        Deck deck;
        Player player;
        PlayerActionInfo bestMove;
        bool splitState = false;

public:
        // Constructor
        Game();
        void startRound(int betAmount);

        void displayHands() const;
        std::vector<Card> playerHand;
        std::vector<Card> houseHand;
        std::vector<Card> splitHand;
        

        int calculateHandValue(const std::vector<Card>& hand) const;

        void hit();
        void doubleDown(int betAmount);
        void split();

};

#endif
