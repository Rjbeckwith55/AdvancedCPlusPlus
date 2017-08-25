/*Robert Beckwith
8/23/17
Lab #1
CIS 2542
Descr:
	A program that caculuates the quatdratic expression and uses exception handling
*/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

vector<double> calcQuadratic(double, double, double);

int main() {
	double a, b, c;
	vector<double> x;

	// read input for a, b ,and c
	cout << "Enter in the value for a: ";
	cin >> a;
	cout << "Enter in the value for b: ";
	cin >> b;
	cout << "Enter in the value for c: ";
	cin >> c;

	
	try {
		x = calcQuadratic(a, b, c);
	}
	catch (char* a) {
		cout << "Error data does not follow this condition b*b > 4 * a*c && a != 0" << a << endl;
		exit(EXIT_FAILURE);
	}
	cout << "First real root = " << x[0] << " Second real root: " << x[1] << endl;
	return 0;
}
//***PART E***
//Precondition: b2>4ac and a!=0
//Postcondition: the two real roots are returned in a vector
vector<double> calcQuadratic(double a, double b, double c) {
	// local delarations
	double x1, x2;
	vector<double> x;

	// quadratic formula
	if (!(b*b >= 4 * a*c && a != 0)) {
		throw "Error!";
	}
	
	x1 = (-b - sqrt((b*b) - (4 * a*c))) / (2 * a);
	x2 = (-b + sqrt((b*b) - (4 * a*c))) / (2 * a);

	// add the two values to the vector to send back to the original function
	x.push_back(x1);
	x.push_back(x2);

	return x;
}


/*Enter in the value for a: 1
Enter in the value for b: 20
Enter in the value for c: 100
Error data does not follow this condition b*b > 4 * a*c && a != 0Error!
*/

/*
//***PART D***
//Precondition: b2>4ac and a!=0
//Postcondition: the two real roots are returned in a vector
vector<int> calcQuadratic(double a, double b, double c) {
	// local delarations
	double x1, x2;
	vector<int> x;

	// quadratic formula
	assert(b*b > 4 * a*c && a != 0);
	x1 = (-b - sqrt((b*b) - (4 * a*c))) / (2 * a);
	x2 = (-b + sqrt((b*b) - (4 * a*c))) / (2 * a);

	// add the two values to the vector to send back to the original function
	x.push_back(x1);
	x.push_back(x2);

	return x;

}
/* EXAMPLE OUTPUT
Enter in the value for a: 1
Enter in the value for b: 20
Enter in the value for c: 100
Assertion failed: b*b > 4 * a*c && a !=0, file c:\users\rjbec\source\repos\advancedcplusplus\rjbconsole\rjbconsole\lab1.cpp, line 38
*/
