/*Author: Robert Beckwith
Date: 11/18/17
File: BOM.cpp
Class: CIS 2542
Descr:
	Implementation file for the BOM class*/

#include "BOM.h"

//Populates the material objects within the bill of materials
BOM::BOM() { //default constructor
	Material* root = new Material();
	string line ;

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
		for (; i <line.length()&& line[i] != ','; i++)
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
		for (; i <line.length() && line[i] != ','; i++)
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
		for (; i <line.length(); i++)
		{
			temp = temp + line[i];
		}
		//set the data into the BOM to the material that was just read in
		item.setCategory(temp);

		//add the item to the BOM list
		addItem(item);
		current = ++numLines;
	}
	
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

//sort the array into an unordered map which will then be able to search for the values of the category faster.
stack<Material> BOM::searchList(string cat) {
	//key of a string and a mapped value of Material.
	unordered_map<string, Material> umap;
	
	stack<Material> found;
	//put all of the BOM data from an array into a map to search more efficiently
	for (size_t i = 0; i < current; i++)
	{
		umap[data[i].getCategory()] = data[i];
	}
	//8 buckets by default

	//now search and return all of the members of data from the category.

	for (size_t i = 0; i < num; i++)
	{
		if (data[i].getCategory() == cat) {
			found.push(data[i]);
		}
	}
	
	while (!found.empty()) {
		//print and remove all the items from the stack
		cout << found.top();
		found.pop();
	}
	return found;
}

void BOM::heapsort(int data [ ], int n)
{
	int unsorted = n;

	make_heap(data, n);

	while (unsorted > 1) {
		--unsorted;
		swap(data[0], data[unsorted]); //provided in <algorithm>
		reheapify_down(data, unosorted);
	}
}

void BOM::make_heap(int data[ ] , int n)
{
	int i; 
	int k; 
	for (size_t i =	1; i < n; i++) // loops through all the elements of the heap
	{
		k = 1;
		while ((k > 0) && (data[k] > data[parent(k)]))
		{
			// swap the parent and the child of the parent if it is found that the child is larger.
			swap(data[k], data[parent(k)]); 
			k = parent(k);
		}
	}
}

void BOM::reaheapify_down(int[], int)
{
}
