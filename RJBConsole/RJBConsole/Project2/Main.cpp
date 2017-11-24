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

	//prompt the user to serach for a something in the BOM
	cout << "This is a program to access the robotics bill of materials" << endl;
	cout << "Enter the category you would like to display from the data" << endl;
	cin >> category;
	searchedItems = BillofMaterials.searchList(category);
	

	return EXIT_SUCCESS;
}