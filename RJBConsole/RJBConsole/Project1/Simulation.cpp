/*Author: Robert Beckwith
Date: 9/25/17
Class: CIS 2542
File: simulation.cpp
Description:
			Simulation program to pick a random player and discard the cards*/

#include "Player.h"
#include "node.h"


int main() {
	string x; // variable to pause at the end -- has value or purpose besides to put into cin
	string name1, name2, name3, name4; // local variables to hold the player names
	Player p1, p2, p3, p4;
	int k;
	Deck deck;
	Card c;
	const Player::size_type MIN_VALUE = 0, MAX_VALUE = 3; // Variables used for the random function

	// generate a random seed off of time
	unsigned seed = time(0);
	srand(seed);
	Player::size_type random;

	


	
	name1 = "Player 1";
	name2 = "Player 2";
	name3 = "Player 3";
	name4 = "Player 4";
	p1.setName(name1);
	p2.setName(name2);
	p3.setName(name3);
	p4.setName(name4);

	//uncomment below for player input names
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


	//Deal out the cards to each of the 4 players
	deal(p1, p2, p3, p4, deck);

	// create the pointer nodes
	node *start = new node;
	node *ptr1 = new node(p1);
	node *ptr2 = new node(p2);
	node *ptr3 = new node(p3);
	node *ptr4 = new node(p4);
	ptr1->set_link(ptr2);
	ptr2->set_link(ptr3);
	ptr3->set_link(ptr4);
	ptr4->set_link(ptr1);

	//Display player names and their cards
	cout << p1.getName() << "'s hand" << endl;
	showHand(p1);
	cout << p2.getName() << "'s hand" << endl;
	showHand(p2);
	cout << p3.getName() << "'s hand" << endl;
	showHand(p3);
	cout << p4.getName() << "'s hand" << endl;
	showHand(p4);

	//Display all the hand values
	cout << p1.getName() << "'s hand value: " << getValue(ptr1->data()) << endl;
	cout << p2.getName() << "'s hand value: " << getValue(ptr2->data()) << endl;
	cout << p3.getName() << "'s hand value: " << getValue(ptr3->data()) << endl;
	cout << p4.getName() << "'s hand value: " << getValue(ptr4->data()) << endl;


	cout << "***Discard 4 cards: ***" << endl;

	for (size_t i = 0; i < Player::HAND_SIZE; i++)
	{
		Player tempP; // declare a temp player for passing to discard

		random = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE; // generate a random from 0 to 3

		//set the start pointer of the list to one of the pointers based on the random number
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
		// keep the starting value of the linked list
		node *sentinelStart = start;
		//current value of the linked list
		node *counter = nullptr; 
		while (counter != sentinelStart)
		{
			tempP = start->data(); // set the player object to the temp player
			c = discard(tempP); // pass the temporary player to the function so it can be modified
			start->set_data(tempP); // set the pointer data to the modified player from the discard function
			cout << start->data().getName()<<" Discards the ";
			cout << c;
			start = start->link(); // progress down the list
			counter = start;
		}
		cout << p1.getName() << "'s hand value: " << getValue(ptr1->data()) << endl;
		cout << p2.getName() << "'s hand value: " << getValue(ptr2->data()) << endl;
		cout << p3.getName() << "'s hand value: " << getValue(ptr3->data()) << endl;
		cout << p4.getName() << "'s hand value: " << getValue(ptr4->data()) << endl;

		//Pause the game
		cout << "Press any key and enter to continue playing: ";
		cin >> x;
	}
	return 0;
}
