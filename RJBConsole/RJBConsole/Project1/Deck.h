/*Author: Robert Beckwith
Date: 9/12/17
Class: CIS 2542
File: Deck.h
Description:
		Specification file for the Deck class*/


// sequence with capacity of 52. Constructor assigns 52 cards in order of suit and rank. Friend function to display the whole deck with descriptive words

#ifndef deck_H
#define deck_H
#include "Card.h"
#include "Player.h"
#include <vector>
#include <cstdlib>
#include <ctime> 

class Deck {
public:
	using value_type = Card;
	using size_type = std::size_t;
	static const size_type CAPACITY = 52;

	Deck(); // default constructor

	//displays all the cards in the deck
	friend void displayCards(Deck);

	// gets a specific card at a specific index used in the deal function
	Card getCard(Deck, int);

	//swaps two cards
	void swap(int,int);

	//goes through 1 through 52 and swaps each card with a random other card
	void shuffle();
	
private:
	// array to hold all the cards in the deck 
	value_type Cards[CAPACITY]; // The deck
};
#endif