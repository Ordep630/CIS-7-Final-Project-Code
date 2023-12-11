#include "Deck.h"
#include <algorithm>
#include <ctime>
#include <random>

// Card constructor
Card::Card(int val, char s) : value(val), suit(s), faceDown(false) {}

// Constructor
Deck::Deck() {
    initializeDeck();
}

// Function to initialize the deck
void Deck::initializeDeck() {
    const char suits[] = {'S', 'H', 'D', 'C'}; // Spades, Hearts, Diamonds, Clubs
    for (char suit : suits) {
        for (int value = 1; value <= 13; ++value) {
            cards.emplace_back(value, suit);
        }
    }

}

// Function to shuffle the deck using a combination of srand and std::mt19937
void Deck::shuffleDeck() {
    // Seed the random number generator with the current time using srand
    std::srand(static_cast<unsigned>(std::time(0)));

    // Use std::mt19937 for additional randomness
    std::mt19937 gen(std::rand());

    // Shuffle the deck
    for (int i = static_cast<int>(cards.size()) - 1; i > 0; --i) {
        int j = std::rand() % (i + 1);
        std::swap(cards[i], cards[j]);
    }
}

// Function to set an individual card as face down
void Deck::setCardFaceDown(int index) {
    if (index >= 0 && index < cards.size()) {
        cards[index].setFaceDown();
    }
}

// Function to draw a card from the deck
Card Deck::drawCard() {
    if (!cards.empty()) {
        Card drawnCard = cards.back();
        cards.pop_back();
        return drawnCard;
        
    }
    // If the deck is empty, return a default card
    return Card(0, 'N');  // 'N' for "No suit"
}

// Function to deal two cards to a player
std::vector<Card> Deck::dealToPlayer() {
    std::vector<Card> playerHand;
    playerHand.push_back(drawCard());
    playerHand.push_back(drawCard());
    return playerHand;
}

// Function to deal two cards to the house
std::vector<Card> Deck::dealToHouse() {
    std::vector<Card> houseHand;
    
    // Draw the first card face down
    Card firstCard = drawCard();
    firstCard.setFaceDown();
    houseHand.push_back(firstCard);

    // Draw the second card face up
    houseHand.push_back(drawCard());

    return houseHand;
}

int Deck::deckSize() const {
                return cards.size();
}

std::vector<Card> Deck::getRemainingCards() const {
    return cards;
}
// Function to display the deck
void Deck::displayDeck() const {
    for (const auto& card : cards) {
        if (card.faceDown) {
            std::cout << "** ";
        } else {
            std::cout << card.value << card.suit << "  ";
        }
    }
    std::cout << "\n";
}

// Function to set the card as face down
void Card::setFaceDown() {
    faceDown = true;
}
Card Deck::drawSpecificCard(int value, char suit) {
    auto it = std::find_if(cards.begin(), cards.end(), [value, suit](const Card& card) {
        return card.value == value && card.suit == suit;
    });

    if (it != cards.end()) {
        Card drawnCard = *it;
        cards.erase(it);
        return drawnCard;
    }

    // If the card is not found, return a default card
    return Card(0, 'N');  // 'N' for "No suit"
}

