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
	
	if (this == &source) // Handle self-assignment
		return;
	
	head_ptr = nullptr;
	many_nodes = 0;

	//check for a blank list
	if (source.head_ptr == nullptr) {
		head_ptr = nullptr;
		many_nodes = 0;
		return;
	}
	Node *temp;
	//set some variables equal to the head of the list

	temp = source.head_ptr;
	//list copy assuming they are in priority order
	for (int i = 0; i < source.many_nodes; i++)
	{
		insert(temp->data, temp->priority);
		temp = temp->link;
	}


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

	//destructor to clear the previous
	PriorityQueue::~PriorityQueue();


	//check for a blank list
	if (source.head_ptr == nullptr) {
		head_ptr = nullptr;
		many_nodes = 0;
		return;
	}
	Node *temp;
	//set a temp equal to the front of the new list
	temp = source.head_ptr;

	//list copy, Traverse the list and insert the items from the new list
	for (int i = 0; i < source.many_nodes; i++)
	{
		insert(temp->data, temp->priority);
		temp = temp->link;
	}


}

void PriorityQueue::insert(const Item& entry, unsigned int priority)
{
	// If the sequence is empty add it to the front and set the priority.
	Node *temp = nullptr;
	Node *tempHead = nullptr;

	//hold the head pointer of the list
	tempHead = head_ptr;

	//set the new node to be equal to the entry
	// we will later insert this node into the list
	Node *newNode = new Node();
	newNode->data = entry;
	newNode->priority = priority;
	newNode->link = nullptr;
	many_nodes++;
	//empty list add the new item to the front
	if (tempHead == nullptr) {
		head_ptr = newNode;
		return;
	}
	// traverse the list until the new node's priority is less than a current nodes
	while (tempHead != nullptr && tempHead->priority >= priority) {
		temp = tempHead; // acts as a previous variable allowing us to insert after it
		tempHead = tempHead->link;
	}
	// tempHead is behind the new node
	newNode->link = tempHead;

	if (tempHead == head_ptr) {
		//(List_Head_Insert) adding the node to the front because it has the greatest priority
		head_ptr = newNode;
		return;
	}
	// set the link of the previous node to the new node
	// It now has been inserted into the linked list
	temp->link = newNode;


}

PriorityQueue::Item PriorityQueue::get_front()
{ // must free up memory here
	Item answer;
	//check to see if head exists
	if (head_ptr != nullptr)
	{
		Node *Front = head_ptr;

		answer = head_ptr->data;
		head_ptr = head_ptr->link;

		delete Front; // delete the previous head pointer out of memory
		many_nodes--;
	}
	return answer;
}
