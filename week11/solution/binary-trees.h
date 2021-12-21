#ifndef __fibonacci_trees__
#define __fibonacci_trees__

using namespace std;

class Tree {
    
public:
    Tree();                     // Constructor
    Tree(unsigned int b);       // Constructor for Fibonacci(n)
    ~Tree();                    // Destructor
    int size(void);             // Size of the tree
    int height(void);           // Height of the tree
    int leaves(void);           // Number of leaves the tree
    void traverse_pre(void);    // Print nodes in pre-order
    void traverse_in(void);     // Print nodes in in-order
    void traverse_post(void);   // Print nodes in post-order
    
private:
    bool empty;     // Flag to specify it tree is empty
    int content;    // Content of the node
    Tree *left;     // Pointer to left sub-tree
    Tree *right;    // Pointer to right sub-tree
};

#endif // __fibonacci_trees__
