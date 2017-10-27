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

PriorityQueue::PriorityQueue( )
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

PriorityQueue::~PriorityQueue( )
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
		head_ptr->link;
		head_ptr->data = entry;
		head_ptr->priority = priority;
		return;
	}
	Node *temp;
	Node *next;
	temp = head_ptr;
	while (many_nodes > 2 && priority > temp->link->priority)
	{
		temp = temp->link;
		many_nodes++; // increment the number of items in the queue
	}
	next = temp;
	temp->data = entry;
	while (temp != nullptr) {
		temp = temp->link;
		temp = next;
		next = temp->link;
	}
	delete temp;
	delete next;
}

PriorityQueue::Item PriorityQueue::get_front( )
{
	Item answer;

	return answer;
}
