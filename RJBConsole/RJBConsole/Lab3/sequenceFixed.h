// FILE: sequenceFixed.h
// CLASS PROVIDED: sequenceFixed 
//
// TYPEDEFS and MEMBER CONSTANTS for the sequenceFixed class:
//   alias ____ value_type
//     sequenceFixed::value_type is the data type of the items in the sequenceFixed. It
//     may be any of the C++ built-in types (int, char, etc.), or a class with a
//     default constructor, an assignment operator, and a copy constructor.
//
//   alias ____ size_type
//     sequenceFixed::size_type is the data type of any variable that keeps track of
//     how many items are in a sequenceFixed.
//
//   static const size_type CAPACITY = _____
//     sequenceFixed::CAPACITY is the maximum number of items that a sequenceFixed can hold.
//
// CONSTRUCTOR for the sequenceFixed class:
//   sequenceFixed( )
//     Postcondition: The sequenceFixed has been initialized as an empty sequenceFixed.
//
// MODIFICATION MEMBER FUNCTIONS for the sequenceFixed class:
//   void start( )
//     Postcondition: The first item on the sequenceFixed becomes the current item
//     (but if the sequenceFixed is empty, then there is no current item).
//
//   void advance( )
//     Precondition: is_item returns true.
//     Postcondition: If the current item was already the last item in the
//     sequenceFixed, then there is no longer any current item. Otherwise, the new
//     current item is the item immediately after the original current item.
//
//   void insert(const value_type& entry)
//     Precondition: size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been inserted in the sequenceFixed
//     before the current item. If there was no current item, then the new entry 
//     has been inserted at the front of the sequenceFixed. In either case, the newly
//     inserted item is now the current item of the sequenceFixed.
//
//   void attach(const value_type& entry)
//     Precondition: size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been inserted in the sequenceFixed after
//     the current item. If there was no current item, then the new entry has 
//     been attached to the end of the sequenceFixed. In either case, the newly
//     inserted item is now the current item of the sequenceFixed.
//
//   void remove_current( )
//     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the sequenceFixed, and the
//     item after this (if there is one) is now the new current item.
//
// CONSTANT MEMBER FUNCTIONS for the sequenceFixed class:
//   size_type size( ) const
//     Postcondition: The return value is the number of items in the sequenceFixed.
//
//   bool is_item( ) const
//     Postcondition: A true return value indicates that there is a valid
//     "current" item that may be retrieved by activating the current
//     member function (listed below). A false return value indicates that
//     there is no valid current item.
//
//   value_type current( ) const
//     Precondition: is_item( ) returns true.
//     Postcondition: The item returned is the current item in the sequenceFixed.
//
// VALUE SEMANTICS for the sequenceFixed class:
//    Assignments and the copy constructor may be used with sequenceFixed objects.

// Taken from Data Structures and Other Objects 
// Using C++ by Michael Main and Walter Savitch

#ifndef MAIN_SAVITCH_sequenceFixed_H
#define MAIN_SAVITCH_sequenceFixed_H
#include <cstdlib>  // Provides size_t


class sequenceFixed
{
public:
    // aliases and MEMBER CONSTANTS
    using value_type = double;
    using size_type = std::size_t;
	static const size_type CAPACITY = 30;

    // CONSTRUCTOR  
    sequenceFixed( );

    // MODIFICATION MEMBER FUNCTIONS
    void start( );
    void advance( );
    void insert(const value_type& entry);
    void attach(const value_type& entry);
    void remove_current( );

    // CONSTANT MEMBER FUNCTIONS
    size_type size( ) const;
    bool is_item( ) const;
    value_type current( ) const;

private:
	// relevant items in data[0] to data[used-1]
    value_type data[CAPACITY];
	// number of items stored
    size_type used;
	// current item's reference
    size_type current_index;
};
#endif

