// FILE:              sequenceDynamic.cpp
// CLASS IMPLEMENTED: sequenceDynamic (See sequenceDynamic.h for documentation)
// INVARIANT for the sequenceDynamic ADT (i.e. verbalization of rules governing
//   private member function behavior):
//   1. The number of value_types in the sequenceDynamic is in the member variable used
//      (i.e. used = 0 means the sequenceDynamic is empty).
//   2. For an empty sequenceDynamic, we do not care what is stored in any of the
//      array data.  For a non-empty sequenceDynamic, the value_types in the sequenceDynamic are
//      stored in strictly maintained order in data[0] through
//      data[used].  We don't care what's in the rest of data (so don't
//      need to initialize data in the constructor).
//   3. To maintain strict order, current_index is used to keep track
//      of current location in data; when current_index is used-1,
//      we're at the last place in the array.  Also whenever current_index
//      is greater than or equal to used, there is no current value_type.
//   4. capacity keeps track of the current capacity of the array pointed
//      to by data; capacity starts out with the value initial_capacity
//      and is changed by resize as needed (whenever used is greater than
//      or equal to capacity).

#include <cassert>   // Provides assert
#include "sequenceDynamic.h"
using namespace std;

// the main constructor
sequenceDynamic::sequenceDynamic(size_type initial_capacity) {
	// create sequence of initial_capacity
	data = new value_type[initial_capacity];
	capacity = initial_capacity;
	used = 0;
	current_index = 0;
}

// copy constructor ==>TO COMPLETE FOR LAB
sequenceDynamic::sequenceDynamic(const sequenceDynamic& source) {

	//allocate enough memory
	data = new value_type[source.used];
	// set current capacity and used from source
	capacity = source.capacity;
	used = source.used;
	current_index = source.current_index;
	// copy items from source to current
	for (size_type i = 0; i < used; i++) {
		data[i] = source.data[i];
	}


}

// the destructor
sequenceDynamic::~sequenceDynamic() {
	// release memory
	delete[] data;
}

void sequenceDynamic::start() {
	current_index = 0;
}

void sequenceDynamic::advance() {
	// ensure that current_index is valid
	assert(is_item());
	current_index++;
}

// insert member function ==>TO COMPLETE FOR LAB
void sequenceDynamic::insert(const value_type& entry) {

	if (used >= capacity)
		resize(1 + used + used / 10); // Increase by 10%

	if (!is_item()) { //go back to the first item the item does not exist 
		current_index = 0;
	}

	for (size_type i = used; i > current_index; i--)
	{
		data[i] = data[i - 1];
	}
	data[current_index] = entry;
	// increment the number of items used
	used++;
}
void sequenceDynamic::attach(const value_type& entry) {
	// add additional memory if at capacity
	if (used >= capacity)
		resize(1 + used + used / 10); // Increase by 10%
	// If there is no current item,
	// add item at end of sequence
	if (!is_item())
	{
		current_index = used;
		data[current_index] = entry;
	}
	else // There is a current item
	{
		// so move items over to make room
		for (size_type i = used; i > (current_index + 1); i--)
			data[i] = data[i - 1];
		// insert item after current_index
		data[current_index + 1] = entry;
		// increment current_index
		current_index++;
	}
	// increment number of items used
	used++;
}

void sequenceDynamic::remove_current() {
	// ensure that current_index is valid
	assert(is_item());
	// remove item at current_index by shifting items over
	for (size_type i = current_index; i < used - 1; i++)
		data[i] = data[i + 1];
	// decrement number of items used
	used--;
}

// resize member function ==>TO COMPLETE FOR LAB
void sequenceDynamic::resize(size_type new_capacity) {
	if (new_capacity == capacity)
		return;

	// Can’t allocate less than we are using.
	if (new_capacity < used)
		new_capacity = used;

	// allocate memory for larger capacity
	value_type *larger_array = new value_type[new_capacity];

	// copy items from current to larger array
	for (size_type i = 0; i < used; ++i)
		larger_array[i] = data[i];

	// release old data, reassign data pointer, and reset capacity
	delete[] data;
	data = larger_array;
	capacity = new_capacity;

}

// overloaded assignment operator ==>TO COMPLETE FOR LAB
void sequenceDynamic::operator =(const sequenceDynamic& source) {
	if (this == &source)
		return;

	// add additional memory if at capacity
	if (this->capacity <= source.capacity)
		resize(source.capacity); // Increase size

	// set the number used from the source
	used = source.used;
	current_index = source.current_index;
	// copy over items from source to current
	for (size_type i = 0; i < used; i++) {
		data[i] = source.data[i];
	}
}

sequenceDynamic::size_type sequenceDynamic::size() const {
	return used;
}

bool sequenceDynamic::is_item() const {
	// see if current_index is valid
	return (current_index < used);
}

sequenceDynamic::value_type sequenceDynamic::current() const {
	// ensure that current_index is valid
	assert(is_item());
	return data[current_index];
}

sequenceDynamic operator +(const sequenceDynamic& s1, const sequenceDynamic& s2) {
	// create new bagDynamic with size equal to sum of both bagDynamic parameters
	sequenceDynamic result(s1.size() + s2.size());
	// add items from first sequenceDynamic
	result += s1;
	// add items from first sequenceDynamic
	result += s2;
	return result;
}

void sequenceDynamic::operator +=(const sequenceDynamic& addend) {
	// see if additional memory needed
	if ((used + addend.used) > capacity)
		resize(used + addend.used);
	// copy items from addend to current
	size_type addUsed = addend.used;
	for (size_type i = 0; i < addUsed; ++i)
		data[used++] = addend.data[i];
}
/* 
==========>TEST RESULTS<========= =
If you submit this sequenceDynamic class now, you will have
30 points out of the 30 points from this test program.
==========>POINT SUMMARY<========= =
Testing insert, attach, and the constant member functions
POINTS = 6 out of 6
Testing situations where the cursor goes off the sequenceDynamic
POINTS = 3 out of 3
Testing remove_current
POINTS = 0 out of 0
Testing the resize member function
POINTS = 6 out of 6
Testing the copy constructor
POINTS = 6 out of 6
Testing the assignment operator
POINTS = 6 out of 6
Testing insert / attach when current DEFAULT_CAPACITY exceeded
POINTS = 3 out of 3
Press any key to continue . . .*/