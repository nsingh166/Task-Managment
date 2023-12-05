#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include "Task.h"
#include "PriorityTask.h"
struct LinkedList{
private:
    Node* head;
    Node* tail;
    int sizeOfLL;

public:
    LinkedList();
    LinkedList(PriorityTask* first);
    ~LinkedList();
    void push_back(PriorityTask* toAdd);
    Node* insert_before(PriorityTask* newTask, Node* knownNode);
    Node* deleteTask(Node* &toDelete);
    void print();
    int size() const;
    Node* getHead() const;
    Node* getTail() const;
};



#endif