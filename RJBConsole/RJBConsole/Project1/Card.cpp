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
	switch (r) {
	case ranks::ace:
		rank = static_cast<int>(ranks::ace);
	}
}

ostream& operator <<(ostream& lhs, const Card& c) {
	
	lhs << "Card Rank: " << static_cast<Card::ranks>(c.rank) << "Card Suit: ";
	switch (c.rank) {
	case Card::ranks::two:
		lhs << "Two";
		break;
	}
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
