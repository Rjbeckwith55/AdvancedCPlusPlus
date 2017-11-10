/*
Robert Beckwith
11/9/17
expression_tree.h
CIS 2542
Descr:
	Specification file for expression tree which will evaluate postfix operators with a tree
*/
#include <iostream>
using namespace std;

class expression_tree {
private:
	exp_node* root;
public:
	expression_tree :: expression_tree();
	expression_tree::expression_tree(istream&);
	expression_tree::~expression_tree(); // destructor
	
	int evaluate(exp_node);

	exp_node* get_root() {
		return root;
	}
};

struct exp_node {
	int number;
	char op;
	exp_node* left_field;
	exp_node* right_field;
};

// implementation

expression_tree::expression_tree() {
	exp_node* root = new exp_node(); // create blank tree
}

expression_tree::expression_tree(istream& ins) {
	exp_node* root = new exp_node();
	int number;
	char op;
	if (isdigit(ins.peek())) {
		
		ins >> number;
		//recursively populate
		numbers.push(number); // REPLACE: with Tree
	}
	else if (ins.peek() == ADDITION || ins.peek() == DIVISION || ins.peek() == MULTIPLICATION || ins.peek() == SUBRACTION)
	{
		ins >> op; // read in the symbol add it to the stack then evaluate
		operations.push(op); //REPLACE: with Tree
		expression += symbol; //append the data to the back of the expression for printing
		evaluate_stack_tops(numbers, operations);
	}
	else
		ins.ignore();
}
int expression_tree::evaluate(exp_node root) { // recursively traverse the tree to evaluate it.

}