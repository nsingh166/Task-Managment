#include "Node.h"
#include <string>
using namespace std;

//inTask = nulllptr
Node::Node(Task* inTask){
    this->data=inTask;
}
string Node::getTask() const{
    return this->data;
}

void Node::setTask(Task* newTask){
    this->data=newTask;
}

Node* Node::getPrevious() const{
    return this->previous;
}

void Node::setPrevious(Node* newNode){
    this->previous=newNode;
}

void Node::setNext(Node* newNode){
    this->next=newNode;
}

Node* Node::getNext() const{
    return this->next;
}

bool operator==(const Node &lhs, const Node &rhs) {
    return (lhs.getTask() == rhs.getTask());
}

bool operator==(const Node &lhs, const string &rhs) {
    return (lhs.getTask() == rhs);
}

bool operator!=(const Node &lhs, const Node &rhs){
    return !(lhs == rhs);
}

bool operator<(const Node &lhs, const Node &rhs){
    return lhs.getTask() < rhs.getTask();
}

bool operator<(const string &lhs, const Node &rhs){
    return lhs < rhs.getTask();
}

bool operator<(const Node &lhs, const std::string rhs){
    return lhs.getTask() < rhs;
}

bool operator>(const Node &lhs, const Node &rhs){
    return rhs < lhs;
}

bool operator<=(const Node &lhs, const Node &rhs){
    return !(lhs > rhs);
}

bool operator>=(const Node &lhs, const Node &rhs){
    return !(lhs < rhs);
}