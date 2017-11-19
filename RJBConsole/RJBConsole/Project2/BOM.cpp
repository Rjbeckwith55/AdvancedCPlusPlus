/*Author: Robert Beckwith
Date: 11/18/17
File: BOM.cpp
Class: CIS 2542
Descr:
	Implementation file for the BOM class*/

#include "BOM.h"
#include "json\src\json.hpp" // library from https://github.com/nlohmann/json to parse the JSON data from the spreadsheet

//using json = nlohmann::json;

//TODO: This will automatically intitialize the bill of materials from the spreadsheet sorted into a certain order
//populates the bill of materials tree with the spreadsheet data
BOM::BOM() { //default constructor
	Material* root = new Material();

	ifstream i("file.json");
	nlohmann::json j;
	i >> j;

	// write prettified JSON to another file
	std::ofstream o("pretty.json");
	o << std::setw(4) << j << std::endl;
	
}