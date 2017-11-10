/*
Robert Beckwith
11/9/17
expression_tree.h
CIS 2542
Descr:
	Specification file for expression tree which will evaluate postfix operators with a tree
*/
#include <iostream>
#include <stack>
using namespace std;

class expression_tree {
private:
	exp_node* root;
	stack<int> numbers;
public:
	//constructors
	expression_tree :: expression_tree();
	expression_tree::expression_tree(istream&);
	expression_tree::~expression_tree(); // destructor
	
	int evaluate(exp_node*);

	exp_node* get_root() {
		return root;
	}
};

struct exp_node {
	int number;
	char op;
	exp_node* left_field;
	exp_node* right_field;

	exp_node() { // default values
		number = 0;
		op = ' ';
		left_field = nullptr;
		right_field = nullptr;

	}
};


// implementation

expression_tree::expression_tree() {
	exp_node* root = new exp_node(); // create blank tree
}

expression_tree::expression_tree(istream& ins) {
	exp_node *cursor = get_root();
	bool done = false;
	if (get_root() == nullptr) // maybe change with root op and number == ' ' and == 0 respectively
	{
		exp_node* root = new exp_node(); // create a new node if there isn't one already
	}

	int number;
	char op;
	bool secondNode = false;
	do {
		
		//check if it is a digit
		if (isdigit(ins.peek())) {
			if (secondNode) {
				// create a new node to move up the tree
				exp_node* temp = root;
				exp_node* root = new exp_node();
				root->left_field = temp;
			}
			ins >> number;
			//populate left side if there isn't anything on the left side
			if (root->left_field == nullptr) {
				root->left_field = new exp_node();
				root->left_field->number = number;
			}
			else // populate the right side
			{
				root->right_field = new exp_node();
				root->right_field->number = number;
			}

		}
		else if (ins.peek() == '*' || ins.peek() == '+')
		{
			ins >> op; // read in the symbol and add it as the root node.
			root->op = op;
			secondNode = true; //Set this flag to true so the program knows to creat a new subtree
		}
		else
			ins.ignore();
	} while (ins);
}

int expression_tree::evaluate(exp_node* rt) { // recursively traverse the tree to evaluate it.
	int total;
	int number;
	int num1;
	int num2;
	if (rt != nullptr) { 
		//postorder recursively traverse the list
		total = evaluate(rt->left_field);
		total = evaluate(rt->right_field);

		//evaluate the one node with two links of the expression.
		if (rt->op == ' ') {
			numbers.push(rt->number);
		}
		else if (rt->op == '*') {
			num1 = numbers.top();
			numbers.pop();
			num2 = numbers.top();
			numbers.pop();
			total += num1 * num2;
		}
		else if (rt->op == '+') {
			num1 = numbers.top();
			numbers.pop();
			num2 = numbers.top();
			numbers.pop();
			total += num1 + num2;
		}
		return total;
	}
	
}