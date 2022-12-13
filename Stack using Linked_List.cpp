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

template<typename T>class Linked_Stack
{
public:
    Node<T> *head = NULL;

    void addAthead(T data)
    {
        Node<T> *myNode = new Node<T>(data);
        if (head == NULL)
        {
            head = myNode;
        }
        else
        {
            myNode->next = head;
            head = myNode;
        }
    }

    void removeFromhead()
    {
         if (head == NULL)
            cout << "List is empty." << endl;
        else
        {
            if (head->next == NULL)
            {
                delete head;
                cout << "List is empty now.";
            }
            else
            {
                Node<T> *temp;
                temp = head->next;
                delete head;
                head = temp;
            }
        }
    }

    T top_element()
    {
        return head->data;
    }

};

class Stack{
    Linked_Stack<int> obj;
    public:
    void push(int data)
    {
       obj.addAthead(data);
    }

    void pop()
    {
        obj.removeFromhead();
    }

    void TOStack()
    {
        cout<<"The Top element of the stack is "<<obj.top_element();
    }
};

int main()
{
    int choice;
    Stack ob;
    while(true)
    {
    cout<<"Enter 1 to push into the stack.\nEnter 2 to pop from the stack.\nEnter 3 to display the top element of the stack.\nEnter 4 to exit.\n";
    cin>>choice;
    switch(choice)
    {
        case 1:
        int temp;
        cout<<"Enter the element to be pushed."<<endl;
        cin>>temp;
        ob.push(temp);
        break;

        case 2:
        ob.pop();
        break;

        case 3:
        ob.TOStack();
        cout<<endl;
        break;

        case 4:
        exit(0);
        break;
    }
}}