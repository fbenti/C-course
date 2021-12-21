#include <iostream>
#include "binary-trees.h"

using namespace std;

Tree::Tree() {
    empty = true;
    left = nullptr;
    right = nullptr;
}

// This is the main method solving the assignment's problem
// It is a constructor with one parameter
// This will build the tree we are looking for
Tree::Tree(unsigned int n) {
    empty = false;

    // For Fib(0) or Fib(1) we just build a tree with just one node
    if (n<=1) {
        content = 1;
        left = new Tree();
        right = new Tree();
        return;
    }

    // Otherwise, we recursively build sub-trees for Fib(n-1), Fib(n-2)
    left = new Tree(n-1);
    right = new Tree(n-2);
    // ... and use their values to update the current node
    content = left->content + right->content;
    return;
}

Tree::~Tree() {
    if (empty) return;
    delete left;
    delete right;
}

int Tree::size(void) {
    // The size of an empty tree is 0
    if (empty) return 0;

    // The size of a non-empty tree is 1 (the root) + the size of the subtrees
    return 1 + left->size() + right->size();
}

int Tree::height(void) {
    // The height of an empty tree is 0
    if(empty) return 0;

    // The height of a non-empty tree is 1 (the root)
    // plus the maximum of the heights of the subtrees
    return 1 + max(left->height(), right->height());
}

// The number of leaves can be computed in a similar fashion to
// size() and height()

int Tree::leaves(void) {
    if (empty) return 0;

    // Leaves are trees with empty sub-trees
    if (left->empty && right->empty) return 1;

    return left->leaves() + right->leaves();
}

// Methods that implement the three (in, pre, post) traversal methods

void Tree::traverse_pre(void) {
    if(empty) return;
    cout << content << " " ;
    left->traverse_pre();
    right->traverse_pre();
}

void Tree::traverse_in(void) {
    if(empty) return ;
    left->traverse_in();
    cout << content << " " ;
    right->traverse_in();
}

void Tree::traverse_post(void) {
    if(empty) return ;
    left->traverse_post();
    right->traverse_post();
    cout << content << " " ;
}

