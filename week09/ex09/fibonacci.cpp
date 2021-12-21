#include <iostream>
#include <vector>
#include <sstream>      // std::istringstream
#include <string>  
using namespace std;


// void fibonacci(vector<int> vec, uint size, uint count = 0) {
//     if (size == 0)
//         return;
//     else if (count == size - 1)
//         return;
//     else {
//         if (vec[count] == 0 || vec[count] == 1)
//             cout << 1 << " ";
//             fibonacci(vec, size,count+1)
//         else {


//         }
//     }

//  }

 int fibonacci(int n) {
    if (n < 2)
        return 1;
    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
 }


int main() {
    string line;
    getline( cin, line );
    
    istringstream is( line );
    int n;
    while( is >> n ) {
        cout << fibonacci(n) << " ";
    }
    return 0 ;
}