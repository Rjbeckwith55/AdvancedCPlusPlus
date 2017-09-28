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
#include "Card.h"
#include <vector>

class Player {
private:
	string name;
	vector<Card> hand;
public:
	string getName() { return name; }
	void setName(string s);
	friend void addCard(Card, Player);
	friend class Deck;
	
	
	
};
#endif