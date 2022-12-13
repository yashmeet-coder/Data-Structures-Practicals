#include <iostream>
using namespace std;

template <typename T> class Node
{
public:
    T data;
    Node<T> *next = NULL;

    Node(T element)
    {
        data = element;
    }
};

template<typename T>class Linked_Queue
{
public:
    Node<T> *head = NULL;
    Node<T> *tail = NULL;

    void addattail(int element)
    {
        Node<T> *myNode = new Node<T>(element);
        if (tail == NULL)
        {
            head = myNode;
            tail = myNode;
        }
        else
        {
            tail->next = myNode;
            myNode->next = head;
            tail = myNode;
        }
    }

    void removeFromhead()
    {
        if (head == NULL)
        {
            cout << "list is empty.";
            return;
        }
        else
        {
            if (head == tail)
            {
                delete head;
            }
            tail->next = head->next;
            delete head;
            head = tail->next;
        }
    }

    void display()
    {
        if (head == NULL)
            cout << "Empty";
        else
        {
            Node<T> *p = head;
            cout << p->data << " ";
            while (p->next != head)
            {
                p = p->next;
                cout << p->data << " ";
            }
        }
    }

};

class Queue{
    Linked_Queue<int> obj;
    public:
    void enqueue(int data)
    {
       obj.addattail(data);
    }

    void dequeue()
    {
        obj.removeFromhead();
    }

    void display()
    {
        obj.display();
    }
};

int main()
{
    int choice;
    Queue ob;
    while(true)
    {
    cout<<"Enter 1 to add into the queue.\nEnter 2 to dequeue.\nEnter 3 to display the queue.\nEnter 4 to exit.\n";
    cin>>choice;
    switch(choice)
    {
        case 1:
        int temp;
        cout<<"Enter the element to be pushed."<<endl;
        cin>>temp;
        ob.enqueue(temp);
        break;

        case 2:
        ob.dequeue();
        break;

        case 3:
        ob.display();
        cout<<endl;
        break;

        case 4:
        exit(0);
        break;
    }
}}