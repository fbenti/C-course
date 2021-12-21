#include <iostream>

#include "arithmetic-syntax-tree.h"

using namespace std;

// Internal function to print the contents of a node (used below)
void printNode(NodeType type, int value) {
    switch (type) {
    case Const:
        cout << value;
        break;
    case Add:
        cout << "+";
        break;
    case Mult:
        cout << "*";
        break;
    default:
        throw logic_error("BUG! This should not happen!");
    }
}

// Constructor for leaf nodes (constants)
ArithmeticSyntaxTree::ArithmeticSyntaxTree(unsigned int value) {
    this->type = Const;
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
}

// Constructor for internal nodes (left + right, or left * right)
ArithmeticSyntaxTree::ArithmeticSyntaxTree(NodeType type,
                                           ArithmeticSyntaxTree *left,
                                           ArithmeticSyntaxTree *right) {
    if (type == Const) {
        throw logic_error("BUG: this constructor is for Add and Mult nodes!");
    }
    if ((left == nullptr) || (right == nullptr)) {
        throw logic_error("BUG: Add and Mult nodes must have 2 descendants!");
    }
    this->type = type;
    this->value = 0;
    this->left = left;
    this->right = right;
}

// Destructor.  We delete the left and right descendants
ArithmeticSyntaxTree::~ArithmeticSyntaxTree() {
    // Uncomment the following line see the order in which nodes are destroyed
    // cout << "Destroying: "; printNode(this->type, this->value); cout << endl;
    if (this->left != nullptr) {
        delete this->left;
    }
    if (this->right != nullptr) {
        delete this->right;
    }
}

// Size of a tree
unsigned int ArithmeticSyntaxTree::size(void) {
    switch (this->type) {
    case Const:
        // The size of a constant node is 1
        return 1;
    case Add:
        // same as Mult
    case Mult:
        // The size of a compound expression is 1 + size of descendent trees
        return 1 + this->left->size() + this->right->size();
    default:
        throw logic_error("BUG! This should not happen!");
    }
}

// Height of a tree: from root to the farthest leaf
unsigned int ArithmeticSyntaxTree::height(void) {
    switch (this->type) {
    case Const:
        // The height of a constant node is 1
        return 1;
    case Add:
    case Mult:
        // The height of a compound expression is 1 + max height of descendants
        return 1 + max(this->left->height(), this->right->height());
    default:
        throw logic_error("BUG! This should not happen!");
    }
}

// The number of leaves can be computed in a similar fashion to
// size() and height()
unsigned int ArithmeticSyntaxTree::leaves(void) {
    switch (this->type) {
    case Const:
        // The number of leaves of a constant node is 1
        return 1;
    case Add:
    case Mult:
        // The leaves of a compound expression is the sum of descendants leaves
        return this->left->leaves() + this->right->leaves();
    default:
        throw logic_error("BUG! This should not happen!");
    }
}

// Pre-order traversal methods: first print a node, then keep traversing
void ArithmeticSyntaxTree::traversePre(void) {
    printNode(this->type, this->value);

    if (this->type == Const) {
        return; // Nothing more to traverse
    }

    cout << "(";
    this->left->traversePre();
    cout << ", ";
    this->right->traversePre();
    cout << ")";
}

// In-order traversal method: first traverse the left descendant (unless we
// have reached a leaf), then print the current node, then traverse the right
// descendant
void ArithmeticSyntaxTree::traverseIn(void) {
    if (this->type == Const) {
        printNode(this->type, this->value);
        return;
    }

    cout << "(";
    this->left->traverseIn();
    cout << ") ";

    printNode(this->type, this->value);

    cout << " (";
    this->right->traverseIn();
    cout << ")";
}

// Compute the value of the expression represented in the tree
unsigned int ArithmeticSyntaxTree::evaluate() {
    switch (this->type) {
    case Const:
        return this->value;
    case Add:
        return this->left->evaluate() + this->right->evaluate();
    case Mult:
        return this->left->evaluate() * this->right->evaluate();
    default:
        throw logic_error("BUG! This should not happen!");
    }
}