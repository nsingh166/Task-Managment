#include "PriorityTask.h"
#include <iostream>
using namespace std;


PriorityTask::PriorityTask(std::string name,std::string desc,int priority){
    Task(name,desc);
    this->Priority=priority;
}

int PriorityTask::getPriority()const{
    return this->Priority;
}
void PriorityTask::setPriority(int number){
    this->Priority=number;
}