#include <iostream>
#include <string>
#include <cstring>
#include "stck.h"

int main()
{
    string num1;
    string num2;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    Stack<int> obj1;
    Stack<int> obj2;
    Stack<int> obj3;

    obj1.tos = -1;
    obj2.tos = -1;

    obj1.setlength(num1.length());
    obj2.setlength(num2.length());

    if (num1.length() >= num2.length())
        obj3.setlength(num1.length() + 1);
    else
        obj3.setlength(num2.length() + 1);

    obj3.tos = -1;

    for (int i = 0; i < num1.length(); i++)
    {
        obj1.push(num1[i] - 48);
      
    }

    for (int i = 0; i < num2.length(); i++)
    {
        obj2.push(num2[i] - 48);
       
    }

    int top1 = obj1.tos;
    int top2 = obj2.tos;
    int carry = 0;

    while (top1 >= 0 || top2 >= 0)
    {
        int sum = 0;

        if (top2 == -1)
        {
            while (top1 >= 0)
            {
                sum = obj1.arr[top1];
                obj3.push(sum);
              
                top1--;
            }
        }
        else
        {
            sum = sum + carry + obj1.arr[top1] + obj2.arr[top2];
            if (sum >= 10)
            {
                    carry = sum / 10;
                    obj3.push(sum%10);
                   
            }
            else
            {
                 obj3.push(sum);
               
                carry = 0;
            }
        }
        top1--;
        top2--;
        if(obj3.tos==obj3.length-2 && carry!=0)
        {
            obj3.push(carry);
            break;
        }
    }

    while (obj3.tos > -1)
    {
        cout << obj3.TOStack();
        obj3.tos--;
    }
}
