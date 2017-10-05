// FILE: sequenceList.h
// CLASS PROVIDED: sequenceList 
// This is the header file for the project described in Section 5.4
// of "Data Structures and Other Objects Using C++"
// This is called "sequenceList" because some students already implemented
// sequenceFixed (with a fixed array) and sequenceDynamic (with a dynamic array).
//
// ALIASES and MEMBER CONSTANTS for the sequenceList class:
//   alias ____ value_type
//     sequenceList::value_type is the data type of the items in the sequenceList. It
//     may be any of the C++ built-in types (int, char, etc.), or a class with a
//     default constructor, an assignment operator, and a copy constructor.
//
//   alias ____ size_type
//     sequenceList::size_type is the data type of any variable that keeps track of
//     how many items are in a sequenceList.
//
// CONSTRUCTOR for the sequenceList class:
//   sequenceList( )
//     Postcondition: The sequenceList has been initialized as an empty sequenceList.
//
// MODIFICATION MEMBER FUNCTIONS for the sequenceList class:
//   void start( )
//     Postcondition: The first item on the sequenceList becomes the current item
//     (but if the sequenceList is empty, then there is no current item).
//
//   void advance( )
//     Precondition: is_item returns true.
//     Postcondition: If the current item was already the last item in the
//     sequenceList, then there is no longer any current item. Otherwise, the new
//     current item is the item immediately after the original current item.
//
//   void insert(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the sequenceList
//     before the current item. If there was no current item, then the new entry
//     has been inserted at the front of the sequenceList. In either case, the newly
//     inserted item is now the current item of the sequenceList.
//
//   void attach(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the sequenceList after
//     the current item. If there was no current item, then the new entry has
//     been attached to the end of the sequenceList. In either case, the newly
//     inserted item is now the current item of the sequenceList.
//
//   void remove_current( )
//     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the sequenceList, and
//     the item after this (if there is one) is now the new current item.
//
// CONSTANT MEMBER FUNCTIONS for the sequenceList class:
//   size_type size( ) const
//     Postcondition: The return value is the number of items in the sequenceList.
//
//   bool is_item( ) const
//     Postcondition: A true return value indicates that there is a valid
//     "current" item that may be retrieved by activating the current
//     member function (listed below). A false return value indicates that
//     there is no valid current item.
//
//   value_type current( ) const
//     Precondition: is_item( ) returns true.
//     Postcondition: The item returned is the current item in the sequenceList.
//
// VALUE SEMANTICS for the sequenceList class:
//    Assignments and the copy constructor may be used with sequenceList objects.

#ifndef MAIN_SAVITCH_sequenceList_H
#define MAIN_SAVITCH_sequenceList_H
#include <cstdlib>  // Provides size_t
#include <cassert>  // Provides assert
#include "node.h"  // Provides node class

class sequenceList
{
public:
	// ALIASES and MEMBER CONSTANTS
	using value_type = node::value_type;
	using size_type = std::size_t;
	// CONSTRUCTORS and DESTRUCTOR
	sequenceList();
	sequenceList(const sequenceList& source);
	~sequenceList();
	// MODIFICATION MEMBER FUNCTIONS
	void start();
	void advance();
	void insert(const value_type& entry);
	void attach(const value_type& entry);
	void operator =(const sequenceList& source);
	void remove_current();
	// CONSTANT MEMBER FUNCTIONS
	size_type size() const { return many_nodes; }
	bool is_item() const { return (cursor != nullptr); }
	value_type current() const;
private:
	node *head_ptr;
	node *tail_ptr;
	node *cursor;
	node *precursor;
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
void list_piece(const node* start_ptr, const node* end_ptr, node*& head_ptr, 
	node*& tail_ptr) {

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
sequenceList::sequenceList() {
	head_ptr = tail_ptr = cursor = precursor = nullptr;
	many_nodes = 0;
}

// copy constructor ==>TO COMPLETE FOR LAB
sequenceList::sequenceList(const sequenceList& source) {
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
		list_piece(source.cursor, nullptr, cursor, tail_ptr);
		precursor->set_link(cursor);
	}
	many_nodes = source.many_nodes;
}

// the destructor
sequenceList::~sequenceList() {
	list_clear(head_ptr);
	many_nodes = 0;
}

// method to set cursor to beginning of list
void sequenceList::start() {
	precursor = nullptr;
	cursor = head_ptr;
}

// method to advance cursor
void sequenceList::advance() {
	assert(is_item());
	precursor = cursor;
	cursor = cursor->link();
	if (cursor == nullptr)
		precursor = nullptr;
}

// method to insert item before cursor
void sequenceList::insert(const value_type& entry) {
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
void sequenceList::attach(const value_type& entry) {
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
void sequenceList::remove_current() {
	assert(is_item());
	if (cursor == head_ptr)
	{   // Remove the front node:
		list_head_remove(head_ptr);
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
void sequenceList::operator =(const sequenceList& source) {
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
		list_piece(source.cursor, nullptr, cursor, tail_ptr);
		precursor->set_link(cursor);
	}
	many_nodes = source.many_nodes;
}

// method to return item at cursor
sequenceList::value_type sequenceList::current() const {
	assert(is_item());
	return cursor->data();
}

