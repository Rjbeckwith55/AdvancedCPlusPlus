// FILE: node.cpp
// IMPLEMENTS: The functions of the node class and the
// linked list toolkit (see node1.h for documentation).
// INVARIANT for the node class:
//   The data of a node is stored in data_field, and the link in link_field.
/*Robert Beckwith
11/1/17
*/
#include "node.h"
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides size_t
#include <iostream>
using namespace std;

//***AAA***modify to recursive version
// return number of nodes in list
size_t list_length(const node* head_ptr) {
	const node *cursor;
	size_t answer;

	answer = 0;
	if (head_ptr != nullptr) {
		cursor = head_ptr;
		cursor = cursor->link();
		answer++;
		answer = list_length(cursor) ;
		
	}
	return answer;
}

// insert new node with data at beginning of list
// NOTE pass by reference for head_ptr to change value
void list_head_insert(node*& head_ptr, const node::value_type& entry) {
	head_ptr = new node(entry, head_ptr);
}

// insert new node with data before given node
void list_insert(node* previous_ptr, const node::value_type& entry) {
	node *insert_ptr;

	insert_ptr = new node(entry, previous_ptr->link());
	previous_ptr->set_link(insert_ptr);
}

//***RJB***modify to recursive version
// search list for given item, return node pointer to first found item or nullptr
node* list_search(node* head_ptr, const node::value_type& target) {
	node *cursor;

	if (head_ptr != nullptr) {
		cursor = head_ptr;
		if (target == cursor->data()) {
			return cursor;
		}
		cursor = cursor->link();
		cursor = list_search(cursor,target);
		return cursor;

	}
	return nullptr;
}

//***RJB***modify to recursive version
// search list for given item, return constant node pointer to first found item or nullptr
const node* list_search(const node* head_ptr, const node::value_type& target) {
	const node *cursor;

	if (head_ptr != nullptr) {
		cursor = head_ptr;
		if (target == cursor->data()) {
			return cursor;
		}
		cursor = cursor->link();
		cursor = list_search(cursor, target);
		return cursor;

	}
	return nullptr;
}

// locate node at given position and return node pointer or nullptr
node* list_locate(node* head_ptr, size_t position) {
	// Library facilities used: cassert
	node *cursor;
	size_t i;

	assert(0 < position);
	cursor = head_ptr;
	for (i = 1; (i < position) && (cursor != nullptr); i++)
		cursor = cursor->link();
	return cursor;
}

// locate node at given position and return constant node pointer or nullptr
const node* list_locate(const node* head_ptr, size_t position) {
	// Library facilities used: cassert, cstdlib
	const node *cursor;
	size_t i;

	assert(0 < position);
	cursor = head_ptr;
	for (i = 1; (i < position) && (cursor != nullptr); i++)
		cursor = cursor->link();
	return cursor;
}

// remove node at beginning
// NOTE pass by reference for head_ptr to change value
void list_head_remove(node*& head_ptr) {
	node *remove_ptr;

	remove_ptr = head_ptr;
	head_ptr = head_ptr->link();
	delete remove_ptr;
}

// remove node linked to given node pointer
void list_remove(node* previous_ptr) {
	node *remove_ptr;

	remove_ptr = previous_ptr->link();
	previous_ptr->set_link(remove_ptr->link());
	delete remove_ptr;
}

// release memory for all nodes in list
// NOTE pass by reference for head_ptr to change value
void list_clear(node*& head_ptr) {
	while (head_ptr != nullptr)
		list_head_remove(head_ptr);
}

// copy all nodes from source list to target head and tail 
// NOTE pass by reference for head_ptr and tail_ptr to change values 
void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr) {
	head_ptr = nullptr;
	tail_ptr = nullptr;

	// Handle the case of the empty list.
	if (source_ptr == nullptr)
		return;

	// Make the head node for the newly created list, and put data in it.
	list_head_insert(head_ptr, source_ptr->data());
	tail_ptr = head_ptr;

	// Copy the rest of the nodes one at a time, adding at the tail of new list.
	source_ptr = source_ptr->link();
	while (source_ptr != nullptr)
	{
		list_insert(tail_ptr, source_ptr->data());
		tail_ptr = tail_ptr->link();
		source_ptr = source_ptr->link();
	}
}

//***RJB***added recursive function
void display_list(const node* head_ptr) {
	if (head_ptr != nullptr) {
		cout << head_ptr->data() << endl;
		display_list(head_ptr->link());
	}
}

//***RJB***added recursive function
void rev_display_list(const node* head_ptr) {

	if (head_ptr->link() != nullptr) {		
		rev_display_list(head_ptr->link());	
	}
	// print after the call so it goes in reverse
	cout << head_ptr->data() << endl;
}

//***RJB***added recursive function
void delete_list(node* head_ptr) {
	if (head_ptr->link() != nullptr) {
		delete_list(head_ptr->link());
	}
	//delete after the call so it deletes all the nodes after they have been called
	delete head_ptr;
	
}