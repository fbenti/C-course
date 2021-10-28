//============================================================================
// Name        : live05-bag-oop.cpp
// Description : Object-oriented implementation of bag
//============================================================================

#include <iostream>
#include "MyBag.h"
using namespace std;
using namespace actions;

/* Sample of supported commands:
  newBag
  newBag
  add 0 1
  add 1 10
 */

int main() {
    vector<myBag> bags;
    string my_act_str;
    action my_act;
    string object;
    int bag_num;

    while (true) {
        // Display the contents of the current bags
        for (int i = 0; i < bags.size(); i++) {
            cout << "BAG #" << i << " = ";
            bags[i].display();
        }

        cout << "What's next? Choose between:" << endl;
        cout << "newBag | fuse | add <bag> <x> | del <bag> <x> | sortIt <bag> | makeSet <bag> | read <bag> <file> | flip <bag>" << endl;
        cin >> my_act_str;

        if (cin.fail()) {
            cout << "Goodbye!" << endl;
            return 0;
        }

        my_act = str2action(my_act_str);

        if (my_act == newBag) {
            bags.push_back(*new myBag(0));
            continue;
        }

        if (my_act == fuse) {
            while(bags.size()>1){
                while(!bags[bags.size()-1].empty()) {
                    bags[0].add(bags[bags.size()-1].pick());
                }
                bags.erase(bags.end()-1);
            }
            continue;
        }

        cin >> bag_num;
        // Some actions require an extra argument
        if (my_act == add || my_act == del || my_act == read){
            cin >> object;
        }
        
        // Resolve the action
        if (bag_num >= 0 && bag_num < bags.size()) {
            bags[bag_num].performAction(my_act, object);
        }
    }

    return 0;
}
