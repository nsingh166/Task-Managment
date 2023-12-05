#include <iostream>
#include "PriorityTask.h"
#include "LinkedList.h"

int main() {
    
    PriorityTask task1("Task 1", "Description 1", 3);
    PriorityTask task2("Task 2", "Description 2", 2);
    PriorityTask task3("Task 3", "Description 3", 1);

   LinkedList *myList = new LinkedList;
    LinkedList LinkedList(&task1);
    myList->push_back(&task1);
   
    myList->push_back(&task2);
   myList->push_back(&task3);

   
    LinkedList.print();


    return 0;
}
