#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <vector>

class Card {
public:
    int value;      // 1 to 13 for Ace to King
    char suit;      // 'S' for Spades, 'H' for Hearts, 'D' for Diamonds, 'C' for Clubs
    bool faceDown;  // Flag to indicate whether the card is face down

    // Constructor
    Card(int val, char s);

    // Function to set the card as face down
    void setFaceDown();
};

class Deck {
private:
    std::vector<Card> cards;

public:
    // Constructor
    Deck();

    // Function to initialize the deck
    void initializeDeck();

    // Function to shuffle the deck
    void shuffleDeck();

    // Function to set an individual card as face down
    void setCardFaceDown(int index);

    // Function to draw a card from the deck
    Card drawCard();
    Card drawSpecificCard(int value, char suit);

    // Function to deal two cards to a player
    std::vector<Card> dealToPlayer();

    // Function to deal two cards to the house
    std::vector<Card> dealToHouse();

    // Function to display the deck
    void displayDeck() const;
};

#endif
