// Robert Beckwith
//10/5/17
//CIS 2542
//FILE: sequenceTemp.h
// CLASS PROVIDED: nodeTemp
// This is the header file for the project described in Section 5.4
// of "Data Structures and Other Objects Using C++"
// This is called "sequenceTemp" because some students already implemented
// sequenceFixed (with a fixed array) and sequenceDynamic (with a dynamic array).
//
// ALIASES and MEMBER CONSTANTS for the sequenceTemp class:
//   alias ____ value_type
//     sequenceTemp::value_type is the data type of the items in the sequenceTemp. It
//     may be any of the C++ built-in types (int, char, etc.), or a class with a
//     default constructor, an assignment operator, and a copy constructor.
//
//   alias ____ size_type
//     sequenceTemp::size_type is the data type of any variable that keeps track of
//     how many items are in a sequenceTemp.
//
// CONSTRUCTOR for the sequenceTemp class:
//   sequenceTemp( )
//     Postcondition: The sequenceTemp has been initialized as an empty sequenceTemp.
//
// MODIFICATION MEMBER FUNCTIONS for the sequenceTemp class:
//   void start( )
//     Postcondition: The first item on the sequenceTemp becomes the current item
//     (but if the sequenceTemp is empty, then there is no current item).
//
//   void advance( )
//     Precondition: is_item returns true.
//     Postcondition: If the current item was already the last item in the
//     sequenceTemp, then there is no longer any current item. Otherwise, the new
//     current item is the item immediately after the original current item.
//
//   void insert(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the sequenceTemp
//     before the current item. If there was no current item, then the new entry
//     has been inserted at the front of the sequenceTemp. In either case, the newly
//     inserted item is now the current item of the sequenceTemp.
//
//   void attach(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the sequenceTemp after
//     the current item. If there was no current item, then the new entry has
//     been attached to the end of the sequenceTemp. In either case, the newly
//     inserted item is now the current item of the sequenceTemp.
//
//   void remove_current( )
//     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the sequenceTemp, and
//     the item after this (if there is one) is now the new current item.
//
// CONSTANT MEMBER FUNCTIONS for the sequenceTemp class:
//   size_type size( ) const
//     Postcondition: The return value is the number of items in the sequenceTemp.
//
//   bool is_item( ) const
//     Postcondition: A true return value indicates that there is a valid
//     "current" item that may be retrieved by activating the current
//     member function (listed below). A false return value indicates that
//     there is no valid current item.
//
//   value_type current( ) const
//     Precondition: is_item( ) returns true.
//     Postcondition: The item returned is the current item in the sequenceTemp.
//
// VALUE SEMANTICS for the sequenceTemp class:
//    Assignments and the copy constructor may be used with sequenceTemp objects.

#ifndef MAIN_SAVITCH_sequenceTemp_H
#define MAIN_SAVITCH_sequenceTemp_H
#include <cstdlib>  // Provides size_t
#include <cassert>  // Provides assert
#include "nodeTemplate.h"  // Provides node class

template<class Item>
class sequenceTemp
{
public:
	// ALIASES and MEMBER CONSTANTS
	using value_type = Item;
	using size_type = std::size_t;
	// CONSTRUCTORS and DESTRUCTOR
	sequenceTemp();
	sequenceTemp(const sequenceTemp& source);
	~sequenceTemp();
	// MODIFICATION MEMBER FUNCTIONS
	void start();
	void advance();
	void insert(const Item& entry);
	void attach(const Item& entry);
	void operator =(const sequenceTemp& source);
	void remove_current();
	// CONSTANT MEMBER FUNCTIONS
	size_type size() const { return many_nodes; }
	bool is_item() const { return (cursor != nullptr); }
	Item current() const;
private:
	nodeTemplate<Item> *head_ptr;
	nodeTemplate<Item> *tail_ptr;
	nodeTemplate<Item> *cursor;
	nodeTemplate<Item> *precursor;
	size_type many_nodes;
};

#endif

// utility function to create a new list from section of an existing list
// Precondition: start_ptr and end_ptr are pointers to nodes on the same
// linked list, with the start_ptr node at or before the end_ptr node.
// Postcondition: head_ptr and tail_ptr are the head and tail pointers
// for a new list that contains the items from start_ptr up to but
// not including end_ptr.  The end_ptr may also be nullptr, in which case
// the new list contains elements from start_ptr to the end of the list.
// Library facilities used: cstdlib
template<class Item>
void list_piece(const nodeTemplate<Item>* start_ptr, const nodeTemplate<Item>* end_ptr, nodeTemplate<Item>*& head_ptr, 
	nodeTemplate<Item>*& tail_ptr) {

	head_ptr = nullptr;
	tail_ptr = nullptr;

	// Handle the case of the empty list.
	if (start_ptr == end_ptr)
		return;

	// Make the head node for the newly created list, and put data in it.
	list_head_insert(head_ptr, start_ptr->data());
	tail_ptr = head_ptr;

	// Copy the rest of the nodes one at a time, adding at the tail of new list.
	start_ptr = start_ptr->link();
	while (start_ptr != end_ptr)
	{
		list_insert(tail_ptr, start_ptr->data());
		tail_ptr = tail_ptr->link();
		start_ptr = start_ptr->link();
	}
}

// default constructor
template<class Item>
sequenceTemp<Item>::sequenceTemp() {
	head_ptr = tail_ptr = cursor = precursor = nullptr;
	many_nodes = 0;
}

// copy constructor ==>TO COMPLETE FOR LAB

template<class Item>
sequenceTemp<Item>::sequenceTemp(const sequenceTemp& source) {
	if (source.cursor == nullptr)
	{   // There is no current item in the source list:
		list_copy(source.head_ptr, head_ptr, tail_ptr);
		cursor = precursor = nullptr;
	}
	else if (source.precursor == nullptr)
	{   // The current item in the source is at its head:
		list_copy(source.head_ptr, head_ptr, tail_ptr);
		cursor = head_ptr;
		precursor = nullptr;
	}
	else
	{   // The current item in the source is not at its head:
		list_piece(source.head_ptr, source.cursor, head_ptr, precursor);
		list_piece(source.cursor, static_cast<nodeTemplate<Item>*>(nullptr), cursor, tail_ptr);
		precursor->set_link(cursor);
	}
	many_nodes = source.many_nodes;
}

// the destructor
template<class Item>
sequenceTemp<Item>::~sequenceTemp() {
	list_clear(head_ptr);
	many_nodes = 0;
}

// method to set cursor to beginning of list
template<class Item>
void sequenceTemp<Item>::start() {
	precursor = nullptr;
	cursor = head_ptr;
}

// method to advance cursor
template<class Item>
void sequenceTemp<Item>::advance() {
	assert(is_item());
	precursor = cursor;
	cursor = cursor->link();
	if (cursor == nullptr)
		precursor = nullptr;
}

// method to insert item before cursor
template<class Item>
void sequenceTemp<Item>::insert(const Item& entry) {
	if (precursor == nullptr)
	{   // The new entry goes at the front:
		list_head_insert(head_ptr, entry);
		cursor = head_ptr;
		if (tail_ptr == nullptr)
			tail_ptr = head_ptr; // There were no other nodes.
	}
	else
	{   // The new entry goes between precursor and cursor,
		// and the cursor is set to point at this new entry.
		list_insert(precursor, entry);
		cursor = precursor->link();
	}
	++many_nodes;
}

// method to attach item after cursor ==>TO COMPLETE FOR LAB
template<class Item>
void sequenceTemp<Item>::attach(const Item& entry) {
	if (tail_ptr == nullptr)
		insert(entry); // First node of the list
	else if (cursor == nullptr)
	{   // The new entry goes after the current tail:
		list_insert(tail_ptr, entry);
		precursor = tail_ptr;
		cursor = tail_ptr = precursor->link();
		++many_nodes;
	}
	else
	{   // The new entry goes after the current cursor:
		list_insert(cursor, entry);
		precursor = cursor;
		cursor = precursor->link();
		if (tail_ptr == precursor)
			tail_ptr = cursor;
		++many_nodes;
	}
}

// method to remove item at cursor ==>TO COMPLETE FOR LAB
template<class Item>
void sequenceTemp<Item>::remove_current() {
	assert(is_item());
	if (cursor == head_ptr)
	{   // Remove the front node:
		list_head_remove(static_cast<nodeTemplate<Item>*>(head_ptr));
		cursor = head_ptr;
		if (cursor == nullptr)
			tail_ptr = nullptr; // No more nodes on the list.
	}
	else
	{   // Remove a node that is not at the head:
		list_remove(precursor);
		cursor = precursor->link();
		if (cursor == nullptr)
		{   // We just removed the old tail node:
			tail_ptr = precursor;
			precursor = nullptr;
		}
	}
	--many_nodes;
}

// overloaded = assignment operator ==>TO COMPLETE FOR LAB
template<class Item>
void sequenceTemp<Item>::operator =(const sequenceTemp<Item>& source) {
	if (this == &source)
		return;

	list_clear(head_ptr);
	if (source.cursor == nullptr)
	{   // There is no current item in the source list:
		list_copy(source.head_ptr, head_ptr, tail_ptr);
		cursor = precursor = nullptr;
	}
	else if (source.precursor == nullptr)
	{   // The current item in the source is at its head:
		list_copy(source.head_ptr, head_ptr, tail_ptr);
		cursor = head_ptr;
		precursor = nullptr;
	}
	else
	{   // The current item in the source is not at its head:
		list_piece(source.head_ptr, source.cursor, head_ptr, precursor);
		list_piece(source.cursor, static_cast<nodeTemplate<Item>*>(nullptr), cursor, tail_ptr);
		precursor->set_link(cursor);
	}
	many_nodes = source.many_nodes;
}

// method to return item at cursor
template<class Item>
Item sequenceTemp<Item>::current() const {
	assert(is_item());
	return cursor->data();
}

/*==========>TEST RESULTS<==========
If you submit this sequenceTemp class now, you will have
30 points out of the 30 points from this test program.
==========>POINT SUMMARY<==========
Testing insert, attach, and the constant member functions
        POINTS = 5 out of 5
Testing situations where the cursor goes off the sequenceTemp
        POINTS = 5 out of 5
Testing remove_current
        POINTS = 5 out of 5
Testing the copy constructor
        POINTS = 5 out of 5
Testing the assignment operator
        POINTS = 5 out of 5
Testing insert/attach for somewhat larger sequenceTemps
        POINTS = 5 out of 5
Press any key to continue . . .*/
