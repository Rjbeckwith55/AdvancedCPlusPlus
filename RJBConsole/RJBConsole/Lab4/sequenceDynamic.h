// FILE: sequenceDynamic.h
// CLASS PROVIDED: sequenceDynamic (part of the namespace main_savitch_4)
// There is no implementation file provided for this class since it is
// an exercise from Chapter 4 of "Data Structures and Other Objects Using C++"
//
// ALIASES and MEMBER CONSTANTS for the sequenceDynamic class:
//   alias ____ value_type
//     sequenceDynamic::value_type is the data type of the items in the sequenceDynamic. It
//     may be any of the C++ built-in types (int, char, etc.), or a class with a
//     default constructor, an assignment operator, and a copy constructor.
//
//   alias ____ size_type
//     sequenceDynamic::size_type is the data type of any variable that keeps track of
//     how many items are in a sequenceDynamic.
//
//   static const size_type DEFAULT_CAPACITY = _____
//     sequenceDynamic::DEFAULT_CAPACITY is the initial capacity of a sequenceDynamic that is
//     created by the default constructor.
//
// CONSTRUCTOR for the sequenceDynamic class:
//   sequenceDynamic(size_t initial_capacity = DEFAULT_CAPACITY)
//     Postcondition: The sequenceDynamic has been initialized as an empty sequenceDynamic.
//     The insert/attach functions will work efficiently (without allocating
//     new memory) until this capacity is reached.
//
// MODIFICATION MEMBER FUNCTIONS for the sequenceDynamic class:
//   void resize(size_type new_capacity)
//     Postcondition: The sequenceDynamic's current capacity is changed to the
//     new_capacity (but not less that the number of items already on the
//     list). The insert/attach functions will work efficiently (without
//     allocating new memory) until this new capacity is reached.
//
//   void start( )
//     Postcondition: The first item on the sequenceDynamic becomes the current item
//     (but if the sequenceDynamic is empty, then there is no current item).
//
//   void advance( )
//     Precondition: is_item returns true.
//     Postcondition: If the current item was already the last item in the
//     sequenceDynamic, then there is no longer any current item. Otherwise, the new
//     current item is the item immediately after the original current item.
//
//   void insert(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the sequenceDynamic
//     before the current item. If there was no current item, then the new entry
//     has been inserted at the front of the sequenceDynamic. In either case, the newly
//     inserted item is now the current item of the sequenceDynamic.
//
//   void attach(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the sequenceDynamic after
//     the current item. If there was no current item, then the new entry has
//     been attached to the end of the sequenceDynamic. In either case, the newly
//     inserted item is now the current item of the sequenceDynamic.
//
//   void remove_current( )
//     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the sequenceDynamic, and the
//     item after this (if there is one) is now the new current item.
//
// CONSTANT MEMBER FUNCTIONS for the sequenceDynamic class:
//   size_type size( ) const
//     Postcondition: The return value is the number of items in the sequenceDynamic.
//
//   bool is_item( ) const
//     Postcondition: A true return value indicates that there is a valid
//     "current" item that may be retrieved by activating the current
//     member function (listed below). A false return value indicates that
//     there is no valid current item.
//
//   value_type current( ) const
//     Precondition: is_item( ) returns true.
//     Postcondition: The item returned is the current item in the sequenceDynamic.
//
// VALUE SEMANTICS for the sequenceDynamic class:
//    Assignments and the copy constructor may be used with sequenceDynamic objects.
//
// DYNAMIC MEMORY USAGE by the List
//   If there is insufficient dynamic memory, then the following functions
//   throw a BAD_ALLOC exception: The constructors, insert, attach.

#ifndef MAIN_SAVITCH_sequenceDynamic_H
#define MAIN_SAVITCH_sequenceDynamic_H
#include <cstdlib>  // Provides size_t

class sequenceDynamic
{
public:
    // ALIAS and MEMBER CONSTANTS
    using value_type = double;
    using size_type = std::size_t;
    static const size_type DEFAULT_CAPACITY = 30;
    // CONSTRUCTORS and DESTRUCTOR
    sequenceDynamic(size_type initial_capacity = DEFAULT_CAPACITY);
    sequenceDynamic(const sequenceDynamic& source);
	~sequenceDynamic( );
    // MODIFICATION MEMBER FUNCTIONS
void resize(size_type new_capacity);
    void start( );
    void advance( );
    void insert(const value_type& entry);
    void attach(const value_type& entry);
    void remove_current( );
    void operator =(const sequenceDynamic& source);
	void operator +=(const sequenceDynamic& addend);
    // CONSTANT MEMBER FUNCTIONS
    size_type size( ) const;
    bool is_item( ) const;
    value_type current( ) const;
private:
    value_type* data;
    size_type used;
    size_type current_index;
	size_type capacity;
};
	
sequenceDynamic operator +(const sequenceDynamic& s1, const sequenceDynamic& s2); // added this overloaded operator

#endif

