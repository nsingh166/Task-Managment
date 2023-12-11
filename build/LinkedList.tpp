// linkedlist.tpp

#ifndef LINKEDLIST_TPP
#define LINKEDLIST_TPP

#include <iostream>

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr) {}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::push_back(const T& data) {
    Node<T>* newNode = new Node<T>(data);

    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

template <typename T>
void LinkedList<T>::insert(const T& data, Node<T>* beforeNode) {
    Node<T>* newNode = new Node<T>(data);

    if (beforeNode == nullptr) {
        // Insert at the beginning
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
    } else {
        newNode->next = beforeNode;
        newNode->prev = beforeNode->prev;
        if (beforeNode->prev != nullptr) {
            beforeNode->prev->next = newNode;
        } else {
            // Inserting at the beginning
            head = newNode;
        }
        beforeNode->prev = newNode;
    }
}

template <typename T>
void LinkedList<T>::display() const {
    Node<T>* current = head;
    while (current != nullptr) {
        std::cout <<"\t"<< current->data.toString() << " "<<std::endl;
        current = current->next;
    }
}

template <typename T>
void LinkedList<T>::clear() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = tail = nullptr;
}

#endif // LINKEDLIST_TPP
