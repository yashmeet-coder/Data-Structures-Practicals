#include <iostream>
using namespace std;

class Queue
{
public:
    int front = 0;
    int rear = 0;
    int *arr;
    int size;
    int k;
    bool flag = false;

    Queue(int n)
    {
        size = n;
        arr = new int[size];
    }

    bool isFull()
    {
        if (rear == size || rear==front-1)
            return true;

        return false;
    }

    bool isEmpty()
    {
        if (rear == 0 && front == 0)
            return true;
        else if (front == size || rear == 0)
            return true;

        return false;
    }

    void enqueue(int a)
    {
        if (rear == size && flag)
        {
            rear = 0;
            arr[rear++] = a;
        }
        else if (!isFull())
        {
            arr[rear++] = a;
        }

        else if (isFull())
            cout << "Queue is full" << endl;
    }

    void dequeue()
    {
        int c = arr[front];
        if (!isEmpty())
        {   k++;
            front++;
            flag = true;
        }
        else
            cout << "Queue is Empty" << endl;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
    }
};

int main()
{
    int len;
    cout << "Enter the size: ";
    cin >> len;
    Queue obj(len);
    for (int i = 0; i < len; i++)
    {
        obj.enqueue(i);
    }
    obj.dequeue();
    obj.enqueue(50);
    obj.dequeue();
    cout<<obj.front<<endl;
    cout<<obj.rear<<endl;
    obj.display();

    return 0;
}