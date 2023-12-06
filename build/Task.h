// Task.h

#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
public:
    // Constructors
    Task();
    Task(const std::string& title);
    Task(const std::string& title, const std::string& description);

    // Getters
    std::string getTitle() const;
    std::string getDescription() const;

    // Setters
    void setTitle(const std::string& title);
    void setDescription(const std::string& description);

    // toString function
    std::string toString() const;

private:
    std::string title;
    std::string description;
};

#endif // TASK_H
