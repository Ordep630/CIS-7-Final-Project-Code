#include <iostream>
#include "Game.h"

bool playAgain = true;

int main() {

    while (playAgain) {
        // Create the objects
        Game game;
        Player player;
        PlayerActionInfo bestMove;
        Probability probability;

        // Prompt the player for a bet
        int betAmount;
        std::cout << "Place your bet: ";
        std::cin >> betAmount;

        // Start a new round
        game.startRound(betAmount);

        char choice;
        bool playerBust = false, endLoop = false, splitEnd = false;
        int handValue;
        while (!endLoop) {
            char hardAction, softAction, hardSplitAction, softSplitAction;
            char action, splitAction;
            int choice;


            // Calculate move and probability with player split hand
            int handValue = game.calculateHandValue(game.playerHand);
            int splitValue = game.calculateHandValue(game.playerHand);

            if (game.splitState) {
                hardAction = static_cast<char> (bestMove.getHardTotalAction(game.playerHand, game.houseHand, handValue));
                if (game.playerHand[0].value = 1) {
                    softAction = static_cast<char> (bestMove.getSoftTotalAction(game.playerHand, game.houseHand, splitValue));
                }
                hardSplitAction = static_cast<char> (bestMove.getHardTotalAction(game.playerHand, game.houseHand, game.calculateHandValue(game.playerHand)));
                softSplitAction = static_cast<char> (bestMove.getSoftTotalAction(game.playerHand, game.houseHand, game.calculateHandValue(game.playerHand)));
            }// Assume deck is not split
            
            else{

                hardAction = static_cast<char> (bestMove.getHardTotalAction(game.playerHand, game.houseHand, game.calculateHandValue(game.playerHand)));
                action = hardAction;
                if (game.playerHand[0].value == 1) {
                    softAction = static_cast<char> (bestMove.getSoftTotalAction(game.playerHand, game.houseHand, handValue));
                }
            
            }
            std::cout << action;
            //probability.calculateProbability(game.playerHand, game.houseHand, softAction);
            probability.calculateProbability(game.playerHand, game.houseHand, action);
            //std::cout << hardAction << " " << softAction<< std::endl;
            switch (action) {
                case 'H':
                    std::cout << "Best move is to hit main hand!\n";
                    break;
                case 'S':
                    std::cout << "Best move is to stand main hand!\n";
                    break;
                case 'D':
                    std::cout << "Best move is to double main hand!";
                    break;
            }
            switch (splitAction) {
                case 'H':
                    std::cout << "Best move is to hit split hand!\n";
                    break;
                case 'S':
                    std::cout << "Best move is to stand with split hand!\n";
                    break;
                case 'D':
                    std::cout << "Best move is to double split hand!";
                    break;
            }
            
            




            std::cout << "Choose an action: \n";
            std::cout << "1. Hit\n";
            std::cout << "2. Double\n";
            std::cout << "3. Stand\n";
            std::cout << "4. Split hand hit\n";
            std::cout << "5. Split hand double\n";
            std::cout << "6. Split hand stand\n";
            std::cout << "Enter your choice (1-3): ";

            // Get player's choice
            std::cin >> choice;

            switch (choice) {
                case 1:
                    game.hit();
                    break;
                case 2:
                    game.doubleDown(betAmount * 2);
                    // Add logic for doubling down
                    break;
                case 3:
                    // Player stands, do nothing
                    if (!game.splitState) {
                        endLoop = true;
                    } else {
                        endLoop = true;
                    }
                    break;
                case 4:
                    game.splitHit();
                    break;
                case 5:
                    game.doubleDown(betAmount * 2);
                    break;
                case 6:
                    if (game.splitState) {
                        // Hand is split
                        splitEnd = true;
                    }
                    break;
                default:
                    std::cout << "Invalid choice. Please enter a number between 1 and 3.\n";
            }
            // Display hands after each action
            game.displayHands();
            // Check if the player busts
            if (game.calculateHandValue(game.playerHand) > 21) {
                std::cout << "You bust! Game over.\n";
                endLoop = true;
                playerBust = true;
            }
            if (game.splitState && game.calculateHandValue(game.splitHand) > 21) {
                splitEnd = true;
                std::cout << "Your split hand busted!\n";
                playerBust = true;
            }
            if (game.splitState) {
                if (endLoop != splitEnd) {
                    endLoop = false;
                }
            }
        }
        // Keep hitting house hand until it is abouve 17
        while (game.calculateHandValue(game.houseHand) < 17) {
            game.houseHit();
        }



        std::cout << "Keep playing? (Y/N): ";
        std::cin >> choice;
        if (choice == 'n' || choice == 'N')
            playAgain = false;
    }
    return 0;
}