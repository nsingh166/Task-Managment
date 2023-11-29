#include "LinkedList.h"
#include <iostream>
using namespace std;


LinkedList::LinkedList(){
        this->head= nullptr;
        this->tail= nullptr;
        this->sizeOfLL = 0;
}

LinkedList::LinkedList(Task first){
   this->head= nullptr;
   this->tail= nullptr;
   this->sizeOfLL = 0;
   this->push_back(first);
}

LinkedList::~LinkedList(){
    Node* currentNode = head;
    while(currentNode != nullptr){
        delete currentNode;
        currentNode=currentNode->getNext();
    }
    sizeOfLL = 0;
}

Node* LinkedList::getHead() const{
   return this->head;
}

Node* LinkedList::getTail() const {
   return this->tail;
}

void LinkedList::push_back(const string& toAdd){

    if(sizeOfLL == 0){
        Node* currentItem = new Node(toAdd);
        currentItem->setNext(nullptr);
        currentItem->setPrevious(nullptr);
        this->tail=currentItem;
        this->head=currentItem;
        sizeOfLL++;
    }

    else {
        Node *currentItem = new Node(toAdd);
        tail->setNext(currentItem);
        currentItem->setPrevious(tail);
        currentItem->setNext(nullptr);
        tail = currentItem;
        sizeOfLL++;
    }
}


void LinkedList::print(){
   Node* currentNode = head->getNext();
   while(currentNode != nullptr){
      cout<<currentNode->getPrevious()->getWord()<<endl;
      currentNode=currentNode->getNext();
   }
   cout<<tail->getWord()<<endl;
}

int LinkedList::size() const{
   return this->sizeOfLL;
}