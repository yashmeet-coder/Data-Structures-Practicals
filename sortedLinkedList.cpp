#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int element)
    {
        data = element;
        next = NULL;
    }
};

class sortedLinkedList
{
public:
    Node *head = NULL;
    // Node *tail = NULL;
    Node *curr;
    Node *prev;

    void inSortedOrder(int element)
    {
        Node *myNode = new Node(element);
        if (head == NULL)
        {
            head = myNode;
            prev = NULL;
            return;
        }

        if (head->next == NULL || head->data>element)
        {
            if (head->data > element)
            {
                myNode->next = head;
                head = myNode;
                prev = NULL;
            }
            else{
                prev = head;
                head->next = myNode;
            }
            return;
        }
        
        Node *temp = head;
        while(element>temp->data && temp->next!=NULL)
        {   
            prev = temp;
            temp = temp->next;
        }
        if (temp->next==NULL)
        {
            temp->next = myNode;
            myNode->next = NULL;
        }
        else
        {
            prev->next = myNode;
            myNode->next = temp;
        }
        
 }

    void display(){
        Node *p = head;
        while(p!=NULL){
            cout<<p->data<<" ";
            p = p->next;
        }
    }
};

int main(){
    sortedLinkedList obj;
    obj.inSortedOrder(3);
    obj.inSortedOrder(5);
    obj.inSortedOrder(6);
    obj.inSortedOrder(4);
    obj.inSortedOrder(7);
    obj.inSortedOrder(2);
    obj.inSortedOrder(10);
    obj.inSortedOrder(30);
    obj.display();
}