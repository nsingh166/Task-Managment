// Project.cpp

#include "Project.h"

// Constructors
Project::Project() : title(""), description("") {}

Project::Project(const std::string& title, const std::string& description)
        : title(title), description(description) {}

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
    Node<Task> *removal = tasks.head;
    while (removal != nullptr){
        if(removal->data.getTitle()!=taskTitle){
            removal->prev->next=removal->next;
            removal->next->prev=removal->prev;

            delete removal;
        }
    }
}

// PriorityTask management
void Project::addPriorityTask(const PriorityTask& priorityTask) {
    priorityTasks.push_back(priorityTask);
}

void Project::removePriorityTask(const std::string& taskTitle) {
    Node<PriorityTask> *removal = priorityTasks.head;
    while (removal != nullptr){
        if(removal->data.getTitle()!=taskTitle){
            removal->prev->next=removal->next;
            removal->next->prev=removal->prev;

            delete removal;
        }
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
    Task error= Task("","Not Found");
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

    PriorityTask error= PriorityTask("","Not Found",0);
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
    std::cout << "Tasks: ";
    tasks.display();
    std::cout << "Priority Tasks: ";
    priorityTasks.display();
}
