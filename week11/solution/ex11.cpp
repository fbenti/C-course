#include <iostream>

// The solution is based on a slight modification of the
// library of trees we saw in the lecture
#include "binary-trees.h"

int main(){
    Tree *t;
    unsigned int n;

    cin >> n;
    // Create a tree using the new constructor Tree(unsigned int)
    // which builds the tree we are looking for
    t = new Tree(n);

    cout << "Call tree in pre-order: ";
    t->traverse_pre(); cout << endl;
    cout << "Call tree size: " << t->size() << endl;
    cout << "Call tree depth: " << t->height()<< endl;
    cout << "Call tree leafs: " << t->leaves()<< endl;

    return 0;
}
