/*Author: Robert Beckwith
Class: CIS 2542
Date: 10/18/17
FileName: postfixEval.cpp
Descr:
	program to evaluate post fix operators with a stack*/

#include <stack>
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <iostream>
#include <cstring>
#include <string>
#include <cassert>
using namespace std;

//prototype
void evaluate_stack_tops(stack<double>& numbers, stack<char>& operations);

int main() {
	double answer;
	bool stop = false;
	bool firstRun = true;
	stack<double> numbers;

	//read the data and evaluate the expression
	cout << "Enter the postfix expression: ";

	// consts for the operators
	const char ADDITION = '+';
	const char SUBRACTION = '-';
	const char MULTIPLICATION = '*';
	const char DIVISION = '/';
	const char DECIMAL = '.';

	string expression; //hold the entire expression will be built off of from the cins
	stack<char> operations; // stack for the operators
	double number;
	char symbol;
	string str1,str; //temp string to get rid of extra zeros


	while (cin && !stop) {
		
		//check if the input is a <CR> if it is set stop to true
		if (cin.peek() == '\n') {
			stop = true;
		}
		while (cin && cin.peek() != '\n') // loop through till the newline is hit
		{
			//check for digit or decimal point
			if (isdigit(cin.peek()) || (cin.peek() == DECIMAL))
			{
				cin >> number; // read in the number and then add it to the stack
				numbers.push(number);
				str = to_string(number); // convert the read float to a string
				str.erase(str.find_last_not_of('0') + 1, string::npos); // strip the 0s of the float 
				str.erase(str.find_last_not_of('.') + 1, string::npos); // strip the decimal off the float
				expression += str;// add the number to the expression string
				expression += " ";// add a space after the operator to rebuild the expression
			}
			else if (cin.peek() == ADDITION || cin.peek() == DIVISION || cin.peek() == MULTIPLICATION || cin.peek() == SUBRACTION)
			{
				cin >> symbol; // read in the symbol add it to the stack then evaluate
				operations.push(symbol);
				expression += symbol; //append the data to the back of the expression for printing
				expression += " ";  // add a space to the rebuilt expression
				evaluate_stack_tops(numbers, operations);
			}
			else
				cin.ignore();

		}
		// set the first run to false and output the expression
		firstRun = false;
		cout << expression;

		if (!numbers.empty()) { // clear the stack if it isn't empty
			cout << "==> evaluates to " << numbers.top() << endl;
			cout << str1;
			cin.clear();
		}
		//clear the stack if it isn't empty
		while (!numbers.empty())
			numbers.pop();
		
		expression = "";
		if (!firstRun && !stop)
			cout << "Enter another postfix expression or <CR> to end: ";
		cin.ignore(); // needs to be here to reset the stream because clear doesn't do its job
	}

	return EXIT_SUCCESS;
}
void evaluate_stack_tops(stack<double>& numbers, stack<char>& operations)
{
	double operand1, operand2;
	//assert that there is enough items to evaluate
	assert(numbers.size() >= 2);
	operand2 = numbers.top();
	numbers.pop();
	operand1 = numbers.top();
	numbers.pop();

	// add the result of the two numbers before the operator onto the stack
	switch (operations.top())
	{
	case '+': numbers.push(operand1 + operand2);
		break;
	case '-': numbers.push(operand1 - operand2);
		break;
	case '*': numbers.push(operand1 * operand2);
		break;
	case '/':
		//assert so there isn't a divide by zero error
		assert(operand2 != 0);
		numbers.push(operand1 / operand2);
		break;
	}
	operations.pop();
}

/*SAMPLE OUTPUTS
***SAMPLE RUN***
Enter the postfix expression: .5 .25 /
0.5 0.25 / ==> evaluates to 2
Enter another postfix expression or <CR> to end: 2.5 3.5 + 8.5 *
2.5 3.5 + 8.5 * ==> evaluates to 51
Enter another postfix expression or <CR> to end: 5 3 2 * + 4 - 5 +
5 3 2 * + 4 - 5 + ==> evaluates to 12
Enter another postfix expression or <CR> to end: 20 3 5 * + 5 /
20 3 5 * + 5 / ==> evaluates to 7
Enter another postfix expression or <CR> to end: 2 3 /
2 3 / ==> evaluates to 0.666667
Enter another postfix expression or <CR> to end:
Press any key to continue . . .

***DIVIDE BY ZERO***
Enter the postfix expression: 5 0 /
Assertion failed: operand2 != 0, file c:\users\cod_user\desktop\postfixeval.cpp, line 108

*** ILL FORMED EXPRESSION ***
Enter the postfix expression: 3 2 + *
Assertion failed: numbers.size() >= 2, file c:\users\cod_user\desktop\postfixeval.cpp, line 94
Press any key to continue . . .
*/