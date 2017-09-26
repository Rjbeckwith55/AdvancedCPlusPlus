/*Author: Robert Beckwith
Date: 9/12/17
Class: CIS 2542
File: Card.h
Description:
			Specification file for the Card class*/

#include <iostream>
#include <ostream>
#include <string>
using namespace std;

#ifndef card_H
#define card_H

class Card {
private:
	//int to store the value of the suit and rank
	int suit;
	int rank;
	//enumerated types used for suits and ranks

public:
	enum suits { clubs = 1, diamonds, hearts, spades };
	enum ranks { two = 2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace };
	Card(int, int); //test parameterized constructor
	Card(); // default constructor

	// getters and setters
	void setSuit(int);
	void setRank(int);
	int getSuit() const { return suit; }
	int getRank() const { return rank; }


	// operator overloading as a friend function
	friend ostream& operator <<(ostream&, const Card&);
	friend int operator +(const int&, const Card&);

	//operator overloading as a member function
	int operator +(const int&);
	int operator +(const Card&);

};


#endif