#ifndef __arithmetic_syntax_tree__
#define __arithmetic_syntax_tree__

// Type of operation.  Here, 'Const' represents a constant value (leaf node)
enum NodeType { Const, Add, Mult };

class ArithmeticSyntaxTree {
public:
    // Constructor for leaf nodes (constants)
    ArithmeticSyntaxTree(unsigned int value);

    // Constructor for internal nodes (left + right, or left * right)
    ArithmeticSyntaxTree(NodeType type, ArithmeticSyntaxTree *left,
                                        ArithmeticSyntaxTree *right);

    ~ArithmeticSyntaxTree(); // Destructor

    unsigned int size();   // Size of the tree
    unsigned int height(); // Height of the tree
    unsigned int leaves(); // Number of leaves/constants in the tree
    void traversePre();    // Print nodes in pre-order (prefix notation)
    void traverseIn();     // Print nodes in in-order (infix notation)
    unsigned int evaluate();        // Compute the expression represented in the tree

private:
    NodeType type;  // This is either Const, Add or Multiply
    int value;      // If the node is a leaf (type == Const), this is its value
    ArithmeticSyntaxTree *left;  // Pointer to left sub-expression tree, only used igf type == Add or Mul
    ArithmeticSyntaxTree *right; // pointer to right sub-expression tree, only used igf type == Add or Mul
};

#endif // __arithmetic_syntax_tree__
