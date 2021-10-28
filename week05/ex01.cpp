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
    sort(a.begin(), a.end()); 
    sort(b.begin(), b.end());
    m.clear();
    for (auto e: a) {
        m.push_back(e);
        cout << e << " ";
    }
    for (auto e: b) {
        m.push_back(e);
        cout << e << " ";
    }
    cout << endl;
}
