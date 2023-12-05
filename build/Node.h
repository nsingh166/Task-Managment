#ifndef NODE_H
#define NODE_H
#include <string>
#include "Task.h"
#include "PriorityTask.h"

struct Node{
private:
    PriorityTask* data;
    Node* previous;
    Node* next;
public:
    Node(PriorityTask* inTask = nullptr);
    PriorityTask* getTask() const;
    Node* getPrevious() const;
    Node* getNext() const;
    void setPrevious(Node* newNode);
    void setNext(Node* newNode);
    void setPriorityTask(PriorityTask* newTask);
};
bool operator==(const Node &lhs, const Node &rhs);
bool operator==(const Node &lhs, const std::string &rhs);
bool operator!=(const Node &lhs, const Node &rhs);
bool operator<(const Node &lhs, const Node &rhs);
bool operator<(const std::string &lhs, const Node &rhs);
bool operator<(const Node &lhs, const std::string rhs);
bool operator>(const Node &lhs, const Node &rhs);
bool operator<=(const Node &lhs, const Node &rhs);
bool operator>=(const Node &lhs, const Node &rhs);

#endif

