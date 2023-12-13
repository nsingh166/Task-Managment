// Project.h

#ifndef PROJECT_H
#define PROJECT_H

#include <iostream>
#include "LinkedList.h"
#include "Task.h"
#include "PriorityTask.h"

class Project {
private:
    std::string title;
    std::string description;
    LinkedList<Task> tasks;
    LinkedList<PriorityTask> priorityTasks;

public:
    // Constructors
    Project();
    Project(const std::string& title, const std::string& description);

    // Accessors
    std::string getTitle() const;
    std::string getDescription() const;
    LinkedList<Task>* getTasks();
    LinkedList<PriorityTask> getPriorityTasks() const;

    // Mutators
    void setTitle(const std::string& title);
    void setDescription(const std::string& description);

    //Task management
    void addTask(const Task& Task);
    void removeTask(const std::string& taskTitle);

    // PriorityTask management
    void addPriorityTask(const PriorityTask& priorityTask);
    void removePriorityTask(const std::string& taskTitle);

    // Search using title
    Task searchTask(const std::string& taskTitle) const;
    PriorityTask searchPriorityTask(const std::string& taskTitle) const;

    // Sort priorityTasks based on priority
    void sortPriorityTasks();
    void sortTasks();

    // Display project details
    void displayProjectDetails() const;
};

#endif // PROJECT_H
