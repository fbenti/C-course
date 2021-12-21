#include <iostream>
#include "linked-list.h"

using namespace std;

template<class C>
class MySet {
    // Internal implementation of the set as a linked list
private:
    Node<C> *first;

public:
    // A constructor
    MySet() {
        // The empty set is just an empty list
        first = nullptr;
    };

public:
    // Is the set empty?
    bool empty() {
        return first == nullptr;
    }

    // Add an element to the set
    void insert(C e) {
        // If the set already contains the element, do nothing
        if (contains(e)) {
            return;
        } else {
            insertOrdered(e);
        }
    }

private:
    void insertFirst(C e) {
        insertAt(e, first);
    }

    void insertAt(C e, Node<C> *&first) {
        // Create a new node for the new element e
        Node<C> * p;
        p = new Node<C>;
        p->content = e;

        // The new element is inserted at the beginning
        p->next = first;
        first = p;
    };

    void insertOrdered(C e) {
        insertOrderedRec(e, first);
    };

    void insertOrderedRec(C e, Node<C> *&first) {
        if (first == nullptr) {
            insertAt(e, first);
        } else if (e < first->content) {
            insertAt(e,first);
        } else {
            insertOrderedRec(e, first->next);
        }
    };

public:
    // Check whether an element is already in the set
    bool contains(C e) {
        return containsR(e, first);
    };

private:
    // Check whether an element is already in the set
    bool containsR(C e, Node<C> *p) {
        // Did we reach the end of the list of elements?
        if (p == nullptr) return false;

        // Check if the first element of the list is the one we are looking for
        if (p->content == e) return true;

        // Check the rest of the list
        return containsR(e, p->next);
    };

public:
    // Delete an element from the set
    void del(C e) {
        delR(e, first);
    };

private:
    // Delete an element from the set
    void delR(C e, Node<C> *&p) {
        // Did we reach the end of the internal list?
        if (p == nullptr) return;

        // Check whether the current element is to be deleted
        if (p->content ==  e) {
            // Save the pointer to the next element in q
            Node<C> *q;
            q = p->next;
            // Delete the current element
            delete p;
            // Note that we update p, which was passed by reference
            p = q;
        } else {
          // Look for the element in the rest of the list
          return delR(e, p->next);
        }
    };

public:
    // Extract some element from the set
    C extract(void) {
        if (empty()) {
            // raise an error
            throw std::invalid_argument("Cannot extract from an empty set");
        }
        C e;
        e = first->content;
        del(e);
        return e;
    };

public:
    void print() {
        printR(first);
    }

private:
    void printR(Node<C> *n) {
        if (n == nullptr) {
            cout << endl;
        } else {
          cout << n->content << " ";
          printR(n->next);
        }
    }

public:
    // Destructors are needed since the internal representation
    // is based on dynamically-allocated list elements
    ~MySet() {
        // We repeatedly extract (and thus deallocate) all elements
        while (!empty()) {
            extract();
        }
    };
    
    // This method tests if two sets are equal
public:
    bool operator ==(const MySet &S) const {
        return equal(first, S.first);
    }

private:
    bool equal(Node<C> *p, Node<C> *q) const {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr) return false;
        if (q == nullptr) return false;
        if (p->content != q->content) return false;
        return equal(p->next, q->next);
    }
};

int main() {
    MySet<int> set1, set2;

    cout << "Inserting some numbers in set1..." << endl;
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    set1.print();
    cout << "Contents of set1: ";
    set2.print();

    cout << "Inserting some numbers in set2..." << endl;
    set2.insert(3);
    set2.insert(2);
    set2.insert(1);
    cout << "Contents of set2: ";
    set2.print();

    cout << "Are S1 and S2 equal?... ";
    cout << ((set1 == set2) ? "yes!" : "no!") << endl;

    return 0;
}
