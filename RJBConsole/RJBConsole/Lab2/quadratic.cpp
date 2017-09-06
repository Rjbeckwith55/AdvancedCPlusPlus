/*Robert Beckwith
Date: 9/6/2017
Class: CIS 2542
File: quadratic.cpp 
Descr: implementaion file for the quadratic class*/
#include "quadratic.h"

quadratic::quadratic() {
	a = 0.0;
	b = 0.0;
	c = 0.0;

}
void quadratic::setA(double A) {
	a = A;
}
void quadratic::setB(double B) {
	b = B;
}
void quadratic::setC(double C) {
	c = C;
}
double quadratic::evalQuadForX(double x) {
	double result;
	result = (a*x*x) + (b*x) + c;
	return result;
}
// parameterized constructor takes 3 doubles and sets the values to a, b and c
quadratic::quadratic(double A, double B, double C) {
	a = A;
	b = B;
	c = C;
}
quadratic operator + (const quadratic& q1, const quadratic& q2)
{
	double a, b, c;

	a = q1.getA() + q2.getA();
	b = q1.getB() + q2.getB();
	c = q1.getC() + q2.getC();
	//constructor that sets all the values of a, b and c
	quadratic q = quadratic(a, b, c);
	return q;

}
quadratic operator * (double m, const quadratic& q)
{
	double a, b, c;

	a = m * q.getA();
	b = m * q.getB();
	c = m * q.getC();
	//constructor that sets all the values of a, b and c
	quadratic quad = quadratic(a, b, c);
	return quad;

}
