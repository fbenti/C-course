#include <iostream>
#include <string>
#include <stdlib.h>     /* Library containing functions such as
                           rand (a generator of random numbers) */
using namespace std;

// We declare here an enumeration type called "material"
enum material {wood, stone};

// We declare here a record type called "tile"
struct tile {
    int x;         // x-coordinate of the tile in the playfield
    int y;         // y-coordinate of the tile in the playfield
    bool isWall;   // Is this tile a wall?
    material type; // The material of this tile
};

// This function translates materials into a symbol in order to display it
char symbol(material m) {
    // Switch is a sort of if-then-else, useful when there many cases.
    // Remember to always break each branch!
    switch (m) {
        case wood:
            return ' ';
        case stone:
            return '#';
        default:
            return '?';
    }
}

// Print a description of the contents of a tile
// NOTE: this function is not used in the code below, but you can experiment...
void printTile(tile f) {
    string typeStr = (f.type == stone) ? "stone" : "wood";

    cout << "Position (" << f.x << "," << f.y << ") is made of " << typeStr << ".";
    if (f.isWall) {
        cout << " It contains a wall.";
    }

    cout << endl;
}

int main() {
    cout << "The symbol for wood is: '" << symbol(wood) << "'" << endl;
    cout << "The symbol for stone is: '" << symbol(stone) << "'" << endl;

    int rows, cols;
    cout << "Enter the height of the playground: ";
    cin >> rows;
    cout << "Enter the width of the playground: ";
    cin >> cols;

    // If rows and cols are constants, we could define the playground as:
    // tile playground[rows][cols];
    // If rows and cols aren't constant, we can't do the above in standard C++!

    // 'playground' is a pointer to a dynamically-allocated array of pointers
    // to 'tile' structures (one per row)
    tile **playground = new tile*[rows];
    for (int i = 0; i < rows; i++) {
        // Each pointer in the 'playground' array points to a
        // dynamically-allocated array of tiles
        playground[i] = new tile[cols];
    }

    // Building the playground (stone perimeter, wood inside)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Note how we access an element of an array with playground[i][j]
            // and how we access the fields of a struct with .x, .y, etc.
            playground[i][j].x = i;
            playground[i][j].y = j;
            playground[i][j].isWall = (i==0 || i==(rows-1) || j==0 || j==(cols-1) || (rand()%4) == 0);
            if (playground[i][j].isWall) {
                playground[i][j].type = stone;
            } else {
                playground[i][j].type = wood;
            }
        }
    }

    // Printing the playground
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << symbol(playground[i][j].type);
        }
        cout << endl;
    }

    // Remember: everything that was created with 'new' must be 'delete'd!
    for (int i = 0; i < rows; i++) {
        delete[] playground[i];
    }
    delete[] playground;

    return 0;
}
