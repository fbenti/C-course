#include <iostream>
#include <vector>
#include <sstream>      // std::istringstream
#include <string>  
using namespace std;


void reverse(vector<int> vec, uint size) {
    if (size == 0)
        return;
    else {
        cout << vec[size-1] << " ";
        reverse(vec, size-1);
    }
    return;
}


int main() {
    vector<int> vec;

    string line;
    getline( cin, line );
    
    istringstream is( line );
    int n;
    while( is >> n ) {
        vec.push_back(n);
    }

    reverse(vec, vec.size());

    return 0;
}