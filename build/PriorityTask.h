#ifndef PRIORITYTASK_H
#define PRIORITYTASK_H
#include <string>
#include "Task.h"

struct PriorityTask : public Task
{
    private:
    int Priority;

    public:
    PriorityTask(std::string name);
    PriorityTask(std::string name,std::string desc);
    PriorityTask(std::string name,std::string desc,int priority);
    int getPriority()const;
    void setPriority(int number);
};

#endif