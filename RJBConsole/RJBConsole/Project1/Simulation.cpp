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
	Card c;
	string name1,name2,name3,name4;
	name1 = "Player 1";
	name2 = "Player 2";
	name3 = "Player 3";
	name4 = "Player 4";

	/*cout << "Enter in the first Player's name: ";
	cin >> name1;
	p1.setName(name1);
	cout << "Enter in the second Player's name: ";
	cin >> name2;
	p2.setName(name2);
	cout << "Enter in the third Player's name: ";
	cin >> name3;
	cout << "Enter in the fourth Player's name: ";
	cin >> name4;*/

	p1.setName(name1);
	p2.setName(name2);
	p3.setName(name3);
	p4.setName(name4);
	deck.shuffle();
	//display all the cards in the deck
	displayCards(deck);

	// Needs a linked list that will pick a random link and will discard a card for each one.
	p1.deal(p1, p2, p3, p4, deck);
	cout << p1.getName()<<"'s hand"<<endl;
	showHand(p1);
	cout << p1.getName() << "'s hand" << getValue(p1) << endl;
	cout << "Player two's hand: " << endl;
	showHand(p2);
	cout << "Player three's hand: " << endl;
	showHand(p3);
	cout << "Player four's hand: " << endl;
	showHand(p4);
	cout << "Discard 4 cards" << endl;

	c = discard(p1);
	cout << c;
	c = discard(p2);
	cout << c;
	c = discard(p3);
	cout << c;
	c = discard(p4);
	cout << c;

	return 0;
}
