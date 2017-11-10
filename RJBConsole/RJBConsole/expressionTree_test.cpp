// CIS2542-002 Lab #10
// File: expressionTree_test.cpp
// Desc: This program tests the implementation
//       of a postfix evaluation tree consisting of
//       integers and the * and + operators.

#include "expression_tree.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

// displays binary expression tree
void pretty_print(const exp_node* node_ptr, int depth = 5)
// Library facilities used: iomanip, iostream
{
	cout << setw(4 * depth) << ""; // indentation
	if (node_ptr == nullptr) {
		// fallen off the tree
		cout << "[Empty]" << std::endl;
	}
	else if (node_ptr->left_field == nullptr) {
		// a leaf with numeric data
		cout << node_ptr->number;
		cout << " [leaf]" << std::endl;
	}
	else {
		// a nonleaf with operator
		cout << node_ptr->op << std::endl;
		pretty_print(node_ptr->right_field, depth + 1);
		pretty_print(node_ptr->left_field, depth + 1);
	}
}

// main interactive testing function
int main() {
	cout << "Enter the postfix expression: ";
	while (cin && cin.peek() != '\n') {
		// allocate memory
		expression_tree *expTree = new expression_tree(cin);
		// display binary tree
		pretty_print(expTree->get_root());
		cout << "\n\t==> evaluates to " << evaluate(expTree->get_root()) << endl;
		// release memory
		delete expTree;
		// clear input stream
		cin.ignore();
		cout << "Enter another postfix expression or <Enter> to end: ";
	}
	cout << "This concludes the Binary Tree Math Postfix Expression program!\n\n";
	return EXIT_SUCCESS;
}