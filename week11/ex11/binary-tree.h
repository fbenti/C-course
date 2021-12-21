#ifndef __fibonacci_trees__
#define __fibonacci_trees__

using namespace std;

class Tree {
public:
    Tree();
    Tree(unsigned int value);
    ~Tree();

    unsigned int size(void);
    unsigned int depth(void);
    unsigned int leaves(void);
    void traverse_pre(void);

private:
    bool empty;     // Flag to specify it tree is empty
    int content;    // Content of the node
    Tree *left;     // Pointer to left sub-tree
    Tree *right;    // Pointer to right sub-tree
};

# endif //__fibonacci_trees_