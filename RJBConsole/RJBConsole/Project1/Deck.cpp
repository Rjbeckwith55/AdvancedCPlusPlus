/*Author: Robert Beckwith
Date: 9/12/17
Class: CIS 2542
File: Deck.cpp
Description:
Implementation file for the Deck class*/

#include "Deck.h"

using namespace std;

const Deck::size_type CAPACITY = 52;

// Creates all the cards two through ace of one suit then goes onto the next suit
Deck::Deck() {
	int r = Card::ranks::two;
	int s = Card::suits::clubs;
	for (size_type i = 0; i < CAPACITY; i++)
	{
		
		Cards[i].setRank(r);
		Cards[i].setSuit(s);
		
		if (r == Card::ranks::ace) {
			r = Card::ranks::two; // reset back to the first card value (two)
			s++; //increment suit by one to go to the next suit
		}
		else
			r++;
	}
}

Card Deck::getCard(Deck d,int index) {
	return d.Cards[index];
}

// Display all the cards in the deck
void displayCards(Deck d){
	for (Deck::size_type i = 0; i < CAPACITY; i++)
	{
		cout << d.Cards[i];
	}
	
}

// Function to swap two cards in the deck
void Deck::swap(int k,int index) {
	Card temp;
	temp = Cards[k];
	Cards[k] = Cards[index];
	Cards[index] = temp;
}

// Shuffle the deck of cards
void Deck::shuffle() {
	// Define the bounds of the random number
	const Deck::size_type MIN_VALUE = 0, MAX_VALUE = 51;

	// generate a random seed off of time
	unsigned seed = time(0);
	srand(seed);
	Deck::size_type k;
	

	//Loop through all the cards in the deck swapping them with a random one
	for (size_t index = 0; index < CAPACITY; index++)
	{
		k = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
		Deck::swap(k, index);
	}
	

}

 /*void Deck::deal(Deck d) {
	 Player p1;
	 Player p2;
	 Player p3;
	 Player p4;
	for (size_t i = 0; i < 52; i+=4)
	{
		addCard(d.Cards[i],p1);
		addCard(d.Cards[i+1], p2);
		addCard(d.Cards[i+2], p3);
		addCard(d.Cards[i+3], p4);

	}
}*/