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

class BOM {
public:
	BOM(); // default constructor
	void searchList();
	void displayList();
}; 
#endif