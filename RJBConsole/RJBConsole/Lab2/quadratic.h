/*Robert Beckwith
Date: 9/6/2017
Class: CIS 2542
File: quadratic.h
Descr: specification file for the quadratic class*/

class quadratic {
private:
	double a;
	double b;
	double c;
public:
	quadratic();
	quadratic(double, double, double);
	void setA(double);
	void setB(double);
	void setC(double);
	double getA() const { return a; };
	double getB() const { return b; };
	double getC() const { return c; };
	double evalQuadForX(double);
};
/* SAMPLE OUTPUT
Input the values for the first quadratic expression.
	a: 3.2
	b : 5.5
	c : 1.7

	The quadratic expression is :
	3.2x ^ 2 + 5.5x + 1.7

Enter a value for x : 2
Evaluation of the quadratic expression is : 25.5

Input the values for the second quadratic expression
to add to the first.
	a : 1.8
	b : 5
	c : 3.2

	The quadratic expression is :
1.8x ^ 2 + 5x + 3.2

Added quadratic expression is : 5x ^ 2 + 10.5x + 4.9

Enter a value for x : 3.5

Evaluation of the quadratic expression is : 102.9

Input the multiplier value for the third quadratic expression
to multiply with the first : 7.7

The multiplied quadratic expression is : 24.64x ^ 2 + 42.35x + 13.09

Please enter a value for x : 8.1

Evaluation of the quadratic expression is : 1972.76
Press any key to continue . . .*/
