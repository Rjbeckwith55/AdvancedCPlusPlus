/*Author: Robert Beckwith
Date: 9/12/17
Class: CIS 2542
File: Deck.cpp
Description:
Implementation file for the Deck class*/

#include "Deck.h"

const Deck::size_type CAPACITY = 52;

Deck::Deck() {
	int r = Card::ranks::two;
	int s = Card::suits::clubs;
	for (size_type i = 0; i < CAPACITY; i++)
	{
		if (r == Card::ranks::ace) {
			r = Card::ranks::two; // reset back to the first card value (two)
			s++; //increment suit by one to go to the next suit
		}
		Cards[i].setRank(r);
		Cards[i].setSuit(s);
		r++;

	}
}

void displayCards() {
	for (Deck::size_type i = 0; i < CAPACITY; i++)
	{
		cout <<Cards[i];
	}
	
}