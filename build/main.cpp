#include <iostream>
#include "Task.h"
#include "PriorityTask.h"
#include "LinkedList.h"

int main() {
    // Creating a linked list of Task objects
    LinkedList<Task> taskList;

    // Adding Task objects to the linked list
    Task task1("Task 1", "Description 1");
    Task task2("Task 2", "Description 2");
    Task task3("Task 3", "Description 3");

    taskList.push_back(task1);
    taskList.push_back(task2);
    taskList.push_back(task3);

    // Displaying Task objects in the linked list
    std::cout << "Linked List of Tasks: ";
    taskList.display();

    // Inserting a new Task object before the second node
    Node<Task>* secondNode = taskList.head->next;
    Task task4("Task 4", "Description 4");
    taskList.insert(task4, secondNode);

    // Displaying Task objects in the linked list after insertion
    std::cout << "Linked List of Tasks after insertion: ";
    taskList.display();

    // Creating a linked list of PriorityTask objects
    LinkedList<PriorityTask> priorityTaskList;

    // Adding PriorityTask objects to the linked list
    PriorityTask priorityTask1("Priority Task 1", "Priority Description 1", 1);
    PriorityTask priorityTask2("Priority Task 2", "Priority Description 2", 2);
    PriorityTask priorityTask3("Priority Task 3", "Priority Description 3", 3);

    priorityTaskList.push_back(priorityTask1);
    priorityTaskList.push_back(priorityTask2);
    priorityTaskList.push_back(priorityTask3);

    // Displaying PriorityTask objects in the linked list
    std::cout << "Linked List of PriorityTasks: ";
    priorityTaskList.display();

    // Inserting a new PriorityTask object before the second node
    Node<PriorityTask>* secondPriorityNode = priorityTaskList.head->next;
    PriorityTask priorityTask4("Priority Task 4", "Priority Description 4", 3);
    priorityTaskList.insert(priorityTask4, secondPriorityNode);

    // Displaying PriorityTask objects in the linked list after insertion
    std::cout << "Linked List of PriorityTasks after insertion: ";
    priorityTaskList.display();

    return 0;
}
