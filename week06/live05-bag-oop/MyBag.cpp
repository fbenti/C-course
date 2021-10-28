#include "MyBag.h"
#include <iostream>
#include <fstream>
#include <stack>
#include <algorithm>

using namespace std;

myBag::myBag(int x){
    vector<unsigned int> a(x);
    data = a;
}

myBag::myBag(int x, int y){
    vector<unsigned int> a(x,y);
    data = a;
}

void myBag::add(int x){
    // Insert at the beginning
    data.insert(data.begin(),x);
    // Insert at the end (more efficient)
    // b.push_back(x);
}

void myBag::del(int x){
    for(vector<unsigned int>::iterator i=data.begin(); i!=data.end(); i++){
        if (*i==x){
            data.erase(i);
            return;
        }
    }
}

void myBag::sortIt(void){
    // sort a vector between to positions
    sort(data.begin(),data.end());
}

void myBag::makeSet(void){
    sort(data.begin(),data.end());
    for (vector<unsigned int>::iterator i=data.begin(); i!=data.end(); i++) {
        while (i+1!=data.end() && *i==*(i+1)) {
            data.erase(i+1);
        }
    }
}

void myBag::read(string s){
    ifstream f;
    string n;

    // Open file s into the filestream f
    f.open(s);
    // Check if the file exists
    if(f.fail()) return;
    // While we can read "words"...
    while (true) {
        f >> n;
        if (f.fail()) {
            break;
        }
        performAction(actions::add, n);
    }
    f.close();
}

void myBag::flip(void) {
    stack<unsigned int> my_pile;
    // Dump the myBag into the stack
    while(!data.empty()) {
        my_pile.push(data[0]);
        data.erase(data.begin());
    }
    // Dump the stack back into the myBag
    while(!my_pile.empty()) {
        data.push_back(my_pile.top());
        my_pile.pop();
    }
}

int myBag::pick(){ 
    int x = data[data.size()-1];
    data.erase(data.end()-1);
    return x;
}

bool myBag::empty() {
    return data.empty();
}

// Method to print the content of the myBag
void myBag::display() {
    cout << "The myBag is : ";
    // this is a simple example of how to use an iterator
    // to go through all the elements in a vector
    for (vector<unsigned int>::iterator i=data.begin(); i!=data.end(); i++) {
        // the iterator is used like a pointer
        // *i is used to de-reference the iterator/pointer
        cout << *i << " ";
    }
    cout << endl;
    return;
}

// this function deals with actions on a myBag
void myBag::performAction(actions::action a, string s) {
    string n;

    switch(a){

        case actions::add:
            add(stoi(s));
            break;

        case actions::del:
            del(stoi(s));
            break;

        case actions::sortIt:
            sortIt();
            break;

        case actions::makeSet:
            makeSet();
            break;

        case actions::read:
            read(s);
            break;

        case actions::flip:
            flip();
            break;

        case actions::none:
            break;

        default:
            break;

    }
}
