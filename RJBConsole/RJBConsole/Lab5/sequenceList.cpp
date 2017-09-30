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

	if (this == &source) { // check if the lists are the same
		return;
	}
	if (source.many_nodes == 0) { // blank list
		cursor = nullptr;
		head_ptr = nullptr;
		precursor = nullptr;
		tail_ptr = nullptr;
		many_nodes = 0;
		return;
	}
	else if (source.many_nodes == 1) { // copy the one item over
		list_copy(source.head_ptr, head_ptr, tail_ptr);
		start(); // go back to the front cursor = head and precursor = null
	}
	else {
		if (source.cursor == nullptr) {
			list_copy(source.head_ptr, head_ptr, tail_ptr);  // current item is at the end of the list
			cursor = nullptr;
			precursor = nullptr;
		}
		else if (source.precursor == nullptr && source.cursor != nullptr) { // current item is the first item
			list_copy(source.head_ptr, head_ptr, tail_ptr);
			start();
		}
		else {
			list_copy(source.precursor, head_ptr, tail_ptr); // insert the nodes after the precursor
			cursor = head_ptr->link(); // set the cursor after the precursor
			precursor = head_ptr; //set the head of this list to the precursor

			value_type nodes_left = source.many_nodes - list_length(head_ptr); // see how many items are left to copy over
			for (nodes_left; nodes_left > 0; nodes_left--) { // copy remaining items starting from the start of the previous list and adding them onto the front
				list_head_insert(head_ptr, (list_locate(source.head_ptr, nodes_left))->data());
			}
		}


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

	if (many_nodes == 0) { // if not any nodes a node is added
		list_head_insert(head_ptr, entry); // the new item becomes the first one in the list
		cursor = head_ptr;
		precursor = nullptr;
		tail_ptr = head_ptr;
		many_nodes++;
	}
	else {
		if (cursor == nullptr) {
			cursor = tail_ptr; // move cursor back temporarily for the attatch function if the cursor is at the back
		}
		list_insert(cursor, entry); // insert the item at the back of the current item
		precursor = cursor; // move precursor forward 1
		cursor = cursor->link(); // move cursort to the new item
		many_nodes++;
		while (tail_ptr->link() != nullptr) // set the tail ptr to the last pointer
			tail_ptr = tail_ptr->link();
	}

}

// method to remove item at cursor ==>TO COMPLETE FOR LAB
void sequenceList::remove_current() {
	if (!is_item()) {
		return;
	}
	if (cursor == nullptr)
		return; // target isn't in the sequence, so no work to do
	if (size() == 1) { // will become blank sequence remove all items in the list and set everything to null
		start();
		list_clear(head_ptr);
		head_ptr = nullptr;
		tail_ptr = nullptr;
		cursor = nullptr;
		many_nodes = 0;
		return;
	}
	if (size() == 2) {
		if (precursor != nullptr) { // checks to see if cursor is at the first item or not
			list_remove(precursor); // remove the item at the cursor
			head_ptr = precursor;
			tail_ptr = precursor;
			cursor = nullptr;
		}
		else
		{
			list_head_remove(head_ptr); // remove the first item
			cursor = head_ptr;
			tail_ptr = head_ptr;
			precursor = nullptr;
		}

	}
	else {
		if (cursor == nullptr) { // move back to the first item if the cursor is null and remove it
			cursor = head_ptr;
			precursor = nullptr;
			list_head_remove(head_ptr);
			cursor = head_ptr;
			while (tail_ptr->link() != nullptr) // set the tail ptr to the last pointer
				tail_ptr = tail_ptr->link();
		}
		else {
			cursor = cursor->link(); // advance one link
			if (precursor == nullptr) { // if the item is the first item... remove it
				list_head_remove(head_ptr); 
				precursor = nullptr;
				cursor = head_ptr;
			}
			else {
				list_remove(precursor); // remove the item after the cursor
				if (precursor->link() != nullptr)
					cursor = precursor->link(); // set the cursor link if the precursor isn't the last item
				else {
					cursor = nullptr; // end of the list
				}

			}
		}
	}
	many_nodes--;
}

// overloaded = assignment operator ==>TO COMPLETE FOR LAB
void sequenceList::operator =(const sequenceList& source) {
	// check for possible self assignment
	if (this == &source)
		return;
	//clear the old list
	list_clear(head_ptr);
	tail_ptr = nullptr;
	cursor = nullptr;
	precursor = nullptr;
	many_nodes = 0;

	if (source.many_nodes == 0) { // empty sequence
		tail_ptr = nullptr;
		cursor = nullptr;
		precursor = nullptr;
		head_ptr = nullptr;
	}
	else if (source.many_nodes == 1) { 
		list_copy(source.head_ptr, head_ptr , tail_ptr); // copy one item over
		start(); // go back to the front of the sequence
	}
	else {
		if (source.cursor == nullptr) {
			list_copy(source.head_ptr, head_ptr, tail_ptr); // copy list over
			precursor = nullptr;
			cursor = nullptr;
		}
		else if (source.precursor == nullptr&& source.cursor != nullptr) { // the front of the list
			list_copy(source.head_ptr, head_ptr, tail_ptr); // copy the list
			start(); // go back to the front of the sequence
		}
		else {
			list_copy(source.precursor, head_ptr, tail_ptr); // insert the nodes after the precursor
			cursor = head_ptr->link(); // set the cursor after the precursor
			precursor = head_ptr; //set the head of this list to the precursor

			value_type nodes_left = source.many_nodes - list_length(head_ptr); // see how many items are left to copy over
			for (nodes_left; nodes_left > 0; nodes_left--) { // copy remaining items starting from the start of the previous list and adding them onto the front
				list_head_insert(head_ptr, (list_locate(source.head_ptr, nodes_left))->data()); 
			}
		}
		
	}
	many_nodes = source.many_nodes;
}

// method to return item at cursor
sequenceList::value_type sequenceList::current() const {
	assert(is_item());
	return cursor->data();
}
