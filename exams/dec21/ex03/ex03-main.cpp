#include <iostream>
#include "ex03-library.h"
using namespace std;

// int main() {
//     Hotel hotel = Hotel();

//     cout << "Initial hotel occupancy:" << endl;
//     hotel.display();

//     hotel.addRoom("Waterlily");
//     cout << endl << "After adding room 'Waterlily':" << endl;
//     hotel.display();

//     hotel.addGuest("Waterlily", "Taika Waititi", "pqr567");
//     cout << endl << "After adding a guest:" << endl;
//     hotel.display();

//     cout << endl << "Room(s) occupied by someone called Alan Smithee:" << endl;
//     hotel.findRoomByGuest("Alan Smithee", "*");

//     return 0;
// }

int main() {
    Hotel hotel = Hotel();

    cout << "Initial hotel occupancy:" << endl;
    hotel.display();


    cout << endl << "Room(s) occupied by Alan Smithee with id 'abc123':" << endl;
    hotel.findRoomByGuest("Alan Smithee", "abc123");

    cout << endl << "Room(s) occupied by someone called Alan Smithee:" << endl;
    hotel.findRoomByGuest("Alan Smithee", "*");

    cout << endl << "Room(s) occupied by a guest with id '123xyz':" << endl;
    hotel.findRoomByGuest("*", "123xyz");

    cout << endl << "Room(s) occupied by a guest:" << endl;
    hotel.findRoomByGuest("*", "*");

    return 0;
}
