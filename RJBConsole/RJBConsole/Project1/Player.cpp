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
void addCard(Card card,Player p) {
	p.hand.push_back(card);
}
void showHand(Player p) {
	for (size_t i = 0; i < HAND_SIZE; i++)
	{
		cout << p.hand[i];
	}
	
}
void Player::deal(Player& p1, Player& p2, Player& p3, Player& p4, Deck d) {
	for (size_t i = 0; i < (HAND_SIZE *4); i += 4)
	{
		p1.hand.push_back(d.getCard(d,i));
		p2.hand.push_back(d.getCard(d, i+1));
		p3.hand.push_back(d.getCard(d, i+2));
		p4.hand.push_back(d.getCard(d, i+3));
		/*p2.hand[i] = d.getCard[i+1];
		p3.hand[i] = d.getCard[i+2];
		p4.hand[i] = d.getCard[i+3];*/
		/*addCard(d.getCard(d, i+1), p2);
		addCard(d.getCard(d, i+2), p3);
		addCard(d.getCard(d, i+3), p4);*/

	}
}

Card discard(Player& p) {
	Card c = p.hand.back();
	p.hand.pop_back();
	return c;
}