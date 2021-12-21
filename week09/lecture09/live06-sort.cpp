// Merge sort
#include <iostream>
#include <vector>

using namespace std;

template <class C>
void display(vector<C> v) {
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return;
}

template <class C>
vector<C> merge(vector<C> &v1, vector<C> & v2) {
    typename std::vector<C>::iterator i1, i2;
    vector<C> v;
    
    i1 = v1.begin();
    i2 = v2.begin();
    
    while (i1 != v1.end() || i2 != v2.end()) {
        if (i2 == v2.end() || (i1 != v1.end() && *i1 <= *i2)) {
            v.push_back(*i1);
            i1++;
        } else {
            v.push_back(*i2);
            i2++;
        }
    }
    
    return v;
}

template <class C>
vector<C> mergesort(vector<C> &v) {
    // If the vector is just one element we are done
    if (v.size() <= 1) return v;
    
    // Otherwise, split the vector into two vectors
    // and sort them
    vector<C> v1(v.begin(), v.begin() + (v.size()/2));
    vector<C> w1 = mergesort(v1);
    
    vector<C> v2(v.begin() + (v.size()/2), v.end());
    vector<C> w2 = mergesort(v2);

    // Finally, merge the result
    return merge(w1, w2);
}

int main(void) {
    vector<int> v;
    
    v.push_back(5);
    v.push_back(4);
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    v.push_back(0);
    
    cout << "Before sorting..." << endl;
    display(v);
    cout << "After sorting..." << endl;
    v=mergesort(v);
    display(v);
    
    vector<string> w;
    
    w.push_back("bac");
    w.push_back("bca");
    w.push_back("aba");
    w.push_back("baa");
    w.push_back("abb");
    w.push_back("aab");
    
    cout << "Before sorting..." << endl;
    display(w);
    cout << "After sorting..." << endl;
    w=mergesort(w);
    display(w);
    
    return 0;
}