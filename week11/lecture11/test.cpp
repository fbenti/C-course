// Representing arithmetic expressions using trees
#include <iostream>

#include "arithmetic-syntax-tree.h"

using namespace std;

int main() {
    // We want to represent the expression:  ((2 * 3) + (4 * 5)) + 1
    //
    //       +      // Leftmost "+" in the expression (called 'add2' below)
    //      / \
    //     +   1    // Rightmost "+" in the expression (called 'add1' below)
    //    / \
    //   *   *      // Multiplications (called 'mult1' and 'mult2' below)
    //  / \ / \
    //  2 3 4 5

    // Allocating bunch of pointer to leaf nodes
    ArithmeticSyntaxTree *one, *two, *three, *four, *five;
    // Allocating bunch of pointer to internal leaf nodes
    ArithmeticSyntaxTree *add1, *add2, *mult1, *mult2;

    // First, we create the leaf nodes for the constants in the expression
    one = new ArithmeticSyntaxTree(1);
    two = new ArithmeticSyntaxTree(2);
    three = new ArithmeticSyntaxTree(3);
    four = new ArithmeticSyntaxTree(4);
    five = new ArithmeticSyntaxTree(5);

    // Then, we create the internal nodes bottom-up, from leaves to root
    mult1 = new ArithmeticSyntaxTree(Mult, two, three);
    mult2 = new ArithmeticSyntaxTree(Mult, four, five);
    add1 = new ArithmeticSyntaxTree(Add, mult1, mult2);
    add2 = new ArithmeticSyntaxTree(Add, add1, one);

    // For clarity, we alias 'add2' as 'root'
    ArithmeticSyntaxTree *root = add2;

    cout << "The size of the tree is: " << root->size() << endl;
    cout << "The height of the tree is: " << root->height() << endl;
    cout << "The number of leaves of the tree is: " << root->leaves() << endl;
    
    cout << endl << "Representation in prefix notation:" << endl;
    root->traversePre();
    cout << endl;

    cout << endl << "Representation in infix notation:" << endl;
    root->traverseIn();
    cout << endl;

    cout << endl << "The expression evaluates to: " << root->evaluate();
    cout << endl;

    delete root;
    return 0;
}
