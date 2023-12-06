// PriorityTask.h

#ifndef PRIORITYTASK_H
#define PRIORITYTASK_H

#include <string>
#include "Task.h"

struct PriorityTask : public Task {
private:
    int Priority;

public:
    // Constructors
    PriorityTask(std::string title);
    PriorityTask(std::string title, std::string desc);
    PriorityTask(std::string title, std::string desc, int priority);

    // Getters
    int getPriority() const;

    // Setters
    void setPriority(int number);

    // toString function
    std::string toString() const;
};

#endif // PRIORITYTASK_H
