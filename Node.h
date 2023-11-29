#ifndef NODE_H
#define NODE_H
#include <string>

struct Node{
private:
    std::string word;
    Node* previous;
    Node* next;
public:
    Node(std::string word = "");
    std::string getWord() const;
    Node* getPrevious() const;
    Node* getNext() const;
    void setPrevious(Node* newNode);
    void setNext(Node* newNode);
    void setWord(std::string newWord);
};
bool operator==(const Node &lhs, const Node &rhs);
bool operator!=(const Node &lhs, const Node &rhs);
bool operator<(const Node &lhs, const Node &rhs);
bool operator>(const Node &lhs, const Node &rhs);
bool operator<=(const Node &lhs, const Node &rhs);
bool operator>=(const Node &lhs, const Node &rhs);

#endif