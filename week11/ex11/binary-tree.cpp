#include <iostream>
#include "binary-tree.h"

using namespace std;

Tree::Tree() {
    empty = true;
    left = nullptr;
    right = nullptr;
}

// This is the main method solving the assignment's problem
// It is a constructor with one parameter
// This will build the tree we are looking for
Tree::Tree(unsigned int n){
    empty = false;

    // For Fib(0) or Fib(1) we just build a tree with one node
    if (n<=1) {
        this->content = 1;
        left = new Tree();
        right = new Tree();
        return;
    }

    // Otherwise, we recusively build sub-tree Fid(n-1), Fib(n-2)
    this->left = new Tree(n-1);
    this->right = new Tree(n-2);
    // use their value to update the current node
    this->content = this->left->content + this->right-> content;
    return;
}

Tree::~Tree() {
    if (this->empty) return;
    delete this->left;
    delete this->right;
}

unsigned int Tree::size(void) {
    // Size of empty tree
    if (this->empty) {
        return 0;
    }
    return 1 + this->left->size() + this->right->size();
}

unsigned int Tree::depth(void) {
    if (this->empty) {
        return 0;
    }
    return 1 + max(this->left->depth(), this->right->depth());
}

unsigned int Tree::leaves(void) {
    if (this->empty) {
        return 0;
    }
    if (left->empty && right->empty) return 1;

    return this->left->leaves() + this->right->leaves();
}

void Tree::traverse_pre(void) {
    if (this->empty) return;
    cout << this->content << " ";
    this->left->traverse_pre();
    this->right->traverse_pre();
}