#include <iostream>
#include "Deck.h"
#include "Game.h"


// Constructor

Game::Game() {
deck.initializeDeck();
   deck.shuffleDeck();
}

// Function to start a new round

void Game::startRound(int betAmount) {
    // Clear hands from previous rounds
    playerHand.clear();
    houseHand.clear();

    // Place the bet
    player.placeBet(betAmount);

    // Deal two cards to the house and player
    houseHand = deck.dealToHouse();
    playerHand = deck.dealToPlayer();

    displayHands();

    // Check if the player can split
    int firstCard = playerHand[0].value;
    int secondCard = playerHand[1].value;
    // Handle if both cards are Jack Queen or King, since these are defined as different values
    if (10 <= firstCard && firstCard <= 12 && 10 <= secondCard && secondCard <= 12 ){
        firstCard = 10;
        secondCard = 10;
    }
    if (playerHand.size() == 2 && firstCard == secondCard) {
        if (bestMove.getPairAction(firstCard, houseHand)) {
            char splitChoice;
            std::cout << "Do you want to split? (Y/N): ";
            std::cin >> splitChoice;
            if (splitChoice == 'y' || splitChoice == 'Y')
                split();
        }
    } else {
        std::cout << "Hand is not eligible to split\n";
    }
}


// Function to display hands

void Game::displayHands() const {
    std::cout << "House's Hand: ";
    // Display the first card face down
    if (!houseHand.empty()) {
        const auto& firstCard = houseHand.front();
        if (firstCard.faceDown) {
            std::cout << "** ";
        } else {
            std::cout << firstCard.value << firstCard.suit << " ";
        }
    }

    // Display the rest of the cards face up
    for (size_t i = 1; i < houseHand.size(); ++i) {
        int value = houseHand[i].value;
        if (value == 11) {
            std::cout << "J" << houseHand[i].suit << " ";
        } else if (value == 12) {
            std::cout << "Q" << houseHand[i].suit << " ";
        } else if (value == 13) {
            std::cout << "K" << houseHand[i].suit << " ";
        } else if (value == 1) {
            std::cout << "A" << houseHand[i].suit << " ";
        } else {
            std::cout << houseHand[i].value << houseHand[i].suit << " ";
        }
    }
    std::cout << "\n";

    // Display main hand
    std::cout << "Player's Main Hand: ";
    for (const auto& card : playerHand) {
        int value = card.value;
        if (value == 11) {
            std::cout << "J" << card.suit << " ";
        } else if (value == 12) {
            std::cout << "Q" << card.suit << " ";
        } else if (value == 13) {
            std::cout << "K" << card.suit << " ";
        } else if (value == 1) {
            std::cout << "A" << card.suit << " ";
        } else {
            std::cout << card.value << card.suit << " ";
        }
    }
    std::cout << "\n";

    // Display split hand if the split state is true
    if (splitState) {
        std::cout << "Player's Split Hand: ";
        for (const auto& card : splitHand) {
            std::cout << card.value << card.suit << "  ";
        }
        std::cout << "\n";
    }
   // std::cout << "\n";
    std::cout << "Player's Hand Value: " << calculateHandValue(playerHand) << "\n";
}

void Game::hit() {
    // Draw a card and add it to the player's hand
    playerHand.push_back(deck.drawCard());
}
void Game::splitHit() {
    // Draw a card and add it to the player's split hand
    splitHand.push_back(deck.drawCard());
}
void Game::houseHit(){
    houseHand.push_back(deck.drawCard());
}

void Game::doubleDown(int doubledBet) {
    player.placeBet(doubledBet);
    hit();
}

void Game::split() {
    // Set split state to true
    splitState = true;

    // Move the second card from the main hand to the split hand
    splitHand.push_back(playerHand.back());
    playerHand.pop_back();

    // Deal one card to each of the main and split hands
    playerHand.push_back(deck.drawCard());
    splitHand.push_back(deck.drawCard());

    // Display hands after splitting
    displayHands();
}

int Game::calculateHandValue(const std::vector<Card>& hand) const {
    int totalValue = 0;
    int numberOfAces = 0;

    for (const auto& card : hand) {
        // Face cards count as 10
        if (card.value >= 10) {
            totalValue += 10;
        } else if (card.value == 1) { // Ace
            totalValue += 11;
            ++numberOfAces;
        } else {
            totalValue += card.value;
        }
    }

    // Adjust for Aces if needed
    while (totalValue > 21 && numberOfAces > 0) {
        totalValue -= 10;
        --numberOfAces;
    }

    return totalValue;
}
