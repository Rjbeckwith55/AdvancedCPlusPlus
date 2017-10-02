/*Author: Robert Beckwith
Date: 9/25/17
Class: CIS 2542
File: simulation.cpp
Description:
			Simulation program to pick a random player and discard the cards*/

#include "Player.h"
#include "node.h"


int main() {
	Player p1, p2, p3, p4;
	int k;
	Deck deck;
	Card c;
	const Player::size_type MIN_VALUE = 0, MAX_VALUE = 4;

	// generate a random seed off of time
	unsigned seed = time(0);
	srand(seed);
	Player::size_type random;

	// create the pointer nodes

	string name1, name2, name3, name4;
	name1 = "Player 1";
	name2 = "Player 2";
	name3 = "Player 3";
	name4 = "Player 4";
	p1.setName(name1);
	p2.setName(name2);
	p3.setName(name3);
	p4.setName(name4);
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

	// shuffle the deck
	deck.shuffle();
	//display all the cards in the deck
	displayCards(deck);



	// Needs a linked list that will pick a random link and will discard a card for each one.

	//Deal out the cards to each of the 4 players
	deal(p1, p2, p3, p4, deck);


	cout << p1.getName() << "'s hand" << endl;
	showHand(p1);
	cout << p1.getName() << "'s hand" << getValue(p1) << endl;
	cout << "Player two's hand: " << endl;
	showHand(p2);
	cout << "Player three's hand: " << endl;
	showHand(p3);
	cout << "Player four's hand: " << endl;
	showHand(p4);
	cout << "Discard 4 cards" << endl;

	for (size_t i = 0; i < Player::HAND_SIZE; i++)
	{
		node *start = new node;
		node *ptr1 = new node(p1);
		node *ptr2 = new node(p2);
		node *ptr3 = new node(p3);
		node *ptr4 = new node(p4);
		ptr1->set_link(ptr2);
		ptr2->set_link(ptr3);
		ptr3->set_link(ptr4);
		ptr4->set_link(ptr1);

		random = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
		switch (random) {
		case(0):
			start = ptr1;
			break;
		case(1):
			start = ptr2;
			break;
		case(2):
			start = ptr3;
			break;
		case(3):
			start = ptr4;
			break;
		}
		c = discard(start->data());
		cout << c;
		node *counter = nullptr;
		node *sentinelStart = start;
		while (counter != sentinelStart)
		{
			start = start->link();
			c = discard(start->data());
			cout << c;
			counter = start;
		}

	}
	return 0;
}
