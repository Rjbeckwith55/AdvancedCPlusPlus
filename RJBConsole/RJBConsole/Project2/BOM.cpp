/*Author: Robert Beckwith
Date: 11/18/17
File: BOM.cpp
Class: CIS 2542
Descr:
	Implementation file for the BOM class*/

#include "BOM.h"

//TODO: This will automatically intitialize the bill of materials from the spreadsheet sorted into a certain order
//populates the bill of materials tree with the spreadsheet data
BOM::BOM() { //default constructor
	Material* root = new Material();
}