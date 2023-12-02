#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include "Task.h"

struct LinkedList{
private:
    Node* head;
    Node* tail;
    int sizeOfLL;

public:
    LinkedList();
    LinkedList(Task* first);
    ~LinkedList();
    void push_back(Task* toAdd);
    Node* insert_before(Task* newTask, Node* knownNode);
    Node* deleteTask(Node* &toDelete);
    void print();
    int size() const;
    Node* getHead() const;
    Node* getTail() const;
};



#endif