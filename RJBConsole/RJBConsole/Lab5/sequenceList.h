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

