#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;

    Node(int element)
    {
        data = element;
    }
};

class SinglyLinkedList
{
public:
    Node *head = NULL;

    void display()
    {
        if (head == NULL)
            cout << "Empty";
        else
        {
            Node *p = head;
            while (p != NULL)
            {
                cout << p->data << " ";
                p = p->next;
            }
        }
    }

    int addAtHead(int data)
    {
        Node *myNode = new Node(data);
        if (myNode == NULL)
            return -1;
        if (head == NULL)
        {
            head = myNode;
        }
        else
        {
            myNode->next = head;
            head = myNode;
        }
        return 0;
    }

    void removefromhead()
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
                Node *temp;
                temp = head->next;
                delete head;
                head = temp;
            }
        }
    }

    int addAtith(int data, int pos)
    {
        Node *myNode = new Node(data);
        if (pos == 1)
        {
            head = myNode;
            myNode->next = NULL;
        }
        else
        {
            if (pos == 2)
            {
                myNode->next = head->next;
                head->next = myNode;
            }
            else
            {

                Node *temp = head;
                for (int i = 0; i < pos - 2; i++)
                {
                    temp = temp->next;
                }
                myNode->next = temp->next;
                temp->next = myNode;
            }
        }
    }

    void ithdelete(int pos)
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
        }
        else
        {
            if (pos == 1)
            {
                delete head;
                cout << "List is empty now.";
            }
            else
            {
                Node *temp = head;
                Node *k;
                Node *prev;
                for (int i = 0; i < pos - 1; i++)
                {
                    prev = temp;
                    temp = temp->next;
                }
                k = temp->next;
                prev->next = k;
                delete temp;
            }
        }
    }

    Node *search(int x)
    {
        if (head == NULL)
        {
            cout << "List is Empty." << endl;
        }
        else
        {
            Node *temp = head;
            while (temp != NULL)
            {
                if (temp->data == x)
                    return temp;
                temp = temp->next;
            }
        }
        return NULL;
    }

    void concatenate(Node *head1, Node *head2)
    {
        while (head1->next != NULL)
        {
            head1 = head1->next;
        }
        head1->next = head2;
        head2 = NULL;
    }
};

int main()
{
    SinglyLinkedList obj1;
    SinglyLinkedList obj2;
    int choice;
    Node *k;
    while (true)
    {
        cout << "---------Menu---------" << endl;
        cout << "Enter 1 to add at head\n";
        cout << "Enter 2 to remove from head\n";
        cout << "Enter 3 to add at ith position\n";
        cout << "Enter 4 to delete from ith position \n";
        cout << "Enter 5 to search in the list\n";
        cout << "Enter 6 to concatenate two lists\n";
        cout << "Enter 7 to display\n";
        cout << "Enter -1 to exit\n";
        cout << "Enter your choice:\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int temp2;
            cout << "Enter an element to add at head: ";
            cin >> temp2;
            obj1.addAtHead(temp2);
            break;

        case 2:
            obj1.removefromhead();
            break;

        case 3:
            int pos;
            int temp;
            cout << "Enter the number and the position at which element is to added: ";
            cin >> pos;
            cin >> temp;
            obj1.addAtith(temp, pos);
            break;
        case 4:
            int position;
            cout << "Enter the position from which element is to be deleted: ";
            cin >> position;
            obj1.ithdelete(position);
            break;

        case 5:
            int temp1;
            cout << "Enter the element to be searched: ";
            cin >> temp1;
            k = obj1.search(temp1);
            if (k == NULL)
                cout << "Element not found.";
            else
                cout << k;
            break;

        case 6:
            obj2.addAtHead(5);
            obj2.addAtHead(10);
            obj2.addAtHead(15);
            obj2.addAtHead(25);
            obj2.addAtHead(35);
            obj2.concatenate(obj1.head,obj2.head);
            break;

        case 7:
            obj1.display();
            break;

        case -1:
            exit(0);
        }
    }
}
