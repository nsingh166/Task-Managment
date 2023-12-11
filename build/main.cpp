#include <iostream>
#include "Task.h"
#include "PriorityTask.h"
#include "LinkedList.h"
#include "Project.h"
using namespace std;

int main() {


    Project* myProj = new Project("CSC-340 Final Project", "Final project demonstration!");
    Task task1("Groceries", "apples, bread, milk, eggs");
    Task task2("Homework", "CSC Final, MATH Final, ENGL Paper");
    Task task3("Chores", "kitchen, bathroom, mop, sweep, windows");

    cout<<"----Empty Project----"<<endl;
    myProj->displayProjectDetails();

    cout<<"----Adding Task objects to Project----"<<endl;
    myProj->addTask(task1);
    myProj->addTask(task2);
    myProj->addTask(task3);
    myProj->displayProjectDetails();

    cout<<"----Adding PriorityTask objects to Project----"<<endl;
    PriorityTask priorityTask1("Make dinner", "Last task of the day, not pressing", 3);
    PriorityTask priorityTask2("CSC-340 Final Project", "Demo is today 11/11/23!", 1);
    PriorityTask priorityTask3("Work", "Must go to work after school today", 2);

    myProj->addPriorityTask(priorityTask1);
    myProj->addPriorityTask(priorityTask2);
    myProj->addPriorityTask(priorityTask3);
    myProj->displayProjectDetails();

    cout<<"----Sorting both Task and Priority Task objects----"<<endl;
    myProj->sortTasks();
    myProj->sortPriorityTasks();
    myProj->displayProjectDetails();

    return 0;
}
