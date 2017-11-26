/*Author: Robert Beckwith
Date: 11/23/17
File: Material.cpp
Class: CIS 2542
Descr:
	Implementation file for the Material class*/
#include "Material.h"
	//default and parameterized constructors
Material::Material() {
	name = " ";
	cost = 0.0;
	category = " ";
	left_field = nullptr;
	right_field = nullptr;
}
Material::Material(string n, double c, string cat) {
	name = n;
	cost = c;
	category = cat;
}
// mutators
void Material::setName(string n)
{
	name = n;
}

void Material::setCost(double c) {
	cost = c;
}

void Material::setCategory(string cat)
{
	category = cat;
}

//compare the costs using an overloaded operator
bool Material::operator>(Material m)
{
	return (cost > m.cost);
}
bool Material::operator<(Material m)
{
	return (cost < m.cost);
}

ostream& operator <<(ostream& out,Material m) {
	//print out all of the data from the material
	out << "$" << m.cost << " " << m.name << " for " << m.category << endl;
	return out;
}