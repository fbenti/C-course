#include <iostream>
#include <set>

using namespace std;

int main()
{
    multiset<int> bag;
    int x;
    string input;
    cin >> input;

    while (input != "quit")
    {
        if (input == "add")
        {
            cin >> x;
            bag.insert(x);
        }
        else if (input == "del")
        {
            cin >> x;
            auto it = bag.find(x);
            if (it != bag.end())
                bag.erase(it);
        }
        else if (input == "qry") 
        {
            cin >> x;
            auto it = bag.find(x);
            if (it != bag.end())
                cout << "T";
            else
                cout << "F"; 
        }
        else
            return 0;
        cin >> input;
    }
}