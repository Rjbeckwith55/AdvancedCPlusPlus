// FILE: pQueueList.cpp
// First implementation of the priority queue, which stores items on a
// linked list. See pQueueList.h for complete specification.
//
// Invariant of the PriorityQueue class:
//    head_ptr is the head pointer for a linked list that
//    contains the items along with their priorities. These nodes are
//    kept in order from highest priority (at the head of the list)
//    to lowest priority (at the tail of the list). The private member
//    variable, many_nodes, indicates how many nodes are on the list.
//    The data type Node is completely defined in pQueueList.h.
//

#include <cassert>       // Provides assert
#include "pQueueList.h"  // Provides PriorityQueue and Node

PriorityQueue::PriorityQueue()
{
	many_nodes = 0;
	head_ptr = nullptr;
}

PriorityQueue::PriorityQueue(const PriorityQueue& source)
{
	Node *temp;

	temp = source.head_ptr;

	many_nodes = source.many_nodes;
	while (head_ptr != nullptr)
	{
		head_ptr->priority = source.head_ptr->priority;
		head_ptr->data = source.head_ptr->data;
		head_ptr = head_ptr->link;
	}
	head_ptr = temp;
	delete temp;
}

PriorityQueue::~PriorityQueue()
{
	Node *temp;

	while (head_ptr != nullptr)
	{
		temp = head_ptr;
		head_ptr = head_ptr->link;
		delete temp;
	}
}

void PriorityQueue::operator =(const PriorityQueue& source)
{
	if (this == &source) // Handle self-assignment
		return;

}

void PriorityQueue::insert(const Item& entry, unsigned int priority)
{
	// If the sequence is empty add it to the front and set the priority.
	if (many_nodes == 0) {
		head_ptr = new Node();
		head_ptr->link = nullptr;
		head_ptr->data = entry;
		head_ptr->priority = priority;
		many_nodes = 1;
		return;
	}
	else if (many_nodes == 1)
	{
		//if the priority is of this new nod is greater add it to the front of the queue
		if (priority > head_ptr->priority) { // insert into the front // for some reason this ends up being null
			Node *temp = head_ptr; // store the head pointer temporarily
			head_ptr = new Node(); // create a new node in front
			// set the data and priority of this new node
			head_ptr->data = entry;
			head_ptr->priority = priority;
			//set the link of the head pointer to what the previous head was
			head_ptr->link = temp;
			many_nodes++;
		}
		// the priority of the new entry is less than the current node
		else {
			head_ptr->link = new Node(); // create a new node after the head
			// set the data and priority of this new node
			head_ptr->link->data = entry;
			head_ptr->link->priority = priority;
			many_nodes++;
		}
	}
	//if there are more than two nodes
	else {
		Node *temp;
		Node *previous;
		Node *EvenMoreTemp;
		temp = head_ptr;
		previous = nullptr;
		// loop through the list until the added priority is less than the current item in the list
		while (temp != nullptr && temp->priority > priority) {
			previous = temp;
			temp = temp->link;
		}
		if (temp != nullptr && previous != nullptr) {
			//set the item at previous to be equal to the new priority item
			EvenMoreTemp = new Node();
			EvenMoreTemp->data = previous->data;
			EvenMoreTemp->priority = previous->priority;
			EvenMoreTemp->link = temp;

			//set the data of previous to point to the new
			previous->data = entry;
			previous->priority = priority;
			previous->link = EvenMoreTemp;
			delete EvenMoreTemp;
		}
		//add to the head of the list
		else if (previous == nullptr) {
			temp = head_ptr; // store the head pointer temporarily
			head_ptr = new Node(); // create a new node in front
								   // set the data and priority of this new node
			head_ptr->data = entry;
			head_ptr->priority = priority;
			//set the link of the head pointer to what the previous head was
			head_ptr->link = temp;
		}
		else { // happens when at the end of the sequence
			temp = new Node();
			temp->data = entry;
			temp->priority = priority;
			previous->link = temp;
		}

		many_nodes++;

		//release memory
		
		
	}



}

PriorityQueue::Item PriorityQueue::get_front()
{
	assert(size() > 0);
	Item answer;
	answer = head_ptr->data;
	head_ptr = head_ptr->link;
	many_nodes--;
	return answer;
}
