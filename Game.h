#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "Player.h"
#include "PlayerActionInfo.h"
#include "Probability.h"

class Game {
private:
        
        Deck deck;
        Player player;
        PlayerActionInfo bestMove;
        

public:
        // Constructor
        Game();
        void startRound(int betAmount);

        void displayHands() const;
        std::vector<Card> playerHand;
        std::vector<Card> houseHand;
        std::vector<Card> splitHand;
        bool splitState = false;
        bool noSplit = true;

        int calculateHandValue(const std::vector<Card>& hand) const;

        void hit();
        void splitHit();
        void houseHit();
        void doubleDown(int betAmount);
        void split();

};

#endif
