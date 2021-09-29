#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

// Here we are saying that 'bag' is an ALIAS for a vector of unsigned ints
typedef vector<unsigned int> bag;

// Enumeration type for actions on the bag
enum action {add, del, sortIt, makeSet, readFile, flip, none};

// Here are several function prototypes; their definitions are after main()
action str2action(string s); // Translate a strings into an action
void display(const bag &b); // Display the content of a bag (used read-only)
void performAction(bag &b, action a, string arg); // Perform an action

int main() {
    bag myBag;
    string actStr;
    action act;
    string arg;

    while (true) {
        display(myBag);

        cout << "Enter an action between: add <x> | del <x> | sortIt | makeSet | readFile <filename> | flip" << endl;
        cout << "To terminate, press Ctrl+D (on Linux and Mac) or Ctrl+Z then <Return> (on Windows)" << endl;
        cin >> actStr;

        if (cin.fail()) {
            cout << "Goodbye!" << endl;
            return 0;
        }

        act = str2action(actStr); // convert the input into an action definfed as enum

        // Some actions require an extra argument
        if ((act == add) || (act == del) || (act == readFile)) {
            cin >> arg;
        }

        // Perform the action
        performAction(myBag, act, arg);
        cout << endl;
    }

    return 0;
}

// Translate a strings into an action
action str2action(string s) {
    if (s == "add") return add;
    if (s == "del") return del;
    if (s == "sortIt") return sortIt;
    if (s == "makeSet") return makeSet;
    if (s == "readFile") return readFile;
    if (s == "flip") return flip;
    cout << "WARNING: converting '" << s << "' into action 'none'" << endl;
    return none;
}

// Function to print the content of the bag.
// Notice that the bag is passed as a constant reference: it cannot be modified
void display(const bag &b) {
    cout << "The bag is now: ";
    // Here is a simple example of how to use modern C++ syntax
    // to go through all the elements in a vector
    for (auto e : b) {
        cout << e << " ";
    }
    cout << endl;

    // we can also use:
    // for (int i = 0; i < b.size(); i++){
    //     cout << b[i] << " ";
    // }
    // cout << endl;
    // or
    // vector<unsigned int>::const_iterator it;
    // bag::const_iterator it; // because bag is defined as an ALIAS
    // for(it = b.begin(); it != b.end(); it++){
    //     cout << *it << " ";
    // }
    // cout << endl;

    // There are several ways of iterating a vector
    // For example, using iterators the above could be written as follows
    // Notice that we use 'const_iterator': this is because 'b' is a reference
    // to a const bag.  A normal iterator could be exploited to modify the bag,
    // so C++ gives an error if we try to use it (try!)
    /*
    for(bag::const_iterator i = b.begin(); i != b.end(); i++) {
        // The iterator is used like a pointer
        // *i is used to de-reference the iterator/pointer
        cout << *i << " ";
    }
    */

    cout << endl;
}

// This function perform a given action 'a' on the bag.
// 'arg' is the argument of the action (sometimes unused)
void performAction(bag &b, action a, string arg) {    
    switch (a) {
        case add: {
            unsigned int x = stoi(arg); // Translate a string into an integer
            // The following line inserts at the beginning of the bag
            b.insert(b.begin(), x);
            // The following line appends at the end of the bag
            // b.push_back(x);
            break;
        }

        case del: {
            unsigned int x = stoi(arg); // Translate a string into an integer
            for (bag::iterator i = b.begin(); i != b.end(); i++) { // we don't need a CONST ITERATOR because we are not passing a the bag as a const
                if (*i == x) {
                    b.erase(i);
                    break;
                }
            }
            // for (int i = 0; i < b.size() ; i++){
            //     if (b[i] == x){
            //         b.erase(b.begin()+i);
            //         break;
            //     }
            // }
            break;
        }

        case sortIt: {
            // Sort vector elements between its initial and final positions
            sort(b.begin(), b.end());
            break;
        }

        case makeSet: {
            // Sort vector elements between its initial and final positions
            sort(b.begin(), b.end());
            for (bag::iterator i = b.begin(); i != b.end(); i++) {
                // We now delete duplicate elements by checking whether
                // the current element is equal to the successor
                while (i+1 != b.end() && *i == *(i+1)) {
                    b.erase(i+1);
                }
            }
            break;
        }

        case readFile: {
            string n; // Will contain data read from a file
            // Open file s into the filestream f
            ifstream f(arg); //input-file-stream
            // Check if the file exists
            if (f.fail()) {
                cout << "ERROR: could not open the file: " + arg << endl;
                break;
            }
            // Repeat until we can read whitespace-separated "words"...
            while (true) {
                // unsigned int x;
                // f >> x; // read from the file
                // if (f.fail()) {
                //     break;
                // }
                // b.push_back(x);
                f >> n;
                if (f.fail()) {
                    // We have reached the end of the file
                    break;
                }
                performAction(b, add, n);
            }
            // The following f.close() is optional:
            // the file will be closed when f exits the current scope
            // f.close();
            break;
        } // This is where f exits the scope, and the file is closed

        case flip: {
            stack<unsigned int> pile;
            // Dump the bag into a stack
            for(auto e : b){
                pile.push(e);
            }
            // Dump the stack into the bag again
            b.clear();
            while (!pile.empty()) {
                b.push_back(pile.top());
                pile.pop();
            }
            break;
        }

        case none: break;

        default:
            cout << "ERROR: invalid action: " << a << endl;
            break;
    }

    return;
}
