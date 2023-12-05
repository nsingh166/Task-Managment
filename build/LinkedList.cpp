#include "LinkedList.h"
#include <iostream>
#include "PriorityTask.h"
using namespace std;

//Default constructor
LinkedList::LinkedList(){
    this->head= nullptr;
    this->tail= nullptr;
    this->sizeOfLL = 0;
}
//Constructor with a parameter
LinkedList::LinkedList(PriorityTask* first){
    this->head= nullptr;
    this->tail= nullptr;
    this->sizeOfLL = 0;
    this->push_back(first);
}

//Deconstructor
LinkedList::~LinkedList(){
    Node* currentNode = head;
    //Iterate from head to tail then delete each Node
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

//Insert before (assumes sorted)
Node*  LinkedList::insert_before(PriorityTask* toAdd, Node * knownNode){
   //If the linked list is empty, then make the head and tail the same pointer
   if(sizeOfLL == 0){
      Node* currentItem = new Node(toAdd);
      //Set new Head pointer
      currentItem->setNext(nullptr);
      currentItem->setPrevious(nullptr);

      this->tail=currentItem;
      this->head=currentItem;

      sizeOfLL++;
   }
   //If Node is to be added as the head
   else if(knownNode == head){
      Node *newItem = new Node(toAdd);
      //Set new pointers
      head->setPrevious(newItem);
      newItem->setNext(head);
      newItem->setPrevious(nullptr);

      head = newItem;
      sizeOfLL++;
   }
   //If to be added to the tail
   else if(knownNode == nullptr){
      push_back(toAdd);
      return nullptr;
   }

   //Else add before the next known Node
   else{
      Node *newItem = new Node(toAdd);
      //Set new pointers
      newItem->setPrevious(knownNode->getPrevious());
      knownNode->getPrevious()->setNext(newItem);
      knownNode->setPrevious(newItem);
      newItem->setNext(knownNode);
      
      sizeOfLL++;
      knownNode = newItem;
   }
   return knownNode->getNext();
}

void LinkedList::push_back(PriorityTask* toAdd){
   //Make head and tail the same if linked list is empty
   if(sizeOfLL == 0){
      Node* currentItem = new Node(toAdd);
      //Set pointers
      currentItem->setNext(nullptr);
      currentItem->setPrevious(nullptr);

      this->tail=currentItem;
      this->head=currentItem;
      sizeOfLL++;
   }else {
     Node *currentItem = new Node(toAdd);
     //Set pointers
     tail->setNext(currentItem);
     currentItem->setPrevious(tail);
     currentItem->setNext(nullptr);

     tail = currentItem;
     sizeOfLL++;
    }
}

Node* LinkedList::deleteTask(Node* &toDelete) {
    if(head == tail){
        sizeOfLL--;
        head = nullptr;
        tail = nullptr;
        delete toDelete;
        return nullptr;
    }

    else{
        Node *prev = toDelete->getPrevious();
        Node *next = toDelete->getNext();
        if (prev != nullptr) {
            prev->setNext(next);
        }
        if(next != nullptr) {
            next->setPrevious(prev);
        }
        sizeOfLL--;
        delete toDelete;
        return next;
    }
}

/*
WIP
*/
void LinkedList::print(){
    if(head == tail){
        if(head == nullptr){
            cout<<endl;
        }
        else{
            cout<<"NOT IMPLEMENTED"<<endl;
            //cout<<tail->getTask()<<endl;
        }
    }

    else{
        Node* currentNode = head;

        while(currentNode != nullptr){
            //cout<<currentNode->getTask()<<endl;
            cout<<"NOT IMPLEMENTED"<<endl;
            currentNode=currentNode->getNext();
        }
    }
}

int LinkedList::size() const{
    return this->sizeOfLL;
}