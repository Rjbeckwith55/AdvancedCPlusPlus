/*Author: Robert Beckwith
Date: 11/18/17
File: Material.h
Class: CIS 2542
Descr:
Specification file for the Material class*/
#include "BOM.h"

class Material {
public:
	Material();
	string getName();
	string setName();
	double getCost();
	double setCost();
	string getCategory();
	string setCategory();
	void displayMaterial(); // or do an overloaded operator
};