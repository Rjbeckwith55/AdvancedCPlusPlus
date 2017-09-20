/*Author: Robert Beckwith
Date: 9/12/17
Class: CIS 2542
File: Card.cpp
Description:
	Implementation file for the Card class*/

#include "Card.h"
Card::Card(int s, int r) {
	suit = s;
	rank = r;
}
void Card::setSuit(int s) {
	suit = s;

}

void Card::setRank(int r) {
	rank = r;
}


// overloaded + for Card and int
int Card::operator +(const int& rhs) {
	return rank + rhs;
}
// overloaded + for Card and Card
int Card::operator +(const Card& rhs) {
	return rank + rhs.getRank();
}
// overloaded + for int and Card
int operator +(const int& lhs, const Card& rhs) {
	return lhs + rhs.rank;
}

// Output the card rank and the card suit
ostream& operator <<(ostream& lhs, const Card& c) {

	lhs << "Card Rank: " << static_cast<Card::ranks>(c.rank) << "Card Suit: ";
	//Giant switch case to print out the rank for the card based on the rank of the specific card
	switch (c.rank) {
	case Card::ranks::two:
		lhs << "Two";
		break;
	case Card::ranks::three:
		lhs << "Three";
		break;
	case Card::ranks::four:
		lhs << "Four";
		break;
	case Card::ranks::five:
		lhs << "Five";
		break;
	case Card::ranks::six:
		lhs << "Six";
		break;
	case Card::ranks::seven:
		lhs << "Seven";
		break;
	case Card::ranks::eight:
		lhs << "Eight";
		break;
	case Card::ranks::nine:
		lhs << "Nine";
		break;
	case Card::ranks::ten:
		lhs << "Ten";
		break;
	case Card::ranks::jack:
		lhs << "Jack";
		break;
	case Card::ranks::queen:
		lhs << "Queen";
		break;
	case Card::ranks::king:
		lhs << "King";
		break;
	case Card::ranks::ace:
		lhs << "Ace5";
		break;
	}
	//switch case to print out the suit for the card based on the suit of the specific card
	switch (c.suit) {
	case Card::suits::diamonds:
		lhs << "Diamonds ";
		break;
	case Card::suits::clubs:
		lhs << "Clubs ";
		break;
	case Card::suits::hearts:
		lhs << "Hearts ";
		break;
	case Card::suits::spades:
		lhs << "Spades ";
		break;
	}
	lhs << "Card's Value: " << c.rank << endl;
	return lhs;

}
