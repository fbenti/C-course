#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

typedef vector<unsigned int> bag;

void performAction(bag &m, bag &a, bag &b); // Perform an action

int main() {
    bag myBag, a, b;
    string set, num;
    while (true) {
        cin >> set;
        if (cin.fail()) {
            break;
        }
        
        cin >> num;
        if (cin.fail()) {
            break;
        } 
        
        if (set == "a") a.push_back(stoi(num));
        else if (set == "b") b.push_back(stoi(num));
    }
    performAction(myBag, a, b);
    return 0;
}

void performAction(bag &m, bag &a, bag &b) {
    int a_size = a.size();
    int b_size = b.size();
    int max;
    if (a_size > b_size) 
        max = a_size;
    else max = b_size;

    for(int i=0; i< max; i++) {
        if(i < a_size)
            m.push_back(a[i]);
        if(i < b_size)
            m.push_back(b[i]);
    }

    for (auto e: m) {
        cout << e << " ";
    }
    cout << endl;
}

