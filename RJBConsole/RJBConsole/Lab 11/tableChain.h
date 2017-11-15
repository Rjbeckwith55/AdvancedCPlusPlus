// FILE: tableChain.h
// TEMPLATE CLASS PROVIDED: tableChain<RecordType>
//   This class is a container template class for a Table of records.
//   The template parameter, RecordType, is the data type of the records in the
//   Table. It may any type with a default constructor, a copy constructor,
//   an assignment operator, and an integer member variable called key.
//
// CONSTRUCTOR for the tableChain<RecordType> template class:
//   tableChain( )
//     Postcondition: The Table has been initialized as an empty Table.
//
// MODIFICATION MEMBER FUNCTIONS for the tableChain<RecordType> class:
//   void insert(const RecordType& entry)
//     Precondition: entry.key >= 0. Also if entry.key is not already a key in
//     the table, then the Table has space for another record
//     (i.e., size( ) < CAPACITY).
//     Postcondition: If the table already had a record with a key equal to
//     entry.key, then that record is replaced by entry. Otherwise, entry has
//     been added as a new record of the Table.
//
//   void remove(int key)
//     Postcondition: If a record was in the Table with the specified key, then
//     that record has been removed; otherwise the table is unchanged.
//
// CONSTANT MEMBER FUNCTIONS for the tableChain<RecordType> class:
//   bool is_present(const Item& target) const
//     Postcondition: The return value is true if there is a record in the
//     Table with the specified key. Otherwise, the return value is false.
//
//   void find(int key, bool& found, RecordType& result) const
//     Postcondition: If a record is in the Table with the specified key, then
//     found is true and result is set to a copy of the record with that key.
//     Otherwise found is false and the result contains garbage.
//
//   size_t size( ) const
//     Postcondition: Return value is the total number of records in the
//     Table.
//
// VALUE SEMANTICS for the tableChain<RecordType> template class:
//   Assignments and the copy constructor may be used with Table objects.
//
// DYNAMIC MEMORY USAGE by the tableChain<RecordType> template class:
//   If there is insufficient dynamic memory, then the following functions
//   can call new_handler: the copy constructor, insert, the assignment
//   operator.

#ifndef tableChain_H
#define tableChain_H
#include <cstdlib>    // Provides size_t
#include "hashNode.h"    // Provides the hashNode struct and toolkit

template <class RecordType>
class tableChain
{
public:
	// MEMBER CONSTANT -- See Appendix E if this fails to compile.
	static const std::size_t TABLE_SIZE = 811;
	// CONSTRUCTORS AND DESTRUCTOR
	tableChain();
	tableChain(const tableChain& source);
	~tableChain();
	// MODIFICATION MEMBER FUNCTIONS
	void insert(const RecordType& entry);
	void remove(int key);
	void operator =(const tableChain& source);
	// CONSTANT MEMBER FUNCTIONS
	void find(int key, bool& found, RecordType& result) const;
	bool is_present(int key) const;
	std::size_t size() const { return total_records; }
	// ***DISPLAY Member function***
	void display_all();
private:
	hashNode<RecordType> *data[TABLE_SIZE];
	std::size_t total_records;
	// HELPER MEMBER FUNCTION
	std::size_t hash(int key) const;
	hashNode<RecordType>* find_node(int key) const;
};

#include "tableChain_template.h" // Include the implementation

#endif
