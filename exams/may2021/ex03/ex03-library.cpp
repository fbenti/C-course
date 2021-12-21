#include <iostream>
#include "ex03-library.h"
using namespace std;

// Do not modify
GroceryList::GroceryList() {
    this->items.push_back("Lasagne");
    this->itemsInfo["Lasagne"] = {1, "With eggs if available"};

    this->items.push_back("Salmon");
    this->itemsInfo["Salmon"] = {500, "Smoked if available"};

    this->items.push_back("Spinach");
    this->itemsInfo["Spinach"] = {300, "Fresh"};

    this->items.push_back("Dessert");
    this->itemsInfo["Dessert"] = {8, "Maybe lagkage?"};
}

// Task 3(a).  Implement this method
void GroceryList::add(string name, unsigned int quantity, string notes) {
    auto it = this->itemsInfo.find(name);
    if (it == this->itemsInfo.end()) {
        this->items.push_back(name);
        this->itemsInfo.insert({name,Info{quantity,notes}});
    }
    else {
        this->itemsInfo[name].quantity += quantity;
        this->itemsInfo[name].notes += ';' + notes;
    }
}

// Task 3(b).  Implement this method
bool GroceryList::remove(string name, unsigned int quantity) {
    auto it = this->itemsInfo.find(name);
    if (it == this->itemsInfo.end()) {
        cout << "here2" <<endl;
        return false;
    }
    else {
        if (this->itemsInfo[name].quantity < quantity){
            cout << this->itemsInfo[name].quantity << endl;    
            return false;
        }

         if (this->itemsInfo[name].quantity == quantity) {
            cout << "here1" <<endl;
            cout << name << endl;
            this->itemsInfo.erase(name);
            for (int it = 0; it < this->items.size(); it++){
                if (this->items[it] == name)
                    this->items.erase(this->items.begin() + it);
                    return true;
            }
        }
        this->itemsInfo[name].quantity -= quantity;
        return true;
    }
    // for (auto it = this->items.begin(); it != this->items.end(); it++) {
    //     if (*it == name) {
    //         Info &item = this->itemsInfo[*it];
    //         if (item.quantity < quantity) {
    //             return false;
    //         }
    //         if (item.quantity == quantity) {
    //             itemsInfo.erase(name);
    //             items.erase(it);
    //             return true;
    //         }
    //         item.quantity -= quantity;
    //         return true;
    //     }
    // }
    // If we are here, we did not find the item
    return false;
}

// Task 3(c).  Implement this method
bool GroceryList::copyEntry(string name, string newName) {
    auto it = this->itemsInfo.find(name);
    if (it == this->itemsInfo.end()) {
        return false;
    }
    it = this->itemsInfo.find(newName);
    if (it != this->itemsInfo.end()) {
        return false;
    }
    this->items.push_back(newName);
    this->itemsInfo[newName] = this->itemsInfo[name];
    return true;
}

// Do not modify
void GroceryList::display() {
    // Write your code here
    for (auto it = this->items.begin(); it != this->items.end(); it++) {
        Info &item = this->itemsInfo[*it];
        cout << "name='" << *it << "'; ";
        cout << "quantity=" << item.quantity << "; ";
        cout << "notes='" << item.notes << "'" << endl;
    }
}