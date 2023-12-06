// linkedlist.h

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

template <typename T>
class LinkedList {
public:
    // Constructor
    LinkedList();

    // Destructor
    ~LinkedList();

    // Function to add a new element to the end of the linked list
    void push_back(const T& data);

    // Function to insert a new element before a specified node in the linked list
    void insert(const T& data, Node<T>* beforeNode);

    // Function to display all elements in the linked list
    void display() const;

    // Function to clear the linked list and free the memory
    void clear();

    Node<T>* head; // Pointer to the first element in the linked list
    Node<T>* tail; // Pointer to the last element in the linked list
};

#include "linkedlist.tpp"  // Include the implementation file at the end of the header

#endif // LINKEDLIST_H
