#include <iostream>
using namespace std;

template <class T> class Stack
{
public:
    int length;
    T *arr;
    int tos;

    void setlength(int a)
    {
        arr = new T[a];
        length = a;
    }

    bool isEmpty()
    {
        if (tos == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if (tos == length - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(T a)
    {
        if (!isFull())
        {   
            arr[++tos] = a;
        }
    }

    void pop()
    {
        if (!isEmpty())
        {
            tos--;
        }
        
    }

    T TOStack()
    {
        if (!isEmpty())
        {
            return arr[tos];
        }
        else
        {
            return -1;
        }
    }
};