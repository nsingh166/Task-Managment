#include "Node.h"
#include <string>
using namespace std;

//string word = ""
Node::Node(string word){
   this->word=word;
}
string Node::getWord() const{
   return this->word;
}

void Node::setWord(string newWord){
   this->word=newWord;
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
   return (lhs.getWord() == rhs.getWord());
}

bool operator!=(const Node &lhs, const Node &rhs){
   return !(lhs == rhs);
}

bool operator<(const Node &lhs, const Node &rhs){
   return lhs.getWord() < rhs.getWord();
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