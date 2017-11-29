/*
	Name: Robert Beckwith
	Class: CIS 2542
	Date: 11/29/17
	File:   tableMultiChain.h
	Descr:
	Derived template class (from tableChain) to allow multiple hash keys
	with different data values.
*/
#ifndef tableMultiChain_H
#define tableMultiChain_H
#include <cstdlib>    // Provides size_t
#include "hashNode.h"    // Provides the hashNode struct and toolkit
#include "tableChain.h"  // Provides base hash table class with chaining

// derived template class
template <class RecordType>
class tableMultiChain : public tableChain <RecordType> {
public:
	// override since duplicates allowed
	// add entry at *end* of duplicate keys
	void insert(const RecordType& entry); // appended to the location of the current duplicates 
	// additional method to count number of entries for given key
	std::size_t count(int key) const;
	// additional method to display all entries for given key
	void display_key_values(int key) const;
	// additional method to remove all entries for given key
	void remove_all(int key);
};

// ***ADD METHOD DEFINITIONS HERE***

#endif

template<class RecordType>
void tableMultiChain<RecordType>::insert(const RecordType & entry)
{
	hashNode<RecordType>* cursor; // set to point to existing hashNode with given key
	hashNode<RecordType>* precursor;
	assert(entry.key >= 0);

	// Set cursor to point to existing hashNode with given key (if there is one)
	cursor = find_node(entry.key); // finds the first node

	if (cursor != nullptr)
	{
		while (cursor != nullptr && (cursor->data).key == entry.key) {
			precursor = cursor;
			cursor = cursor->link; // traverse until it doesn't equal it
		}
		if (cursor == nullptr) {
			hashNode<RecordType>* cursor = new hashNode<RecordType>();
			precursor->link = cursor;
			cursor->data = entry;
			total_records++;
		}
		else {
			list_insert(precursor, entry);
			total_records++;
		}


	}
	else
	{   // Add in a new spot
		list_head_insert(data[hash(entry.key)], entry);
		total_records++;

	}
}

template<class RecordType>
std::size_t tableMultiChain<RecordType>::count(int key) const
{
	hashNode<RecordType>* cursor;
	cursor = find_node(key);
	size_t count = 0;

	while (cursor != nullptr && (cursor->data).key == key) {
		cursor = cursor->link; // traverse until it doesn't equal it
		count++;
	}
	return count;
}

template<class RecordType>
void tableMultiChain<RecordType>::display_key_values(int key) const
{
	hashNode<RecordType>* cursor;
	cursor = find_node(key);
	size_t count = 0;

	while (cursor != nullptr && (cursor->data).key == key) {// traverse until it doesn't equal it
		cout <<"\t"<< cursor->data << endl;
		cursor = cursor->link;
	}
}

template<class RecordType>
inline void tableMultiChain<RecordType>::remove_all(int key)
{
	hashNode<RecordType> *cursor;    // Points to existing hashNode with given key
	hashNode<RecordType> *precursor; // Points to hashNode before the cursor

	assert(key >= 0);

	// Set cursor to point to existing hashNode with given key (if there is one)
	cursor = data[hash(key)];
	precursor = nullptr;
	while ((cursor != nullptr) && ((cursor->data).key != key))
	{
		precursor = cursor;
		cursor = cursor->link;
	}

	if ((cursor != nullptr) && (precursor != nullptr))
	{   // Remove the cursor hashNode
		//loop through and remove the elements
		while ((cursor != nullptr) && ((cursor->data).key == key)) {
			list_remove(precursor);
			total_records--;
			cursor = precursor->link;
		}

	}
	else if (cursor != nullptr)
	{   // Cursor points to head, so remove head
		while ((cursor != nullptr) && ((cursor->data).key == key)) {
			list_head_remove(cursor);
			total_records--;
			precursor = cursor;
			cursor = cursor->link;
		}

	}
}

/*The table size is 9

***DISPLAY ALL TABLE ENTRIES***
Index = 1
        KEY=1623 DATA=11
        KEY=1 DATA=11.1
        KEY=1 DATA=11.2
        KEY=1 DATA=11.3
        KEY=5678 DATA=99
Index = 2
        KEY=2435 DATA=22
        KEY=2 DATA=22.1
        KEY=2 DATA=22.2
Index = 3
        KEY=3 DATA=33.1

The number of entries with KEY=1 is 3
        KEY=1 DATA=11.1
        KEY=1 DATA=11.2
        KEY=1 DATA=11.3

The number of entries with KEY=2 is 2
        KEY=2 DATA=22.1
        KEY=2 DATA=22.2

The number of entries with KEY=3 is 1
        KEY=3 DATA=33.1


Removing one element with KEY=2
The table size is 8

***DISPLAY ALL TABLE ENTRIES***
Index = 1
        KEY=1623 DATA=11
        KEY=1 DATA=11.1
        KEY=1 DATA=11.2
        KEY=1 DATA=11.3
        KEY=5678 DATA=99
Index = 2
        KEY=2435 DATA=22
        KEY=2 DATA=22.2
Index = 3
        KEY=3 DATA=33.1


Removing all elements with KEY=1
The table size is 5

***DISPLAY ALL TABLE ENTRIES***
Index = 1
        KEY=1623 DATA=11
        KEY=5678 DATA=99
Index = 2
        KEY=2435 DATA=22
        KEY=2 DATA=22.2
Index = 3
        KEY=3 DATA=33.1

The number of entries with KEY=1 is 0

The number of entries with KEY=2 is 1
        KEY=2 DATA=22.2

The number of entries with KEY=3 is 1
        KEY=3 DATA=33.1
Press any key to continue . . .*/