/*
Author: Robert Beckwith
Date:09/13/2017
File: SequenceFixed.cpp
Descr:
Implementation file for the sequence fixed class*/

#include "sequenceFixed.h"
#include <cassert>
const sequenceFixed::size_type CAPACITY = 30;

// Constructor
// Postcondition: sequence fixed has been initialized as empty
sequenceFixed::sequenceFixed() {
	used = 0;
	current_index = 0;
}

// constant member function to return the current size
// Postcondition: returns the number of items in the container
sequenceFixed::size_type sequenceFixed::size() const {
	return used;
}

// constant member fuction to return if the current index is valid
// Postcondition: return value of true indicates current_index is valid false indicates current_index is not valid
bool sequenceFixed::is_item() const {
	return (current_index < used);
}

// member function to set the current index at the beginning of the sequence
// Postcondition: make the first item in the sequence the current_item
void sequenceFixed::start() {
	current_index = 0;
}

// const member funciton to return the value at the current index
// Precondition: is_item() returned true
// Postcondition: return value of the current_index
sequenceFixed::value_type sequenceFixed::current() const {
	assert(is_item()); //ensure that the index is valid
	return data[current_index];
}

// member function to move the current index by one
// Precondition: is_item() returned true
// Postcondition: current_index incremented by one
void sequenceFixed::advance() {
	assert(is_item()); //ensure that the index is valid
	current_index++;
}
// member function to insert an item at the current index 
// Precondition: enough space in the sequence
// Postcondition: item is inserted and current_index is points to new item
void sequenceFixed::insert(const sequenceFixed::value_type& entry){
	// see if the current_index is valid
	assert(used < CAPACITY);

	//see if the current_index is valid; if not reset current_index to front
	if (is_item() == false) {
		current_index = 0;
	}
	//move item over from current_index
	for (size_type i = used ; i> current_index; i--)
	{
		data[i] = data[i-1];
	}

	//insert the new entry
	data[current_index] = entry;
	// increment the number of items used
	used++;

}
// member function to insert an item after current index 
// Precondition: enough space in the sequence
// Postcondition: item is inserted and current_index is points to new item
void sequenceFixed::attach(const sequenceFixed::value_type& entry) {
	assert(used < CAPACITY);
	//assert(is_item());
	
	//see if the current_index is valid; if not reset current_index to front
	if (is_item() == false) {
		//If the index doesnt exists it is put at the last element
		data[used] = entry;
		current_index = used;
		used++;
	}
	else {
		//move item over from current_index
		current_index++;
		used++;
		for (size_type i = used; i> current_index; i--)
		{
			data[i] = data[i - 1];
		}

		//insert the new entry
		data[current_index] = entry;
		// increment the number of items used
	}
	
	


}
//Precondition: is_item returns true.
	//     Postcondition: The current item has been removed from the sequenceFixed, and the
	//     item after this (if there is one) is now the new current item.
void sequenceFixed::remove_current(){
	assert(is_item());
	for (size_type i = current_index; i<used-1; i++)
	{
		data[i] = data[i + 1];
		
	}
	used--;

}