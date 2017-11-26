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
#include <unordered_map>
using namespace std;

#ifndef Material_H
#define Material_H

class Material {
private:
	string name; 
	double cost; 
	string category;
public:
	Material();
	Material(string, double, string);
	// Mutators
	const string getName() { return name; }
	void setName(string);
	const double getCost() { return cost; }
	void setCost(double);
	const string getCategory() { return category; }
	void setCategory(string);
	
	bool operator >(Material);
	bool operator <(Material);

	friend ostream& operator <<(ostream&,Material); //overloaded operator to print out all the data of the material
};
#endif