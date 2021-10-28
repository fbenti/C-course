// Example using enumerations
#include <iostream>
#include <string>
using namespace std;


// an ENUMERATION is a user-defined data type with values limited to a given finite set
enum direction {
    north, // Underlying value: 0
    east,  // Underlying value: 1
    south, // Underlying value: 2
    west   // Underlying value: 3
};
// now I can create variable of type direction
// direction dir = north; where the value is one of the ones shown
// very handy for representing symbolic information and using the switch statement

// Function prototypes: they only specify the function name,
// the argument(s) type(s), and the return type, so they are known in main().
// The actual function definitions appear later
direction turnLeft(direction dir);
direction turnRight(direction dir);
string dirToText(direction dir);

int main() {
    direction dir = north;

    while (true) {
        char turn;
        cout << "Now going " << dirToText(dir) << endl;
        cout << "Turn right (r), turn left (l), or quit (q): ";
        cin >> turn;
        if (turn == 'r') {
            cout << "Turning right" << endl;
            dir = turnRight(dir);
        } else if (turn == 'l') {
            cout << "Turning left" << endl;
            dir = turnLeft(dir);
        } else {
            cout << "Bye!" << endl;
            break;
        }
    }

    return 0;
}

/**
 * Return the direction to the left of the given direction.
 * Don't forget to use 'break' statements in the 'switch'!
 */
direction turnLeft(direction dir) {
    direction newDir;
    // Don't forget to use 'break' statements in the 'switch'!
    switch (dir) {
        case north:
            newDir = west;
            break;
        case west:
            newDir = south;
            break;
        case south:
            newDir = east;
            break;
        case east:
            newDir = north;
            break;
        default:
            cout << "WARNING: invalid direction: " << dir << endl;
            newDir = north;
            break;
    }
    return newDir;
}

/**
 * Return the direction to the right of the given direction.
 */
direction turnRight(direction dir) {
    switch (dir) {
        case north:
            return east;
        case west:
            return north;
        case south:
            return west;
        case east:
            return south;
        default:
            cout << "WARNING: invalid direction: " << dir << endl;
            return north;
    }
}

/**
 * Return a string representation of the given direction
 */
string dirToText(direction dir) {
    switch (dir) {
        case north:
            return "North";
        case west:
            return "West";
        case south:
            return "South";
        case east:
            return "East";
        default:
            cout << "WARNING: invalid direction: " << dir << endl;
            return "INVALID!";
    }
}
