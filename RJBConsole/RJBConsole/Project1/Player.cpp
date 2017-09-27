/*Author: Robert Beckwith
Date: 9/19/17
Class: CIS 2542
File: Player.h
Description:
		implementation file for the Player class*/

#include "Player.h"

void Player::setName(string s) {
	name = s; 
}
void Player::addCard(Card card,Player& p) {
	p.hand.push_back(card);
}