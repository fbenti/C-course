// Header file for a template linked list
#ifndef __linked_list__
#define __linked_list__

// C can be of any type
template<class C>
class Node {
public:
    C content;
    Node<C> *next;
};


#endif // __linked_list__
