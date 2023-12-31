#include <iostream>
#include "Project.h"
#include "tester.h"
#include <string>
#include <istream>
using namespace std;
void insertList(LinkedList<Task>* list,string Name,Task task);
enum Actions {QUIT,ADDTASK,ADDPRIORITY,INSERTTASK,SEARCHTASK,SEARCHPRIORITY,REMOVETASK,REMOVEPRIORITY,TEST};
int main() {
    // Creating a linked list of Task objects
    int choice=100;
    string Name;
    string Desc;
    cout<<"Add a Name then a Description of Project:\n";

    cin>>Name;
    getline(cin>>ws,Desc);
    Project * project = new Project(Name,Desc);
    while(choice != Actions::QUIT){
        cout<<"Enter a choice to add to the Project list\n";
        cout<<"0=Quit \n1=AddTask \n2=AddPriorityTask \n3=InsertTask \n4=SearchTasks "
              "\n5=SearchPriorityTasks \n6=RemoveTask \n7=RemovePriority\n 8=Test";
        cin>>choice;
        switch(choice){
            case ADDTASK: {
                cout << "Add a Name then a Description of Task:\n";
                cin >> Name;
                getline(cin >> ws, Desc);
                Task task(Name, Desc);
                project->addTask(task);
                break;
            }
            case ADDPRIORITY: {
                cout << "Add a Name of Task then a Desciption then a Priority number:\n";
                cin >> Name;
                getline(cin >> ws, Desc);
                int priority;
                cin >> priority;
                PriorityTask task(Name, Desc, priority);
                project->addPriorityTask(task);
                break;
            }
            case INSERTTASK: {
                cout << "Add a Name then a Description of Task:\n";
                cin >> Name;
                getline(cin >> ws, Desc);
                Task task(Name, Desc);
                cout << "Which task do you want before this:\n";
                cin >> Name;
                insertList(project->getTasks(), Name, task);
                break;
            }
            case SEARCHTASK:
            {
                cout<<"Search for the Name of a Task:\n";
                cin>>Name;
                Task task=project->searchTask(Name);
                if(task.getTitle()=="Error") cout<<"Not Found\n";
                else cout<<"Found\n";
                break;
            }
            case SEARCHPRIORITY:
            {
                cout<<"Search for the Name of a PriorityTask:\n";
                cin>>Name;
                PriorityTask task= project->searchPriorityTask(Name);
                if(task.getTitle()=="Error") cout<<"Not Found\n";
                else
                {
                    cout<<"Found\n";
                    cout<<"Priority is "<<task.getPriority()<<endl;
                }
                break;
            }
            case REMOVETASK:
            {
                cout<<"The Name of Task to remove:\n";
                cin>>Name;
                project->removeTask(Name);
                break;
            }
            case REMOVEPRIORITY:
            {
                cout<<"The Name of PriorityTask to remove:\n";
                cin>>Name;
                project->removePriorityTask(Name);
                break;
            }
            case TEST:
                testAll();
                break;
            default:
                cout<<"Bye!"<<endl;
                break;
        }
        cout<<"\n";
        project->displayProjectDetails();
    }
    cout<<"\n";
    cout<<"Sorting....\n";
    project->sortPriorityTasks();
    project->sortTasks();
    cout<<"Done\n";
    project->displayProjectDetails();



    return 0;
}
void insertList(LinkedList<Task>* list,string Name,Task task){
    Node<Task> * node = list->head;
    while(node!= nullptr){
        if(node->data.getTitle()==Name){
            list->insert(task,node);
        }
        node=node->next;
    }

}