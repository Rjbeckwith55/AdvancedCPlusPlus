/*Author: Robert Beckwith
Date: 9/25/17
Class: CIS 2542
File: simulation.cpp
Description:
Simulation program to pick a random player and discard the cards*/

#include "Player.h"



int main() {
	Player p1, p2, p3, p4;
	Deck deck;
	string name1,name2,name3,name4;
	cout << "Enter in the first Player's name: ";
	cin >> name1;
	p1.setName(name1);
	cout << "Enter in the second Player's name: ";
	cin >> name2;
	p2.setName(name2);
	cout << "Enter in the third Player's name: ";
	cin >> name3;
	p3.setName(name3);
	cout << "Enter in the fourth Player's name: ";
	cin >> name4;
	p4.setName(name4);
	deck.shuffle();
	displayCards(deck);


	return 0;
}
