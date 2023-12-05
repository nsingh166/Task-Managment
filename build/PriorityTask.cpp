#include "PriorityTask.h"
#include <iostream>
using namespace std;

PriorityTask::PriorityTask(std::string name){

}
PriorityTask::PriorityTask(std::string name,int priority){
    
}
int PriorityTask::getPriority()const{
    return this->Priority;
}
void PriorityTask::setPriority(int number){
    this->Priority=number;
}