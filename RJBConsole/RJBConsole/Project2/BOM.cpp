/*Author: Robert Beckwith
Date: 11/18/17
File: BOM.cpp
Class: CIS 2542
Descr:
	Implementation file for the BOM class*/

#include "BOM.h"

	//TODO list
	/*
	--Maybe make an all category on the unordered_map
	--Figure out Alphabetical
	--Make the UI better and cleaner and smoother and any other adjective I can think of
	--Clean up code
	*/

// Get the data for the Bill of Materials from the spreadsheet and adds it to the data field of the BOM class
BOM::BOM() { //default constructor
	string line;

	//Spreadsheet data taken from ETC Treasury 11/23/17
	ifstream file("Project2/Treasury.csv");
	//parse the data from a csv file
	int numLines = 0;

	while (!file.eof()) {
		getline(file, line);
		Material item;
		int i = 0;
		string temp = "";

		//loop through until a comma is reached in the CSV file
		//Get the cost of the material
		for (; i < line.length() && line[i] != ','; i++)
		{
			temp = temp + line[i];
		}
		item.setCost(stod(temp));

		//Get the name of the material from the spreadsheet
		temp = "";
		//skip the comma
		if (line[i] == ',') {
			i++;
		}
		for (; i < line.length() && line[i] != ','; i++)
		{
			temp = temp + line[i];
		}
		item.setName(temp);

		//Get the category of the material from the spreadsheet
		temp = "";
		//skip the comma
		if (line[i] == ',') {
			i++;
		}
		for (; i < line.length(); i++)
		{
			temp = temp + line[i];
		}
		//set the data into the BOM to the material that was just read in
		item.setCategory(temp);

		//add the item to the BOM list
		addItem(item);
		current = ++numLines;

		//map with key values of the string category and the second value is a linked list of all the items in that category
		mat_node* newNode = new mat_node();
		newNode->data = item;

		// Key is already in the map
		if (umap.find(item.getCategory()) != umap.end()) {
			//insert the item before the first item
			mat_node* base = umap.find(item.getCategory())->second;
			newNode->link = base; //add the new item as a link
			umap.erase(item.getCategory()); // erase the current bucket this is a hack because insert and emplace were not overriding.
			umap.insert({ item.getCategory(), newNode });

		}
		//key is not in the map
		else {
			// Insert the current material into the linked list on the map
			umap.insert({ item.getCategory(), newNode });
		}

	}
	//set the total cost of the entire list
	for (size_t i = 0; i < num; i++)
	{
		totalCost += data[i].getCost();
	}
}
// Destructor to release the memory and clear the map.
BOM::~BOM()
{

	for (auto& x : umap) {
		//deallocate the memory from the linked list 
		deleteNodes(x.second);
	}

	// clear the map
	umap.clear();
}
//Copy constructor solved an issue where the destructor was called too early
BOM::BOM(BOM & source) // copy constructor
{
	for (int i = 0; i < source.num; i++) {
		data[i] = source.data[i];
	}
	num = source.num;
	current = source.current;
}

double BOM::getTotal()
{
	return totalCost;
}


//recursive deletion of the nodes in a linked list
void BOM::deleteNodes(mat_node * node)
{
	if (node != nullptr) {
		node = node->link;
		deleteNodes(node);
	}
	delete node;
}

//Add an item to the BOM
void BOM::addItem(Material m) {
	data[current] = m;
	num++;
}

//overloaded output operator
ostream& operator <<(ostream& out, BOM b) {
	//print out all of the data from the material
	for (size_t i = 0; i < b.num; i++)
	{
		cout << b.data[i];
	}
	return out;
}

//Use the map to display the category display the data in that category
void BOM::searchList(string cat) {
	string category;
	double total;

	//all of the data sorted by category is distributed in the unordered_map umap;
	if (umap.find(cat) != umap.end()) {
		cout << endl;
		total = printLinked(umap.find(cat)->second);
		cout << "The total cost of this category is: $" << total << endl;
		cout << endl;
	}
	else {
		cout << endl;
		cout << "**Category not found!**" << endl;
		cout << "Enter the category you would like to display from the data" << endl;
		cout << "The categories are: "; printMapCat();
		cin >> category;
		searchList(category);
	}

}

// Passed the type of sort needed and the bill of materials object so the overloaded operator can be used
// Uses a stack to swap the direction of the sort for printing
void BOM::displayList(int type, BOM& Bill)
{
	cout << endl;
	stack<Material> items;
	int sortType;

	switch (type) {	
	case 1:
		//Descending by cost
		//swap the print order by using a stack
		Bill.heapsort();
		for (int i = 0; i < num; i++) // off by one
		{
			items.push(Bill.data[i]);
		}
		while (!items.empty()) {
			cout << items.top();
			items.pop();
		}
		cout << endl;
		cout << "The Total cost of this Bill of Materials is: $" << Bill.getTotal() << endl;
		break;

	case 2:
		//Ascending by cost
		Bill.heapsort();
		cout << Bill;
		cout << endl;
		cout << "The Total cost of this Bill of Materials is: $" << Bill.getTotal() << endl;
		break;

	case 3:
		//Alphabetically
		break;
	default:
		cout << "**Please choose the number next to the type of sort**" << endl;
		cout << "How would you like to sort the Bill of Materials?" << endl;
		cout << "1. Ascending by cost" << endl;
		cout << "2. Descending by cost" << endl;
		cout << "3. Alphabetically" << endl;
		cin >> sortType;
		displayList(sortType, Bill);
	}
	
}

void BOM::printMapCat()
{
	for (auto& x : umap) {
		cout << x.first << " ";
	}
	cout << ": ";
}

// Recursive print and add the cost up of the linked list
double BOM::printLinked(mat_node * node)
{
	double total = 0;
	if (node != nullptr) {
		cout << node->data;
		total += node->data.getCost();
		node = node->link;
		total += printLinked(node);
	}
	return total;
}



// heapsort demonstrates the use of trees and sorting
// a lot of logic was taken from the heapsort example but was modified in order to sort the materials
void BOM::heapsort()
{
	int unsorted = num; // number of elements to sort

	//create a heap of the current data
	make_heap();

	while (unsorted > 1) {
		--unsorted;
		swap(data[0], data[unsorted]); //provided in <algorithm>
		reheap_down(unsorted);
	}

}

void BOM::make_heap()
{
	int i; // the index of the new node in the heap
	int k;

	for (i = 1; i < num; ++i) // loops through all the elements of the heap
	{
		k = i;
		// if the child that is being pushed up is larger than the parent it needs to swap postititions with the parent
		while ((k > 0) && (data[k] > data[parent(k)]))
		{
			// swap the parent and the child of the parent if it is found that the child is larger.
			swap(data[k], data[parent(k)]);
			k = parent(k);
		}
	}
}

//n represents the segment of the heap that needs to be sorted
void BOM::reheap_down(int unsorted)
{
	int currentIndex = 0;
	int big_child_index; // index of the child that is larger than the parent and will need to be swapped with the parent
	bool heap_complete = false; // flag to tell if the heap is completed with the children less than the parents.

	//Loops through until the heap has been completed this will be when all the children are less than the parents.
	// The second part of the while loop compares the left child to the number of elements in the heap.
	while ((!heap_complete) && (left_child(currentIndex) < unsorted)) {
		// get the right child of the current node and check
		// n represents the number of nodes in this section of the heap
		if (right_child(currentIndex) >= unsorted) {
			// there is no right child. Set the biggest child from this node to the left child
			big_child_index = left_child(currentIndex);
		}
		else if (data[left_child(currentIndex)] > data[right_child(currentIndex)]) {
			// the left child is larger than the right child therefore the biggest child is the left child
			big_child_index = left_child(currentIndex);
		}
		else
			//right child is the bigger of the two nodes.
			big_child_index = right_child(currentIndex);

		//check whether the larger child is bigger than the current node
		if (data[currentIndex] < data[big_child_index]) {
			//swap the data so the child is less than the parent
			swap(data[currentIndex], data[big_child_index]);
			currentIndex = big_child_index; // progress up the tree
		}
		// the heap is completed because the current node is larger than the child nodes
		else
			heap_complete = true;
	}
}
// This represents postorder traversal of the tree structure
int BOM::right_child(int k)
{
	//goes down to the level below by multiplying by 2 and then adds 2 to retrieve the right element
	return 2 * k + 2;
}

int BOM::left_child(int k)
{
	//goes up to the level above by multiplying by 2 and then adds 1 to retrieve the left element
	return 2 * k + 1;
}

int BOM::parent(int k)
{
	return (k - 1) / 2;
}
