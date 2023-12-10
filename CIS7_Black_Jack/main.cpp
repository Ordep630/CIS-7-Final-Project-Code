#include <iostream>
#include "Game.h"

bool playAgain = true;

int main() {
    
    while (playAgain) {
        // Create a Game object
        Game game;
        Player player;

        // Prompt the player for a bet
        int betAmount;
        std::cout << "Place your bet: ";
        std::cin >> betAmount;

        // Start a new round
        game.startRound(betAmount);

        char choice;
        bool playerBust = false, endLoop = false;
        int handValue;
        while (!endLoop) {
            
int choice;
            std::cout << "Choose an action: \n";
            std::cout << "1. Hit\n";
            std::cout << "2. Double\n";
            std::cout << "3. Stand\n";
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
                    endLoop = true;
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

           

        }
        std::cout << "Keep playing? (Y/N): ";
        std::cin >> choice;
        if (choice == 'n' || choice == 'N')
            playAgain = false;
                    }
    return 0;
}