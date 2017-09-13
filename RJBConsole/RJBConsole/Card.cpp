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
	switch (s) {
	case suits::diamonds:
		suit = static_cast<int>(suits::diamonds);
	case suits::clubs:
		suit = static_cast<int>(suits::clubs);
	case suits::hearts:
		suit = static_cast<int>(suits::hearts);
	case suits::spades:
		suit = static_cast<int>(suits::spades);
	}


}


void Card::setRank(int r) {
	switch (r) {
	case ranks::ace:
		rank = static_cast<int>(ranks::ace);
	}
}

ostream& operator <<(ostream& lhs, const Card& c) {
	lhs << "Card Rank: " << static_cast<Card::ranks>(c.rank) << "Card Suit: " << static_cast<Card::suits>(c.suit) << "Card's Value: " << c.rank << endl;
	return lhs;

}