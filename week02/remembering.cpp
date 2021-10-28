#include <iostream>
using namespace std;

int main()
{
    int array[1000] = {0};

    int n;
    cin >> n;
    while (n != 0) 
    {
        if (n > 0 && n <= 1000)
        {
            cout << array[n-1] << endl;
            array[n-1] += 1;
        }
        cin >> n;
    }
    return 0;
}