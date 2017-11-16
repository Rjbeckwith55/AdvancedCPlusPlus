// FILE: tableChain_template.h
// Written by: Michael Main (main@colorado.edu)
// TEMPLATE CLASS IMPLEMENTED: Table (see tableChain.h for documentation)
// INVARIANT for the Table ADT:
//   1. The number of records in the Table is in the member variable
//      total_records.
//   2. The actual records of the table are stored in a chained hash table.
//      An entry with key i is stored on the linked list with the head
//      pointer at data[hash(i)].

#include <cassert> // Provides assert
#include <cstdlib> // Provides size_t
#include "hashNode.h"  // Provides the hashNode struct and toolkit
#include "tableChain.h"

template <class RecordType>
tableChain<RecordType>::tableChain()
// Library facilities used: cstdlib
{
	size_t i;

	total_records = 0;
	for (i = 0; i < TABLE_SIZE; i++)
		data[i] = nullptr;
}

template <class RecordType>
tableChain<RecordType>::tableChain(const tableChain<RecordType>& source)
// Library facilities used: hashNode.h, cstdlib 
{
	size_t i;
	hashNode<RecordType>* tail_ptr; // Needed for list_copy

	for (i = 0; i < TABLE_SIZE; i++)
		list_copy(source.data[i], data[i], tail_ptr);
	total_records = source.total_records;
}

template <class RecordType>
tableChain<RecordType>::~tableChain()
// Library facilities used: hashNode.h
{
	size_t i;

	total_records = 0;
	for (i = 0; i < TABLE_SIZE; i++)
		list_clear(data[i]);
}

template <class RecordType>
void tableChain<RecordType>::insert(const RecordType& entry)
// Library facilities used: cassert, hashNode.h
{
	hashNode<RecordType>* cursor; // set to point to existing hashNode with given key

	assert(entry.key >= 0);

	// Set cursor to point to existing hashNode with given key (if there is one)
	cursor = find_node(entry.key);
	if (cursor != nullptr)
	{   // Add in existing spot
		cursor->data = entry;
	}
	else
	{   // Add in a new spot
		list_head_insert(data[hash(entry.key)], entry);
		total_records++;
	}
}

template <class RecordType>
void tableChain<RecordType>::remove(int key)
// Library facilities used: cassert, hashNode.h
{
	// TO BE IMPLEMENTED
	// See tableChain.h for description
	//Remove the element from the chain
}

template <class RecordType>
void tableChain<RecordType>::operator =(const tableChain<RecordType>& source)
// Library facilities used: hashNode.h, cstdlib 
{
	size_t i;
	hashNode<RecordType>* tail_ptr; // Needed for list_copy

	if (this == &source)
		return; // Avoid self-assignment

	for (i = 0; i < TABLE_SIZE; i++)
	{
		list_clear(data[i]);
		list_copy(source.data[i], data[i], tail_ptr);
	}
	total_records = source.total_records;
}

template <class RecordType>
bool tableChain<RecordType>::is_present(int key) const
// Library facilities used: cassert, cstdlib
{
	assert(key >= 0);

	return (find_node(key) != nullptr);
}

//***Display member function
template<class RecordType>
void tableChain<RecordType>::display_all()
{
	cout << "\n\n***DISPLAY ALL TABLE ENTRIES" << endl;
	//loop thorugh each array element
	for (size_t i = 0; i < TABLE_SIZE; i++)
	{
		if (data[i] != nullptr) {
			cout << "Index = " << i << endl;
			for (hashNode<RecordType>* cursor = data[i]; cursor != nullptr;cursor = cursor->link)
			{
				cout <<"\t"<< cursor->data<<endl;
			}
		}
			
									

	}
}

template <class RecordType>
void tableChain<RecordType>::find(int key, bool& found, RecordType& result) const
// Library facilities used: cstdlib
{
	hashNode<RecordType> *cursor;

	cursor = find_node(key);
	found = (cursor != nullptr);
	if (found)
		result = cursor->data;
}

template <class RecordType>
size_t tableChain<RecordType>::hash(int key) const
// Library facilities used: cstdlib
{
	return (key % TABLE_SIZE);
}

template <class RecordType>
hashNode<RecordType>* tableChain<RecordType>::find_node(int key) const
// Postcondition: The return value is a pointer to the record with the
// specified key (if there is one). If there is no such hashNode, the return value
// is the nullptr pointer.
// Library facilities used: hashNode.h, cstdlib
{
	hashNode<RecordType>* cursor;

	cursor = data[hash(key)];
	while ((cursor != nullptr) && ((cursor->data).key != key))
		cursor = cursor->link;

	return cursor;
}
