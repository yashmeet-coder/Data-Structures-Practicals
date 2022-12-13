#include <iostream>
#include "stck.h"
using namespace std;

class infix
{
public:
     int precedence(char ch)
     {
          if (ch == '/')
               return 4;
          if (ch == '*')
               return 3;
          if (ch == '+')
               return 2;
          if (ch == '-')
               return 1;
     }
};

int main()
{
     infix ob1;
     string str;
     cout << "Enter a string: ";
     cin >> str;
     Stack<char> obj;
     Stack<int> obj2;
     obj.setlength(str.length());
     obj.tos = -1;
     char ch;
     char c1;
     int oper = 0;
     string postfix = "";

     for (int i = 0; i < str.length(); i++)
     {
          ch = str[i];
          if (ch == '/' || ch == '*' || ch == '+' || ch == '-')
          {
               oper++;
               if (obj.tos == -1)
                    obj.push(ch);
               else
               {
                    if (ob1.precedence(ch) < ob1.precedence(obj.TOStack()) && obj.tos > -1)
                    {
                         while (obj.tos > -1)
                         {
                              if (ob1.precedence(ch) < ob1.precedence(obj.TOStack()))
                              {
                                   postfix += obj.TOStack();
                                   obj.pop();
                              }
                         }
                         obj.push(ch);
                    }

                    else
                         obj.push(ch);
               }
          }
          else
               postfix += ch;
     }

     while (obj.tos > -1)
     {
          postfix += obj.TOStack();
          obj.tos--;
     }
     cout << "The postfix expression is: "<<postfix;
     cout << endl;

     obj2.setlength(oper + 1);
     obj2.tos = -1;

     // Evaluating the expression
     int answer = 0;
     int top1 = 0;
     int top2 = 0;
     for (int i = 0; i <= postfix.length(); i++)
     {
          c1 = postfix[i];

          if ((int)c1 >= 48 && (int)c1 <= 57)
               obj2.push(postfix[i] - 48);

          if (c1 == '/' || c1 == '+' || c1 == '*' || c1 == '-')
          {

               switch (c1)
               {
               case '/':
                    top1 = obj2.TOStack();
                    obj2.pop();
                    top2 = obj2.TOStack();
                    obj2.pop();
                    answer = top1 / top2;
                    obj2.push(answer);
                    break;

               case '*':
                    top1 = obj2.TOStack();
                    obj2.pop();
                    top2 = obj2.TOStack();
                    obj2.pop();
                    answer = top1 * top2;
                    obj2.push(answer);
                    break;

               case '+':
                    top1 = obj2.TOStack();
                    obj2.pop();
                    top2 = obj2.TOStack();
                    obj2.pop();
                    answer = top1 + top2;
                    obj2.push(answer);
                    break;

               case '-':
                    top1 = obj2.TOStack();
                    obj2.pop();
                    top2 = obj2.TOStack();
                    obj2.pop();
                    if(top1>top2)
                    answer = top1 - top2;
                    else
                    answer = top2-top1;
                    obj2.push(answer);
                    break;
               }
          }
     }

     cout <<"Evaluated answer: "<<(obj2.TOStack());
}
