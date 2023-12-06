#include "PriorityTask.h"
#include <iostream>
using namespace std;


PriorityTask::PriorityTask(std::string title, std::string desc,int priority){
    Task(title, desc);
    this->Priority=priority;
}

int PriorityTask::getPriority()const{
    return this->Priority;
}
void PriorityTask::setPriority(int number){
    this->Priority=number;
}

// toString function implementation
std::string PriorityTask::toString() const {
    return Task::toString() + ", Priority: " + std::to_string(Priority);
}