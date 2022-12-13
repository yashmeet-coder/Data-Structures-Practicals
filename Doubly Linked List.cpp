#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    Node *prev;
    int data;

    Node(int element)
    {
        next = NULL;
        prev = NULL;
        data = element;
    }
};

class DoublyLinkedList
{
public:
    Node *head = NULL;
    Node *tail = NULL;

    int addAtHead(int data)
    {
        Node *myNode = new Node(data);
        if (head == NULL)
        {
            head = myNode;
            tail = myNode;
        }
        else
        {
            myNode->next = head;
            head->prev = myNode;
            head = myNode;
        }
        return 0;
    }

    void ithinsertion(int pos, int data)
    {
        Node *myNode = new Node(data);
        if (pos == 1)
        {
            head = myNode;
            myNode->next = NULL;
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

    int removeFromhead()
    {
        Node *p = head;
        if (p == NULL)
        {
            cout << " Unable to remove. List is empty";
            return -1;
        }
        else if (p->next == NULL)
        {
            delete p;
            head = NULL;
        }
        else
        {
            p->next->prev = NULL;
            head = p->next;
            delete p;
        }
        return 0;
    }

    void addAtTail(int data)
    {
        Node *myNode = new Node(data);

        tail->next = myNode;
        myNode->prev = tail;
        tail = myNode;
    }

    void removefromtail()
    {
        if (head == tail)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            tail->prev->next = NULL;
            tail = tail->prev;
        }
    }

    void ithremove(int pos)
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
        }
        if (head == tail)
        {
            delete head;
        }
        else
        {
            Node *temp = head;
            Node *k;
            for (int i = 0; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            k = temp;
            k->prev->next = k->next;
            delete temp;
        }
        return;
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

    void display()
    {
        Node *p = head;
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }
};

int main()
{
    DoublyLinkedList obj1;
    DoublyLinkedList obj2;
    int choice;
    Node *k;
    while (true)
    {
        cout << "---------Menu---------" << endl;
        cout << "Enter 1 to add at head\n";
        cout << "Enter 2 to remove from head\n";
        cout << "Enter 3 to add at ith position\n";
        cout << "Enter 4 to delete from ith position \n";
        cout << "Enter 5 to add at tail \n";
        cout << "Enter 6 to remove from tail \n";
        cout << "Enter 7 to search in the list\n";
        cout << "Enter 8 to concatenate two lists\n";
        cout << "Enter 9 to display\n";
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
            obj1.removeFromhead();
            break;

        case 3:
            int pos;
            int temp;
            cout << "Enter the number and the position at which element is to added: ";
            cin >> pos;
            cin >> temp;
            obj1.ithinsertion(temp, pos);
            break;
        case 4:
            int position;
            cout << "Enter the position from which element is to be deleted: ";
            cin >> position;
            obj1.ithremove(position);
            break;

        case 5:
            int temp3;
            cout << "Enter an element to add at tail: ";
            cin >> temp3;
            obj1.addAtTail(temp3);
            break;

        case 6:
        obj1.removefromtail();
        break;

        case 7:
            int temp1;
            cout << "Enter the element to be searched: ";
            cin >> temp1;
            k = obj1.search(temp1);
            if (k == NULL)
                cout << "Element not found.";
            else
                cout << k;
            break;

        case 8:
            obj2.addAtHead(5);
            obj2.addAtHead(10);
            obj2.addAtHead(15);
            obj2.addAtHead(25);
            obj2.addAtHead(35);
            obj2.concatenate(obj1.head, obj2.head);
            break;

        case 9:
            obj1.display();
            break;

        case -1:
            exit(0);
        }
    }
}
