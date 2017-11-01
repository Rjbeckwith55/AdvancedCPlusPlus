// FILE:  RecListTesting.cpp
// DESCR: 
// Testing program for recursive
// list functions of CIS2542 Lab #9.

#include <iostream>
#include "node.h"
using namespace std;

int main() {
	// identify node values
	double ditems[5] = { 5.5, 33.3, 22.2, 77.7, 11.1 };
	int arrSize = sizeof(ditems) / sizeof(double);

	// create linked list
	node* head_ptr = nullptr;  // empty list
	// add items to list
	for (int i = 0; i < arrSize; i++) {
		list_head_insert(head_ptr, ditems[i]);
	}

	// LAB#8-->Test Recursive Toolkit Functions
	// display list length
	cout << "The number of items in list is " << list_length(head_ptr) << endl;

	// display list
	cout << "List items in order:" << endl;
	display_list(head_ptr);
	// display list
	cout << "List items in reverse order:" << endl;
	rev_display_list(head_ptr);

	// searching list with non-constant function
	double dval;
	cout << "\nSearching with non-constant recursive function..." << endl;
	cout << "Input a  value to search (0 to end): ";
	cin >> dval;
	while (dval != 0.0) {
		node* toFind = list_search(head_ptr, dval);
		if (toFind != nullptr)
			cout << toFind->data() << " has been found!" << endl;
		else cout << dval << " has NOT been found!" << endl;
		cout << "Input a  value to search (0 to end): ";
		cin >> dval;
	}
	// searching list with constant function
	cout << "\nSearching with constant recursive function..." << endl;
	cout << "Input a  value to search (0 to end): ";
	cin >> dval;
	while (dval != 0.0) {
		const node* toFind = list_search(head_ptr, dval);
		if (toFind != nullptr)
			cout << toFind->data() << " has been found!" << endl;
		else cout << dval << " has NOT been found!" << endl;
		cout << "Input a  value to search (0 to end): ";
		cin >> dval;
	}

	// release the memory
	delete_list(head_ptr);

	return EXIT_SUCCESS;
}