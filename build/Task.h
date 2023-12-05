#ifndef TASK_H
#define TASK_H

#include <string>


struct Task{
    protected:
    std::string title; 
    std::string Descripition;

    public:
    Task();
    Task(std::string name);
    Task::Task(std::string name,std::string desciption);
    std::string getTitle()const;
    std::string getDescription()const;
    void setTitle(std::string name);
    void setDescription(std::string desciption);
};

#endif
