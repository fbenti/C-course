#include <iostream>
#include <string> 
using namespace std;

int main()
{
    string temp;
    int sum = 0;
    cin >> temp;
    while ( stoi(temp) < 0) {
        cin >> temp;
    }
    int n = stoi(temp);
    for (n; n >0; n--) {
        sum += n; 
    }
    cout << sum << endl;
    return 0;
}
