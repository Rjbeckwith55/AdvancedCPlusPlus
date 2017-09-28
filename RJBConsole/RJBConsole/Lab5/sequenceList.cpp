// FILE: sequenceList.cpp
// CLASS implemented: sequenceList (see sequenceList.h for documentation)
// INVARIANT for the sequenceList ADT:
//   1. The items in the sequenceList are stored on a linked list,
//      in order from the start of the sequenceList at the head of the list;
//   2. The head pointer of the list is stored in the member variable head_ptr;
//   3. The tail pointer of the list is stored in the member variable tail_ptr;
//   4. If there is a current item, then the cursor points to the node that
//      contains this item; otherwise the cursor is nullptr.
//   5. If there is an item before the current item, then the precursor points
//      to the node that contains this item; otherwise the precursor is nullptr.
//   3. The total number of items in the list is stored in the member variable
//      many_nodes.

#include <cassert>  // Provides assert
#include <cstdlib>  // Provides rand, size_t
#include "node.h"  // Provides node and the linked list functions
#include "sequenceList.h"
using namespace std;

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
	// Library facilities used: node.h  
	if (head_ptr == nullptr)
		return;
	tail_ptr = source.tail_ptr;	list_copy(source.head_ptr, head_ptr, tail_ptr);
	many_nodes = source.many_nodes;
	cursor = source.cursor;
	precursor = source.precursor;
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
	if (cursor == nullptr) {
		if (head_ptr == nullptr) {
			insert(entry);// will make tail = head
			if(tail_ptr->link())
				tail_ptr = tail_ptr->link();
		}
		else {
			list_insert(tail_ptr, entry);
			precursor = tail_ptr;
			tail_ptr = tail_ptr->link();
			cursor = tail_ptr;
			if (head_ptr == nullptr)
				head_ptr = tail_ptr; //shouldn't ever run
			++many_nodes;
		}

	}
	else
	{
		list_insert(cursor, entry);
		precursor = cursor;
		cursor = cursor->link();

		while (tail_ptr->link()!=nullptr) // set the tail ptr to the last pointer
			tail_ptr = tail_ptr->link();
		++many_nodes;
	}
	
}

// method to remove item at cursor ==>TO COMPLETE FOR LAB
void sequenceList::remove_current() {
	if (cursor == nullptr)
		return; // target isn't in the bagList, so no work to do

	list_remove(precursor);
	--many_nodes;
}

// overloaded = assignment operator ==>TO COMPLETE FOR LAB
void sequenceList::operator =(const sequenceList& source) {
	// check for possible self assignment
	if (this == &source)
		return;

	//clear the old list
	list_clear(head_ptr);
	list_copy(source.head_ptr, head_ptr, tail_ptr);
	many_nodes = source.many_nodes;
}

// method to return item at cursor
sequenceList::value_type sequenceList::current() const {
	assert(is_item());
	return cursor->data();
}
