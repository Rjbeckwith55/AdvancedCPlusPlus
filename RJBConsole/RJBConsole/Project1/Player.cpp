/*Author: Robert Beckwith
Date: 9/19/17
Class: CIS 2542
File: Player.h
Description:
		implementation file for the Player class*/

#include "Player.h"

static const Player::size_type HAND_SIZE = 13;


Player::Player(){
	name = "";
}

void Player::setName(string s) {
	name = s; 
}

//prints out the hand
void showHand(Player p) {
	for (size_t i = 0; i <p.hand.size(); i++)
	{
		cout << p.hand[i];
	}
	
}

//deal 14 cards out to each player
void Player::deal(Player& p1, Player& p2, Player& p3, Player& p4, Deck d) {
	for (size_t i = 0; i < (HAND_SIZE *4); i += 4)
	{
		//add a car to the hand vector using the get card function with an index off by 4 each time
		p1.hand.push_back(d.getCard(d,i));
		p2.hand.push_back(d.getCard(d, i+1));
		p3.hand.push_back(d.getCard(d, i+2));
		p4.hand.push_back(d.getCard(d, i+3));

	}
}

//discards the last card in each players hand
Card discard(Player& p) {
	Card c = p.hand.back();
	p.hand.pop_back();
	return c;
}

int getValue(Player& p) {
	int value = 0;
	for (size_t i = 0; i < p.hand.size(); i++)
	{
		value = value + p.hand[i];
	}
	return value; 

}