#include <iostream> 
#include "binary-tree.h"
using namespace std;

int main() {
    Tree *t;
    unsigned int n;

    cin >> n;
    t = new Tree(n);

    cout << "Call tree in pre-order: ";
    t->traverse_pre(); cout << endl;
    cout << "Call tree size: " << t->size() << endl;
    cout << "Call tree depth: " << t->depth()<< endl;
    cout << "Call tree leaves: " << t->leaves()<< endl;

    return 0;
}