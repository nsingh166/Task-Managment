// node.h

#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev; // Pointer to the previous node

    // Constructor
    Node(const T& data);
};

#include "node.tpp"  // Include the implementation file at the end of the header

#endif // NODE_H
