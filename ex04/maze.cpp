#include <iostream>
#include <string>
#include <stdlib.h>
// using namespace std;
using std::cin; using std::cout; using std::endl;

#define NROWS 12
#define NCOLS 16

typedef enum { 
    wood, 
    stone 
} material;

enum direction {
    up,
    left,
    down,
    right,
    non_valid
};

struct tile {
    int x, y;
    bool isWall;
    material type;
};

struct pos {
    int x,y;
};

void printMaze(pos user, tile ground[NROWS][NCOLS]) {
    for (int i = 0; i<  NROWS; i++){
        for (int j = 0; j<NCOLS; j++){
            if (i == user.x && j == user.y) 
                cout << "O";
            else if (ground[i][j].type == stone)
                cout << "*";
            else if (ground[i][j].type == wood)
                cout << " ";
        }
        cout << endl;
    }
    // cout << endl;
    return;
}

direction char2dir(char move){
    if (move == 'u') return up;
    else if (move == 'l') return left;
    else if (move == 'd') return down;
    else if (move == 'r') return right; 
    else return non_valid;
}

pos checkMovement(char move, pos user, tile current_ground[NROWS][NCOLS]) {
    pos next_user = user;
    direction dir = char2dir(move);
    switch(dir){
        case up:
            if (!current_ground[next_user.x-1][next_user.y].isWall) // != stone ) //&& (user.x-1) != 0)
                next_user.x--;
                // return next_user;
                break;
        case left:
            if (!current_ground[next_user.x][next_user.y-1].isWall)// != stone ) //&& (user.y-1) != 0)
                next_user.y--;
                // return next_user;
                break;
        case down:
            if (!current_ground[next_user.x+1][next_user.y].isWall)// != stone ) //&& (user.x+1) != NROWS-1)
                next_user.x++;
                // return next_user;
                break;
            break;           
        case right:
            if (!current_ground[next_user.x][next_user.y+1].isWall)//  != stone ) //&& (user.y+1) != NCOLS-1)
                next_user.y++;
                // return pos {user.x,user.y+1};
                break;
        default:
            cout << "WARNING: invalid direction: " << dir << endl;
            // return next_user;
    }
    printMaze(next_user, current_ground);
    return next_user;
}

int main() {
    tile playground[NROWS][NCOLS];
    for (int i = 0; i < NROWS; i++) {
        for (int j = 0; j < NCOLS; j++) {
            playground[i][j].x = j;
            playground[i][j].y = i;
            playground[i][j].isWall = (j==0 || i==(NROWS-1) || (i==0 && j!=3) || j==(NCOLS-1));
            if (playground[i][j].isWall) {
                playground[i][j].type = stone;
            } else {
                playground[i][j].type = wood;
            }
        }   
    }

    pos user;
    user.x = 5; user.y = 5;

    printMaze(user, playground);

    while (true) {
        char move;
        cin >> move;

        if (move == 'q')
            break;
        else 
            user = checkMovement(move, user, playground);            
    }
    return 0;
}
