#include "Task.h"
#include <iostream>
using namespace std;

Task::Task(){
    this->title ="";
    this->Descripition="";
}

Task::Task(string name){
    this->title=name;
    this->Descripition="";
}
Task::Task(string name,string desciption){
    this->title=name;
    this->Descripition=desciption;
}

std::string Task::getTitle() const{
    return this->title;
}
std::string Task::getDescription()const{
    return this->Descripition;
}
void Task::setTitle(std::string name){
    this->title=name;
}
void Task::setDescription(std::string desciption){
    this->Descripition=desciption;
};