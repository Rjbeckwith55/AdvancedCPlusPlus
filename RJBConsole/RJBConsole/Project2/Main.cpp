/*Author: Robert Beckwith
Date: Main.cpp
Class: CIS 2542
Descr:
	Main to prompt the user for how they would like to search the data and it will do that.*/

#include "BOM.h"

int main() {
	BOM BillofMaterials;
	stack<Material> searchedItems;
	 // test data
	string category;
	int sortType;

	//prompt the user to serach for a something in the BOM
	cout << "This is a program to access the robotics bill of materials. Here is the bil of materials:\n" <<BillofMaterials<< endl; // currently off by one
	cout << "Enter the category you would like to display from the data" << endl;
	cout << "The categories are: "; BillofMaterials.printMapCat();
	cin >> category;
	//prints out the data specific to that category
	BillofMaterials.searchList(category);


	cout << "How would you like to sort the Bill of Materials?" << endl;
	cout << "1. Ascending by cost" << endl;
	cout << "2. Descending by cost" << endl;
	cout << "3. Alphabetically" << endl;
	cin >> sortType;
	//sorts the data based on how the user would like it sorted and displayed
	BillofMaterials.displayList(sortType,BillofMaterials); //TODO: data currently is being printed without being sorted

	return EXIT_SUCCESS;
}