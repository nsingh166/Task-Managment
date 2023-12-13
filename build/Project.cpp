// Project.cpp

#include "Project.h"

// Constructors
Project::Project() : title(""), description("") {}

Project::Project(const std::string& title, const std::string& description)
        : title(title), description(description) {}
LinkedList<Task>* Project::getTasks(){
    LinkedList<Task>* testList;
    testList= &tasks;
    return testList;
}
LinkedList<PriorityTask> Project::getPriorityTasks() const{
    return priorityTasks;
}
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
void Project::addTask(const Task& Task) {
    tasks.push_back(Task);
}

void Project::removeTask(const std::string& taskTitle) {
    Node<Task> *removal;
    removal = tasks.head;
    while (removal != nullptr){
        if(removal->data.getTitle()==taskTitle){
            if(removal->next== nullptr && removal->prev!= nullptr){
                removal->prev->setNext(nullptr);
                tasks.tail=removal->prev;
                delete removal;
                std::cout<<"delete is done\n";
                break;
            }
            else if(removal->prev== nullptr && removal->next!=nullptr){
                removal->next->setPrev(nullptr);
                tasks.head=removal->next;
                delete removal;
                std::cout<<"delete is done\n";
                break;
            }
            else if(removal->prev== nullptr && removal->next==nullptr){
                tasks.clear();
            }
            else{
                removal->prev->setNext(removal->next);
                removal->next->setPrev(removal->prev);
                delete removal;
                std::cout<<"delete is done\n";
                break;
            }

        }
        removal=removal->next;
    }
}



// PriorityTask management
void Project::addPriorityTask(const PriorityTask& priorityTask) {
    priorityTasks.push_back(priorityTask);
}

void Project::removePriorityTask(const std::string& taskTitle) {
    Node<PriorityTask> *removal;
    removal = priorityTasks.head;
    while (removal != nullptr){
        if(removal->data.getTitle()==taskTitle){
            if(removal->next== nullptr && removal->prev!= nullptr){
                removal->prev->setNext(nullptr);
                priorityTasks.tail=removal->prev;
                delete removal;
                std::cout<<"delete is done\n";
                break;
            }
            else if(removal->prev== nullptr && removal->next!=nullptr){
                removal->next->setPrev(nullptr);
                priorityTasks.head=removal->next;
                delete removal;
                std::cout<<"delete is done\n";
                break;
            }
            else if(removal->prev== nullptr && removal->next==nullptr){
                priorityTasks.clear();
            }
            else{
                removal->prev->setNext(removal->next);
                removal->next->setPrev(removal->prev);
                delete removal;
                std::cout<<"delete is done\n";
                break;
            }

        }
        removal=removal->next;
    }
}

// Search using title
Task Project::searchTask(const std::string& taskTitle) const {
    Node<Task> *current = tasks.head;
    while (current != nullptr){
        if(current->data.getTitle()==taskTitle){
            return current->data;
        }
        current=current->next;
    }
    Task error= Task("Error","Not Found");
    return error;
}

PriorityTask Project::searchPriorityTask(const std::string& taskTitle) const {
    Node<PriorityTask> *current = priorityTasks.head;
    while (current != nullptr){
        if(current->data.getTitle()==taskTitle){
            return current->data;
        }
        current=current->next;
    }

    PriorityTask error= PriorityTask("Error","Not Found",0);
    return error;
}

void Project::sortTasks(){
    //Bubble Sort for Tasks
    Node<Task> *i = tasks.head;

    while(i != nullptr){
        Node<Task> *j = tasks.head;
        while (j->next != nullptr){
            Node<Task> * current = j->next;
            if(j->data.getTitle() > current->data.getTitle()){
                Task temp = j->data;
                j->data = current->data;
                current->data = temp;

            }

            j=current;
        }
        i = i->next;
    }

}
// Sort priorityTasks based on priority
void Project::sortPriorityTasks() {
    // SelectionSort
    Node<PriorityTask> *current = priorityTasks.head;

    while (current != nullptr) {
        Node<PriorityTask> *LargeNode = current;
        Node<PriorityTask> *next = LargeNode->next;
        while (next != nullptr) {
            if (next->data.getPriority() > LargeNode->data.getPriority()) {
                LargeNode = next;
            }
            next = next->next;
        }


        PriorityTask temp = current->data;
        current->data = LargeNode->data;
        LargeNode->data = temp;

        current = current->next;
    }
}
// Display project details
void Project::displayProjectDetails() const {
    std::cout << "Project: " << title << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout << "Tasks: \n";
    tasks.display();
    std::cout << "Priority Tasks: \n";
    priorityTasks.display();
}
