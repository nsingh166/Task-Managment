// Project.cpp

#include "Project.h"

// Constructors
Project::Project() : title(""), description("") {}

Project::Project(const std::string& title, const std::string& description)
    : title(title), description(description) {}

// Accessors
std::string Project::getTitle() const {
    return title;
}

std::string Project::getDescription() const {
    return description;
}

// Mutators
void Project::setTitle(const std::string& title) {
    this->title = title;
}

void Project::setDescription(const std::string& description) {
    this->description = description;
}

// PriorityTask management
void Project::addPriorityTask(const PriorityTask& priorityTask) {
    priorityTasks.push_back(priorityTask);
}

void Project::removePriorityTask(const std::string& taskTitle) {
    priorityTasks.removeIf([taskTitle](const Node<PriorityTask>* node) {
        return node->data.getTitle() == taskTitle;
    });
}

// Search using title
Task Project::searchTask(const std::string& taskTitle) const {
    return tasks.search([taskTitle](const Node<Task>* node) {
        return node->data.getTitle() == taskTitle;
    });
}

PriorityTask Project::searchPriorityTask(const std::string& taskTitle) const {
    return priorityTasks.search([taskTitle](const Node<PriorityTask>* node) {
        return node->data.getTitle() == taskTitle;
    });
}

// Sort priorityTasks based on priority
void Project::sortPriorityTasks() {
    priorityTasks.sort([](const Node<PriorityTask>* a, const Node<PriorityTask>* b) {
        return a->data.getPriority() < b->data.getPriority();
    });
}

// Display project details
void Project::displayProjectDetails() const {
    std::cout << "Project: " << title << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout << "Tasks: ";
    tasks.display();
    std::cout << "Priority Tasks: ";
    priorityTasks.display();
}
