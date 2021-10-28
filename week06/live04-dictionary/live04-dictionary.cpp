//============================================================================
// Name        : live04-dictionary.cpp
// Description : Custom implementation of a map/dictionary
//============================================================================

#include <iostream>
#include "myMap.h"

using namespace std;

int main() {
    myMap dan2eng("Danish-to-English");
    myMap *eng2dan=new myMap("English-to-Danish");
    eng2dan->insert("black", "sort");

    // This would cause a compilation error
    // dan2eng.entries.push_back("lala");

    dan2eng.insert("groen", "black");
    dan2eng.insert("blaa", "blue");
    dan2eng.insert("roed", "red");
    dan2eng.insert("groen", "green");

    cout << "groen -> " << dan2eng.find("groen") << endl;
    cout << "black -> " << eng2dan->find("black") << endl;

    delete eng2dan;

    return 0;
}
