/*Author: Robert Beckwith
Date: 11/2/17
File: BOM.h
Class: CIS 2542
Descr:
	Specification file for the BOM class*/

#include "Material.h"


#ifndef BOM_H
#define BOM_H
	//struct for the nodes of the bill of materials tree
struct mat_node {
	Material data;
	mat_node* link;

	mat_node() { // default values
		data = Material();
		link = nullptr;

	}
};
class BOM {

public:
	static const int NUM_ITEMS = 30;
	BOM(); // default constructor
	const int getNum() { return num; }
	void addItem(Material);
	void searchList(string); // would return a stack of the items in an order
	void displayList(int,BOM&); // given an int to print out in different orders

	//functions for traversing the map and linked list combo
	void printLinked(mat_node*);

	//functions for heapsorting the data in different arrangements
	void heapsort();
	void make_heap(Material[ ], int);
	void reheap_down(Material[ ], int);
	int right_child(int);
	int left_child(int);
	int parent(int);

	friend ostream& operator <<(ostream&, BOM);
private:
	unordered_map<string, mat_node*> umap;
	int current = 0;
	int num = 0;
	Material data[NUM_ITEMS];
};
#endif