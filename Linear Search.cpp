#include <iostream>
using namespace std;

class linearSearch{
    public:
    int *arr;
    int size;

    linearSearch(int n){
        size = n;
        arr = new int[size];
    }

    int LinearSearch(int target)
    {
        for(int i=0;i<size;i++)
        {
            if(target==arr[i])
            return i;
        }
        return -1;
    }
};


int main()
{   int length,element;
    cout<<"Enter the size of the array: ";
    cin>>length;
    linearSearch obj(length);
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<length;i++)
    {
          cin>>obj.arr[i];
    }

    cout<<"Enter the element to be searched for: ";
    cin>>element;
    int result = obj.LinearSearch(element);
    if(result==-1)
    cout<<"The element was not found";
    else
    cout<<"The element was found at index "<<result;
    return 0;
}