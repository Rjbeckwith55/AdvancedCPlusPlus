/*
Robert Beckwith
11/9/17
expression_tree.h
CIS 2542
Descr:
	Specification file for expression tree which will evaluate postfix operators with a tree
*/
#include <iostream>
#include <queue>
using namespace std;

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

class expression_tree {
private:
	exp_node* root = nullptr;
public:
	//constructors
	expression_tree::expression_tree();
	expression_tree::expression_tree(istream&);
	expression_tree::~expression_tree(); // destructor

	friend int evaluate(exp_node*);

	void tree_clear(exp_node*);

	exp_node* get_root() {
		return root;
	}
};




// implementation
expression_tree::~expression_tree() {
	queue<exp_node*> nodes;
	nodes.push(root);

	while (!nodes.empty())
	{
		exp_node* temp = nodes.front();
		nodes.pop();
		if (temp->left_field != nullptr)
		{
			nodes.push(temp->left_field);
		}
		if (temp->right_field != nullptr)
		{
			nodes.push(temp->right_field);
		}
		delete temp;
	}
}

//void expression_tree::tree_clear(exp_node* rt) {
//	//exp_node* child;
//	//recursively delete all the nodes
//	if (rt != nullptr)
//	{
//		tree_clear(rt->right_field);
//		tree_clear(rt->right_field);
//		delete rt;
//		rt = nullptr;
//	}
//}


//default contructor
expression_tree::expression_tree() {
	exp_node* root = new exp_node(); // create blank tree
}

expression_tree::expression_tree(istream& ins) {
	root = new exp_node();
	exp_node *cursor = root;
	bool done = false;

	int number;
	char op;
	bool secondNode = false;
	do {

		//check if it is a digit
		if (isdigit(ins.peek())) {
			if (secondNode) {
				// create a new node to move up the tree
				exp_node* temp = root;
				root = new exp_node();
				root->left_field = temp;
			}
			ins >> number;
			//populate left side if there isn't anything on the left side
			if (root->left_field == nullptr) { // check for default values...
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
	} while (ins.peek() != '\n');
}

int evaluate(exp_node* rt) { // recursively traverse the tree to evaluate it.
	if (rt->left_field == nullptr && rt->right_field == nullptr) {
		return rt->number;
	}
	//postorder recursively traverse the list
	else if (rt->op == '+') {
		return evaluate(rt->left_field) + evaluate(rt->right_field);
	}
	else if (rt->op == '*') {
		return evaluate(rt->left_field) * evaluate(rt->right_field);
	}

}
/*Enter the postfix expression:  1 2 + 4 * 3 +
                    +
                        3 [leaf]
                        *
                            4 [leaf]
                            +
                                2 [leaf]
                                1 [leaf]

        ==> evaluates to 15
Enter another postfix expression or <Enter> to end: 3 7 + 14 *
                    *
                        14 [leaf]
                        +
                            7 [leaf]
                            3 [leaf]

        ==> evaluates to 140
Enter another postfix expression or <Enter> to end:
This concludes the Binary Tree Math Postfix Expression program!

Press any key to continue . . .*/
