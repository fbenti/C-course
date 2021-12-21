#include <iostream>
#include "ex03-library.h"
using namespace std;

// Do not modify
Hotel::Hotel() {
    this->roomNames.push_back("Daisy");
    this->roomOccupancy["Daisy"] = {"Alan Smithee", "xyz890"};

    this->roomNames.push_back("Geranium");

    this->roomNames.push_back("Lotus");
    this->roomOccupancy["Lotus"] = {"Kathryn Bigelow", "456abc"};

    this->roomNames.push_back("Orchid");
    this->roomOccupancy["Orchid"] = {"Alan Smithee", "abc123"};

    this->roomNames.push_back("Tulip");
    this->roomOccupancy["Tulip"] = {"Denis Villeneuve", "123xyz"};
}

// Task 3(a).  Implement this method
void Hotel::addRoom(string name) {
    bool found = false;
    for (int i = 0; i < this->roomNames.size(); i++) {
        if (this->roomNames[i] == name) {
            found = true;
            break;
        }
    }
    if (!found)
        this->roomNames.push_back(name);
}

// Task 3(b).  Implement this method
void Hotel::addGuest(string roomName, string guestName, string guestId) {
    bool found = false;
    for (int i = 0; i < this->roomNames.size(); i++) {
        if (this->roomNames[i] == roomName) {
            found = true;
            break;
        }
    }
    if (!found)
        return;

    // if already that ID in other rooms
    for (auto p: this->roomOccupancy) {
        if (p.second.id == guestId) {
            return;
        }
    }
    
    // otherwise
    this->roomOccupancy[roomName].name = guestName;
    this->roomOccupancy[roomName].id = guestId;
    return;
}

// Task 3(c).  Implement this method
void Hotel::findRoomByGuest(string guestName, string guestId) {
    for (auto it = this->roomNames.begin(); it != this->roomNames.end(); it++) {
        if (this->roomOccupancy.find(*it) != this->roomOccupancy.end()) {
            if (guestName == "*" && guestId == "*") {
                cout << *it << endl;
            }
            else if (guestName != "*" && guestId == "*") {
                for (auto p: this->roomOccupancy) {
                    if (p.second.name == guestName) {
                        cout << p.first << endl;
                    }
                }
                return;
            }
            else {
                for (auto p: this->roomOccupancy) {
                    if (p.second.id == guestId) {
                        cout << p.first << endl;
                    }
                }
                return;
            }
        }
    }
}

// Do not modify
void Hotel::display() {
    for (auto it = this->roomNames.begin(); it != this->roomNames.end(); it++) {
        cout << "Room '" << *it << "' is ";
        if (this->roomOccupancy.find(*it) == this->roomOccupancy.end()) {
            cout << "empty" << endl;
        } else {
            cout << "occupied by " << this->roomOccupancy[*it].name;
            cout << " (id: " << this->roomOccupancy[*it].id << ")" << endl;
        }
    }
}
