#ifndef NODE_H
#define NODE_H
#include <string>
#include "Task.h"

struct Node{
private:
    Task* data;
    Node* previous;
    Node* next;
public:
    Node(Task* inTask = nullptr);
    std::string getTask() const;
    Node* getPrevious() const;
    Node* getNext() const;
    void setPrevious(Node* newNode);
    void setNext(Node* newNode);
    void setTask(Task* newTask);
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