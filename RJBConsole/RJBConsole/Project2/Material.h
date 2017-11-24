/*Author: Robert Beckwith
Date: 11/18/17
File: Material.h
Class: CIS 2542
Descr:
Specification file for the Material class*/
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <fstream>
using namespace std;

#ifndef Material_H
#define Material_H

class Material {
private:
	string name; 
	double cost; 
	string category;
	Material* left_field;
	Material* right_field;
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
/*Queries
https://docs.google.com/spreadsheets/d/1oXSR3jUg-dtJDht0ZeoAnDO1GC62AbGO3NeTbYnkA-Q/edit#gid=0
https://spreadsheets.google.com/tq?tqx=out:JSON&tq=select%20*%20where%20G%20contains%20%27SS%27&key=1jJLek-Y_6n9JoBqEBNj88WaE_WBbgwrAdgvqharpnvI
*/
#endif