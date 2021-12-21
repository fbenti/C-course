#include <iostream>
#include <vector>
#include <sstream>      // std::istringstream
#include <string>  
#include <algorithm>
using namespace std;


int f(char u1, char v1) {
    if (u1 == v1)
        return 0;
    else return 1;
}

int levenshtein(string u, string v) {
    if (v.size() == 0)
        return u.size();
    else if (u.size() == 0)
        return v.size();
    else {
        int d1 = levenshtein(u.substr(1), v) + 1;
        int d2 = levenshtein(u, v.substr(1)) + 1;
        int d3 = levenshtein(u.substr(1), v.substr(1)) + f(u.front(), v.front());
        return min(min(d1,d2), min(d2,d3));
    }
}


int main() {

    string s1, s2;

    cin >> s1;
    cin >> s2;

    cout << levenshtein(s1,s2) << endl; 

    return 0;
}