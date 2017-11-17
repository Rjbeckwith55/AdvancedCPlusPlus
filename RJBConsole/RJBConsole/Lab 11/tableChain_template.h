/* Robert Beckwith - added remove
11/16/17
CIS 2542*/
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

//   Postcondition: If a record was in the Table with the specified key, then
//     that record has been removed; otherwise the table is unchanged.
template <class RecordType>
void tableChain<RecordType>::remove(int key)
// Library facilities used: cassert, hashNode.h
{
	//Remove the element from the chain
	assert(key >= 0);
	hashNode<RecordType>* cursor;
	hashNode<RecordType>* previous = nullptr;

	cursor = data[hash(key)];
	while ((cursor != nullptr) && ((cursor->data).key != key))
	{
		previous = cursor;
		cursor = cursor->link;
	} // cursor will be null if not found and previous will be the second to last element
	

	if (cursor != nullptr) {
		if (previous != nullptr&&cursor->link == nullptr) // at the end of the current index
			list_remove(previous);
		else if (previous == nullptr) // first element in the current index
		{
			hashNode<RecordType> *remove_ptr;

			remove_ptr = cursor;
			cursor = cursor->link;
			data[hash(key)] = cursor;
			delete remove_ptr;
			if (cursor == nullptr) { // index is empty
				data[hash(key)] = nullptr;
			}
		}
		else
			list_remove(previous);
		total_records--;
	}
	else
		cout << "Not found in the table!" << endl;
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

/*I have initialized an empty table. Each record in the table
has an integer key and a real number as data.

The following choices are available:
 S   Print the result from the size( ) function
 I   Insert a new record with the insert(...) function
 R   Remove a record with the remove(...) function
 ?   Check whether a particular key is present
 F   Find the data associated with a specified key
 Q   Quit this test program
 D   Displays all the elements from the table
Enter choice: i
Please enter a real number for a record's data: 33.2
33.2 has been read.
Please enter a non-negative integer for a key: 4058
4058 has been read.
The record has been inserted.

The following choices are available:
 S   Print the result from the size( ) function
 I   Insert a new record with the insert(...) function
 R   Remove a record with the remove(...) function
 ?   Check whether a particular key is present
 F   Find the data associated with a specified key
 Q   Quit this test program
 D   Displays all the elements from the table
Enter choice: i
Please enter a real number for a record's data: 22.2
22.2 has been read.
Please enter a non-negative integer for a key: 2
2 has been read.
The record has been inserted.

The following choices are available:
 S   Print the result from the size( ) function
 I   Insert a new record with the insert(...) function
 R   Remove a record with the remove(...) function
 ?   Check whether a particular key is present
 F   Find the data associated with a specified key
 Q   Quit this test program
 D   Displays all the elements from the table
Enter choice: i
Please enter a real number for a record's data: 11.4
11.4 has been read.
Please enter a non-negative integer for a key: 1
1 has been read.
The record has been inserted.

The following choices are available:
 S   Print the result from the size( ) function
 I   Insert a new record with the insert(...) function
 R   Remove a record with the remove(...) function
 ?   Check whether a particular key is present
 F   Find the data associated with a specified key
 Q   Quit this test program
 D   Displays all the elements from the table
Enter choice: i
Please enter a real number for a record's data: 100
100 has been read.
Please enter a non-negative integer for a key: 811
811 has been read.
The record has been inserted.

The following choices are available:
 S   Print the result from the size( ) function
 I   Insert a new record with the insert(...) function
 R   Remove a record with the remove(...) function
 ?   Check whether a particular key is present
 F   Find the data associated with a specified key
 Q   Quit this test program
 D   Displays all the elements from the table
Enter choice: i
Please enter a real number for a record's data: 11.3
11.3 has been read.
Please enter a non-negative integer for a key: 1623
1623 has been read.
The record has been inserted.

The following choices are available:
 S   Print the result from the size( ) function
 I   Insert a new record with the insert(...) function
 R   Remove a record with the remove(...) function
 ?   Check whether a particular key is present
 F   Find the data associated with a specified key
 Q   Quit this test program
 D   Displays all the elements from the table
Enter choice: i
Please enter a real number for a record's data: 22.1
22.1 has been read.
Please enter a non-negative integer for a key: 2435
2435 has been read.
The record has been inserted.

The following choices are available:
 S   Print the result from the size( ) function
 I   Insert a new record with the insert(...) function
 R   Remove a record with the remove(...) function
 ?   Check whether a particular key is present
 F   Find the data associated with a specified key
 Q   Quit this test program
 D   Displays all the elements from the table
Enter choice: i
Please enter a real number for a record's data: 11.2
11.2 has been read.
Please enter a non-negative integer for a key: 3245
3245 has been read.
The record has been inserted.

The following choices are available:
 S   Print the result from the size( ) function
 I   Insert a new record with the insert(...) function
 R   Remove a record with the remove(...) function
 ?   Check whether a particular key is present
 F   Find the data associated with a specified key
 Q   Quit this test program
 D   Displays all the elements from the table
Enter choice: i
Please enter a real number for a record's data: 11.1
11.1 has been read.
Please enter a non-negative integer for a key: 5678
5678 has been read.
The record has been inserted.

The following choices are available:
 S   Print the result from the size( ) function
 I   Insert a new record with the insert(...) function
 R   Remove a record with the remove(...) function
 ?   Check whether a particular key is present
 F   Find the data associated with a specified key
 Q   Quit this test program
 D   Displays all the elements from the table
Enter choice: i
Please enter a real number for a record's data: 33.1
33.1 has been read.
Please enter a non-negative integer for a key: 3
3 has been read.
The record has been inserted.

The following choices are available:
 S   Print the result from the size( ) function
 I   Insert a new record with the insert(...) function
 R   Remove a record with the remove(...) function
 ?   Check whether a particular key is present
 F   Find the data associated with a specified key
 Q   Quit this test program
 D   Displays all the elements from the table
Enter choice: d

***DISPLAY ALL TABLE ENTRIES
Index = 0
        KEY=811 Data=100
Index = 1
        KEY=5678 Data=11.1
        KEY=3245 Data=11.2
        KEY=1623 Data=11.3
        KEY=1 Data=11.4
Index = 2
        KEY=2435 Data=22.1
        KEY=2 Data=22.2
Index = 3
        KEY=3 Data=33.1
        KEY=4058 Data=33.2

The following choices are available:
 S   Print the result from the size( ) function
 I   Insert a new record with the insert(...) function
 R   Remove a record with the remove(...) function
 ?   Check whether a particular key is present
 F   Find the data associated with a specified key
 Q   Quit this test program
 D   Displays all the elements from the table
Enter choice: r
Please enter a non-negative integer for a key: 3245
3245 has been read.
Remove has been called with that key.

The following choices are available:
 S   Print the result from the size( ) function
 I   Insert a new record with the insert(...) function
 R   Remove a record with the remove(...) function
 ?   Check whether a particular key is present
 F   Find the data associated with a specified key
 Q   Quit this test program
 D   Displays all the elements from the table
Enter choice: d


***DISPLAY ALL TABLE ENTRIES
Index = 0
        KEY=811 Data=100
Index = 1
        KEY=5678 Data=11.1
        KEY=1623 Data=11.3
        KEY=1 Data=11.4
Index = 2
        KEY=2435 Data=22.1
        KEY=2 Data=22.2
Index = 3
        KEY=3 Data=33.1
        KEY=4058 Data=33.2

The following choices are available:
 S   Print the result from the size( ) function
 I   Insert a new record with the insert(...) function
 R   Remove a record with the remove(...) function
 ?   Check whether a particular key is present
 F   Find the data associated with a specified key
 Q   Quit this test program
 D   Displays all the elements from the table
Enter choice: r
Please enter a non-negative integer for a key: 2
2 has been read.
Remove has been called with that key.

The following choices are available:
 S   Print the result from the size( ) function
 I   Insert a new record with the insert(...) function
 R   Remove a record with the remove(...) function
 ?   Check whether a particular key is present
 F   Find the data associated with a specified key
 Q   Quit this test program
 D   Displays all the elements from the table
Enter choice: d


***DISPLAY ALL TABLE ENTRIES
Index = 0
        KEY=811 Data=100
Index = 1
        KEY=5678 Data=11.1
        KEY=1623 Data=11.3
        KEY=1 Data=11.4
Index = 2
        KEY=2435 Data=22.1
Index = 3
        KEY=3 Data=33.1
        KEY=4058 Data=33.2

The following choices are available:
 S   Print the result from the size( ) function
 I   Insert a new record with the insert(...) function
 R   Remove a record with the remove(...) function
 ?   Check whether a particular key is present
 F   Find the data associated with a specified key
 Q   Quit this test program
 D   Displays all the elements from the table
Enter choice: r
Please enter a non-negative integer for a key: 3
3 has been read.
Remove has been called with that key.

The following choices are available:
 S   Print the result from the size( ) function
 I   Insert a new record with the insert(...) function
 R   Remove a record with the remove(...) function
 ?   Check whether a particular key is present
 F   Find the data associated with a specified key
 Q   Quit this test program
 D   Displays all the elements from the table
Enter choice: d


***DISPLAY ALL TABLE ENTRIES
Index = 0
        KEY=811 Data=100
Index = 1
        KEY=5678 Data=11.1
        KEY=1623 Data=11.3
        KEY=1 Data=11.4
Index = 2
        KEY=2435 Data=22.1
Index = 3
        KEY=4058 Data=33.2

The following choices are available:
 S   Print the result from the size( ) function
 I   Insert a new record with the insert(...) function
 R   Remove a record with the remove(...) function
 ?   Check whether a particular key is present
 F   Find the data associated with a specified key
 Q   Quit this test program
 D   Displays all the elements from the table
Enter choice: r
Please enter a non-negative integer for a key: 811
811 has been read.
Remove has been called with that key.

The following choices are available:
 S   Print the result from the size( ) function
 I   Insert a new record with the insert(...) function
 R   Remove a record with the remove(...) function
 ?   Check whether a particular key is present
 F   Find the data associated with a specified key
 Q   Quit this test program
 D   Displays all the elements from the table
Enter choice: d


***DISPLAY ALL TABLE ENTRIES
Index = 1
        KEY=5678 Data=11.1
        KEY=1623 Data=11.3
        KEY=1 Data=11.4
Index = 2
        KEY=2435 Data=22.1
Index = 3
        KEY=4058 Data=33.2

The following choices are available:
 S   Print the result from the size( ) function
 I   Insert a new record with the insert(...) function
 R   Remove a record with the remove(...) function
 ?   Check whether a particular key is present
 F   Find the data associated with a specified key
 Q   Quit this test program
 D   Displays all the elements from the table
Enter choice:*/