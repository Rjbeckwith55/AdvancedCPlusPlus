/*Author: Robert Beckwith
Date: 9/12/17
Class: CIS 2542
File: Deck.h
Description:
		Specification file for the Deck class*/


// sequence with capacity of 52. Constructor assigns 52 cards in order of suit and rank. Friend function to display the whole deck with descriptive words
#include "Card.h"

class Deck {
	friend void DisplayCards();
};
