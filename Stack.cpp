#include <iostream>
using namespace std;

class Stack
{
private:
    int value;
    int length;
    int *arr;
    int tos = -1;

public:
    void setArrayLength(int a)
    {
        arr = new int[a];
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

    int push(int a)
    {
        if (!isFull())
        {
            arr[++tos] = a;
            return 0;
        }
        else
        {
            return 1;
        }
    }

    int pop()
    {
        if (!isEmpty())
        {
            tos--;
            return 0;
        }
        else
        {
            return 1;
        }
    }

    int TOStack()
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

int main()
{
    int choice;
    char ch;

    Stack obj;
    int len;
    cout << "Enter the length of the stack" << endl;
    cin >> len;
    obj.setArrayLength(len);

    while (true)
    {
        cout << "Enter Choice\n1)Push an element\n2)Pop an element\n3)TOStack\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int a;
            cout << "Enter the element you want to push" << endl;
            cin >> a;
            int b;
            b = obj.push(a);
            if (b == 0)
            {
                cout << "Element Pushed." << endl;
            }
            else
            {
                cout << "Stack Overflow.Element not Pushed" << endl;
            }
            break;
        case 2:
            int c;
            c = obj.pop();
            if (c == 0)
            {
                cout << "Element Popped" << endl;
            }
            else
            {
                cout << "Stack Underflow.Element not Popped" << endl;
            }
            break;

        case 3:

            int k;
            k = obj.TOStack();
            if (k != -1)
            {
                cout << "Element at the Top of the Stack is: " << k << endl;
            }
            else
            {
                cout << "Stack is Empty." << endl;
            }
            break;

        }
        cout << "Press Y to continue" << endl;
        cin >> ch;
        if (ch == 'Y' || ch == 'y')
        {
            continue;
        }
        else
        {
            cout << "Exiting.";
            break;
        }
    }
}
