/*Author: Robert Beckwith
Date: 9/12/17
Class: CIS 2542
File: Card.h
Description:
			Specification file for the Card class*/
#include <iostream>
#include <ostream>
using namespace std;


class Card {
private:
	int suit;
	int rank;
	enum suits { clubs, diamonds, hearts, spades };
	enum ranks { two = 1, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace };
public:
	Card(int, int);
	//Card(); // default constructor
	void setSuit(int);
	void setRank(int);
	int getSuit() const { return suit; }
	int getRank() const { return rank; }

	// operator overloading as a member function
	friend ostream& operator <<(ostream&, const Card&);

};