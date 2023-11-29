#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

struct LinkedList{
   private:
   Node* head;
   Node* tail;
   int sizeOfLL;
   
   public:
   LinkedList();
   LinkedList(Task first);
   ~LinkedList();
   void push_back(const std::string& toAdd);
   void print();
   int size() const;
   Node* getHead() const;
   Node* getTail() const;
};



#endif