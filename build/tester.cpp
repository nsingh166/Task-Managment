#include "tester.h"
#include "LinkedList.h"
#include "PriorityTask.h"
using namespace std;

void testAll(){
    cout<<"Testing Nodes..."<<endl;
    testNode();
    cout<<"\t\tDone!\nTesting Linked List..."<<endl;
    testLL();
    cout<<"\t\tDone!\nTesting Tasks.."<<endl;
    testTask();
    cout<<"\t\tDone!\nTesting Priority Tasks..."<<endl;
    testPTask();
    cout<<"\t\tDone!\nTesting Project..."<<endl;
    testProject();
    cout<<"\t\tDone!\nAll tests complete."<<endl;

}

void testNode(){//done

    //Test a Node besides our Task and Priority Task objects
    cout<<"-----Testing Node-----"<<endl;
    {
        Node<int>* testNode = new Node<int>(1);

        if (testNode->data != 1) cout << ".data fail" << endl;
        else cout << ".data correct" << endl;
        if (testNode->next != nullptr) cout << ".next fail" << endl;
        else cout << ".next correct" << endl;
        if (testNode->prev != nullptr) cout << ".prev fail" << endl;
        else cout << ".prev correct" << endl;

        //Test a change in Task
        delete testNode;
        testNode = NULL;
    }
    //Test changes to Node based on same Node<T> types
    cout<<"-----Testing Changes in Node data-----"<<endl;
    {   //Node* must be same type to point to each other.
        //  eg: Node<int> and Node<string> are incompatible
        //  solution: use only string to demonstrate .next and .prev
        Node<string>* testNode = new Node<string>("1");
        testNode->data = "1";
        if (testNode->data != "1") cout << ".data fail" << endl;
        else cout << ".data match correct" << endl;

        Node<string>* nextNode = new Node<string>("second");
        testNode->next = nextNode;
        Node<string>* prevNode = new Node<string>("first");
        testNode->prev = prevNode;


        if(testNode->next != nextNode && testNode->next->data != "second")
            cout<<".next or .next.data fail"<<endl;
        else cout<<".next && .next.data correct"<<endl;
        if(testNode->next->next != nullptr) cout<<".next.next fail"<<endl;
        else cout<<".next.next correct"<<endl;
        if(testNode->prev != prevNode && testNode->prev->data != "first")
            cout<<".prev or .prev.data fail"<<endl;
        else cout<<".prev.data and .prev.prev correct"<<endl;
        if(testNode->prev->prev != nullptr) cout<<".prev.prev fail"<<endl;
        else cout<<".prev.prev correct"<<endl;


        delete nextNode;
        delete prevNode;
        delete testNode;
        testNode = NULL;
        nextNode = NULL;
        prevNode = NULL;
    }
}
void testLL(){
    //Basic LL test
    cout<<"-----Testing Basic Linked List-----"<<endl;
    {
        LinkedList<Task *> *testList = new LinkedList<Task *>();

        if (testList->head != nullptr) cout << ".head fail" << endl;
        else cout << ".head correct" << endl;
        if (testList->tail != nullptr) cout << ".tail fail" << endl;
        else cout << ".tail correct" << endl;

        delete testList;
        testList = nullptr;
    }

    //Test size 3 Linked List
    cout<<"-----Testing Linked List Size 3-----"<<endl;
    {
        LinkedList<int>* testList = new LinkedList<int>();
        testList->push_back(2);
        testList->push_back(3);
        testList->insert(1, testList->head);

        if(testList->head->next->data != 2) cout<<"push/insert fail"<<endl;
        else cout<<"push/insert correct"<<endl;

        delete testList;
        testList = nullptr;
    }
}
void testTask(){//needs operator
    //Test Task data members
    cout << "-----Testing Task-----" << endl;
    {
        Task *task = new Task("Title", "Desc");

        if (task->getTitle() != "Title") cout << ".title fail" << endl;
        else cout << ".title match correct" << endl;
        if (task->getDescription() != "Desc") cout << ".description fail" << endl;
        else cout << ".description match correct" << endl;

        cout << "operator tests coming soon" << endl;

        delete task;
        task = NULL;
    }
}
void testPTask(){//needs operator
    //Test Priority Task data members and inheritance
    cout << "-----Testing Priority Task-----" << endl;
    {
        PriorityTask *task = new PriorityTask("Title", "Desc", 1);

        if (task->getTitle() != "Title") cout << ".title fail" << endl;
        else cout << ".title match correct" << endl;
        if (task->getDescription() != "Desc") cout << ".description fail" << endl;
        else cout << ".description match correct" << endl;
        if (task->getPriority() != 1) cout << ".priority fail" << endl;
        else cout << ".priority correct" << endl;

        cout << "operator tests coming soon" << endl;

        delete task;
        task = NULL;
    }
}
void testProject(){
    cout<<""<<endl;
}