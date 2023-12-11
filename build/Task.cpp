// Task.cpp

#include "Task.h"

// Default constructor
Task::Task() {
    this->title = "";
    this->description = "";
}

// Constructor with title
Task::Task(const std::string& title) {
    this->title = title;
    this->description = "";
}

// Constructor with title and description
Task::Task(const std::string& title, const std::string& description) {
    this->title = title;
    this->description = description;
}

// toString function implementation
std::string Task::toString() const {
    return title + " - " + description;
}

// Getter for title
std::string Task::getTitle() const {
    return title;
}

// Getter for description
std::string Task::getDescription() const {
    return description;
}

// Setter for title
void Task::setTitle(const std::string& title) {
    this->title = title;
}

// Setter for description
void Task::setDescription(const std::string& description) {
    this->description = description;
}
