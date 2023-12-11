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
        std::cout << "available money: " << player.money << std::endl;
        std::cout << "Place your bet: ";
        std::cin >> betAmount;
        char choice;
        bool playerBust = false, endLoop = false, splitEnd = false, stand = false;
        int handValue;
        // Start a new round
        game.startRound(betAmount);
        if (game.calculateHandValue(game.playerHand) == 21) {
            if (game.calculateHandValue(game.playerHand) == game.calculateHandValue(game.houseHand)) {
                player.money += betAmount;
                std::cout << "It's a push :/ Remaining money: " << player.money << std::endl;
                endLoop = true;
            }

            std::cout << "You win! Remaining money: " << player.money << std::endl;
            endLoop = true;
        }


        while (!endLoop) {
            char hardAction, softAction, hardSplitAction, softSplitAction;
            char action, splitAction;
            int choice;

            // Calculate move and probability with player split hand
            int handValue = game.calculateHandValue(game.playerHand);
            int splitValue = game.calculateHandValue(game.playerHand);

            if (game.splitState) {
                hardAction = static_cast<char> (bestMove.getHardTotalAction(game.playerHand, game.houseHand, handValue));
                if (game.playerHand[0].value == 1) {
                    softAction = static_cast<char> (bestMove.getSoftTotalAction(game.playerHand, game.houseHand, splitValue));
                }
                hardSplitAction = static_cast<char> (bestMove.getHardTotalAction(game.playerHand, game.houseHand, game.calculateHandValue(game.playerHand)));
                softSplitAction = static_cast<char> (bestMove.getSoftTotalAction(game.playerHand, game.houseHand, game.calculateHandValue(game.playerHand)));
            }// Assume deck is not split

            else {
                hardAction = static_cast<char> (bestMove.getHardTotalAction(game.playerHand, game.houseHand, game.calculateHandValue(game.playerHand)));
                if (game.playerHand[0].value == 1) {
                    softAction = static_cast<char> (bestMove.getSoftTotalAction(game.playerHand, game.houseHand, handValue));
                    std::cout << softAction;
                    action = softAction;
                } else {
                    action = hardAction;
                }

            }
            probability.calculateProbability(game.playerHand, game.houseHand, action);
            switch (action) {
                case 'H':
                    std::cout << "Best move is to hit main hand!\n";
                    break;
                case 'S':
                    std::cout << "Best move is to stand main hand!\n";
                    break;
                case 'D':
                    std::cout << "Best move is to double main hand!\n";
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
                    std::cout << "Best move is to double split hand!\n";
                    break;
            }

            std::cout << "Choose an action: \n";
            std::cout << "1. Hit\n";
            std::cout << "2. Double\n";
            std::cout << "3. Stand\n";
            std::cout << "4. Split hand hit\n";
            std::cout << "5. Split hand double\n";
            std::cout << "6. Split hand stand\n";
            std::cout << "Enter your choice (1-6): ";

            // Get player's choice
            std::cin >> choice;

            switch (choice) {
                case 1:
                    game.hit();
                    break;
                case 2:
                    betAmount *= 2;
                    game.doubleDown(betAmount);
                    // Add logic for doubling down
                    break;
                case 3:
                    // Player stands, do nothing
                    stand = true;
                    break;
                case 4:
                    game.splitHit();
                    break;
                case 5:
                    betAmount *= 2;
                    game.doubleDown(betAmount);
                    break;
                case 6:
                    if (game.splitState) {
                        // Hand is split
                        stand = true;
                    }
                    break;
                default:
                    std::cout << "Invalid choice. Please enter a number between 1 and 3.\n";
            }
            // Display hands after each action
            game.displayHands();
            if (game.splitState) {
                if (endLoop != splitEnd) {
                    endLoop = false;
                }
            }
            // Look at end states
            int hand = game.calculateHandValue(game.playerHand);
            int house = game.calculateHandValue(game.houseHand);
            if (game.splitState) {

                int split = game.calculateHandValue(game.splitHand);
                if (hand > 21) {
                    player.money += -betAmount;
                    std::cout << "Main hand busted :( Remaining money: " << player.money << std::endl;

                }
                if (split > 21) {
                    player.money += -betAmount;
                    std::cout << "Split hand busted :( Remaining money: " << player.money << std::endl;

                }
                if (split > 21 && hand > 21) {
                    player.money += -(betAmount * 2);
                    std::cout << "Both hands busted :( Remaining money: " << player.money << std::endl;
                    endLoop = true;
                }
            }
            if (hand > 21) {
                player.money += -betAmount;
                std::cout << "You busted :( , remaining money: " << player.money << std::endl;
                endLoop = true;
            }

            if (stand) {
                // Keep hitting house hand until it is above 17
                while (house < 17) {
                    game.houseHit();
                    house = game.calculateHandValue(game.houseHand);
                }

                if (hand > house) {
                    player.money += betAmount * 2; // Paying out a 2x bet to keep it simple
                    std::cout << "You win! Remaining money: " << player.money << std::endl;
                    endLoop = true;
                } else if (hand == house) {
                    player.money += betAmount;
                    std::cout << "It's a push :/ Remaining money: " << player.money << std::endl;
                    endLoop = true;
                } else if (house > 21) {
                    player.money += betAmount * 2;
                    std::cout << "House busted, you win! Remaining money: " << player.money << std::endl;
                    endLoop = true;
                } else {
                    player.money += -betAmount;
                    std::cout << "House hand = " << house << ", your hand = " << hand << ", house wins :( Remaining money: " << player.money << std::endl;
                }
            }
        }

        std::cout << "Keep playing? (Y/N): ";
        std::cin >> choice;
        if (choice == 'n' || choice == 'N')
            playAgain = false;
    }
    return 0;

}