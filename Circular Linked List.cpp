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

class circularLinkedList
{
public:
    Node *head = NULL;
    Node *tail = NULL;

    void display()
    {
        if (head == NULL)
            cout << "Empty";
        else
        {
            Node *p = head;
            cout << p->data << " ";
            while (p->next != head)
            {
                p = p->next;
                cout << p->data << " ";
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
            tail = myNode;
            myNode->next = NULL;
        }
        else
        {
            myNode->next = head;
            head = myNode;
            tail->next = head;
        }
        return 0;
    }

    int insertafter(int x, int target)
    {
        Node *temp = head;
        Node *myNode = new Node(target);
        while (temp->next != head)
        {
            if (temp->data == x)
            {
                myNode->next = temp->next;
                temp->next = myNode;
            }
            temp = temp->next;
        }
    }

    void addattail(int element)
    {
        Node *myNode = new Node(element);
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

    void removeFromtail()
    {
        if (tail == NULL)
        {
            cout << "list is empty.";
            return;
        }
        else
        {
            Node *temp = head;
            Node *k;
            while (temp->next != head)
            {
                k = temp;
                temp = temp->next;
            }
            k->next = head;
            delete temp;
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

    void remove(int item)
    {
        Node *temp = tail->next; // Refers to the first index
        Node *prev_node = NULL;

        if (temp->data == item)
            tail->next = temp->next;

        else
        {
            while (temp != tail && temp->data != item)
            {
                prev_node = temp;
                temp = temp->next;
            }

            if (temp == tail)
            {
                if (tail->data != item)
                {
                    return;
                }
                else
                {
                    prev_node->next = tail->next;
                    tail = prev_node->next;
                }
            }
            else
            {
                prev_node->next = temp->next;
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

    void concatenate(Node *head1, Node *head2, Node *tail1, Node *tail2)
    {
        tail1->next = head2;
        tail2->next = head1;
    }
};

int main()
{
    circularLinkedList obj1;
    circularLinkedList obj2;
    int choice;
    Node *k;
    while (true)
    {
        cout << "---------Menu---------" << endl;
        cout << "Enter 1 to add at head\n";
        cout << "Enter 2 to remove from head\n";
        cout << "Enter 3 to add at element after another element\n";
        cout << "Enter 4 to delete an element \n";
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
            int temp;
            int temp1;
            cout << "Enter the number after which element is to added and the element to be added: ";
            cin >> temp;
            cin >> temp1;
            obj1.insertafter(temp, temp1);
            break;
        case 4:
            int position;
            cout << "Enter the element is to be deleted: ";
            cin >> position;
            obj1.remove(position);
            break;

        case 5:
            int temp3;
            cout << "Enter an element to add at tail: ";
            cin >> temp3;
            obj1.addattail(temp3);
            break;

        case 6:
            obj1.removeFromtail();
            break;

        case 7:
            int temp5;
            cout << "Enter the element to be searched: ";
            cin >> temp5;
            k = obj1.search(temp5);
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
            obj2.concatenate(obj1.head, obj2.head, obj1.tail, obj2.tail);
            break;

        case 9:
            obj1.display();
            break;

        case -1:
            exit(0);
        }
    }
}