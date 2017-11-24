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
	Material* left_field;
	Material* right_field;
public:
	Material();
	Material(string, double, string);
	//mutators
	const string getName() { return name; }
	void setName(string);
	const double getCost() { return cost; }
	void setCost(double);
	const string getCategory() { return category; }
	void setCategory(string);

	
	friend ostream& operator <<(ostream&,Material); //overloaded operator to print out all the data of the material
};

/*Queries
https://docs.google.com/spreadsheets/d/1oXSR3jUg-dtJDht0ZeoAnDO1GC62AbGO3NeTbYnkA-Q/edit#gid=0
https://spreadsheets.google.com/tq?tqx=out:JSON&tq=select%20*%20where%20id%20equals%20%27A%27&key=1oXSR3jUg-dtJDht0ZeoAnDO1GC62AbGO3NeTbYnkA-Q
%20or%20%27B%27%20%27C%27%20
1oXSR3jUg-dtJDht0ZeoAnDO1GC62AbGO3NeTbYnkA-Q
*/
#endif