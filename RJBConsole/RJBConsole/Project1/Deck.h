/*Author: Robert Beckwith
Date: 9/12/17
Class: CIS 2542
File: Deck.h
Description:
		Specification file for the Deck class*/


// sequence with capacity of 52. Constructor assigns 52 cards in order of suit and rank. Friend function to display the whole deck with descriptive words
#include "Card.h"
#include <vector>
#include <cstdlib>

#ifndef deck_H
#define deck_H

class Deck {
public:
	using value_type = vector<Card>;
	using size_type = std::size_t;
	static const size_type CAPACITY = 52;


	Deck();


	friend void DisplayCards();
private:
	value_type Cards;
	// number of items stored
	size_type used;
	// current item's reference
	size_type current_index;
};
#endif