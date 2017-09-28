/*Author: Robert Beckwith
Date: 9/19/17
Class: CIS 2542
File: Player.h
Description:
		Specification file for the Player class*/
#ifndef player_H
#define player_H
/*Use a circular linked list to run a simple simulation of a card game. Use the card and deck classes, and shuffle and deal functions
from previous Programming Projects. Create a player class to hold a hand of dealt cards. During each turn, a player will discard a card.
Use rand( ) to determine who gets the first turn in each hand, and make sure each person has a turn during every hand. The program ends when all cards have been played.*/
#include "Deck.h"
#include <vector>

class Deck;  // something to fix "identifier error"
class Player {
private:
	// name of each player in the game
	string name;

	// vector of cards to hold the cards for each players hand
	vector<Card> hand;

public:
	Player(); // default constructor

	using size_type = std::size_t;
	static const size_type HAND_SIZE = 13; // size of each player's hand

	
	string getName() { return name; } // inline getter
	void setName(string s); // setter

	//deal the cards out to each of the players in the game
	void deal(Player&, Player&, Player&, Player&, Deck);

	//print out each players hand currently can only print when the hand is full
	friend void showHand(Player p);

	//discard a player's card
	friend Card discard(Player&);

	//add up the value of a player's hand
	friend int getValue(Player&);
	
	
	
};
#endif