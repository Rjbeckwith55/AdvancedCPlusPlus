// FILE: tableMultiChain_tester.cpp

#include <cstdlib>     // Provides EXIT_SUCCESS and size_t
#include <iostream>    // Provides cin, cout
#include "tableMultiChain.h"    // Provides the table class
using namespace std;

// Struct definition for the test_record_type, which has a key and a double.
struct test_record_type
{
	int key;
	double data;
};

// overload output operator for display method
ostream& operator <<(ostream& outs, const test_record_type& source) {
	outs << "KEY=" << source.key << " DATA=" << source.data;
	return outs;
}

int main() {
	// create multi key hash table
	tableMultiChain<test_record_type> multiHash;
	// TEST CASES
	test_record_type t1{ 5678, 99.0 }, t2{ 1, 11.1 }, t3{ 2, 22.1 }, t4{ 3, 33.1 },
		t5{ 2435, 22.0 }, t6{ 1, 11.2 }, t7{ 1623, 11.0 }, t8{ 1, 11.3 }, t9{ 2, 22.2 };
	// add the elements
	multiHash.insert(t1);
	multiHash.insert(t2);
	multiHash.insert(t3);
	multiHash.insert(t4);
	multiHash.insert(t5);
	multiHash.insert(t6);
	multiHash.insert(t7);
	multiHash.insert(t8);
	multiHash.insert(t9);
	// display size and elements
	cout << "The table size is " << multiHash.size();
	multiHash.display_all();
	// display elements for given key
	cout << "\nThe number of entries with KEY=1 is " << multiHash.count(1) << endl;
	multiHash.display_key_values(1);
	cout << "\nThe number of entries with KEY=2 is " << multiHash.count(2) << endl;
	multiHash.display_key_values(2);
	cout << "\nThe number of entries with KEY=3 is " << multiHash.count(3) << endl;
	multiHash.display_key_values(3);
	// removing one entry with key
	cout << "\n\nRemoving one element with KEY=2" << endl;
	multiHash.remove(2);
	cout << "The table size is " << multiHash.size();
	multiHash.display_all();
	// removing all entries with key
	cout << "\n\nRemoving all elements with KEY=1" << endl;
	multiHash.remove_all(1);
	cout << "The table size is " << multiHash.size();
	multiHash.display_all();
	// display elements for given key
	cout << "\nThe number of entries with KEY=1 is " << multiHash.count(1) << endl;
	multiHash.display_key_values(1);
	cout << "\nThe number of entries with KEY=2 is " << multiHash.count(2) << endl;
	multiHash.display_key_values(2);
	cout << "\nThe number of entries with KEY=3 is " << multiHash.count(3) << endl;
	multiHash.display_key_values(3);
	return EXIT_SUCCESS;
}