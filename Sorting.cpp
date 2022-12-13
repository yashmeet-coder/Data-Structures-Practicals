#include <iostream>
#include <string>
using namespace std;

template <class T>
class Array
{
public:
    int length;
    T *arr;

    Array(int a)
    {
        arr = new T[a];
        length = a;
    }

    void bubbleSort()
    {
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < length - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                    swap(arr[j], arr[j + 1]);
            }
        }
    }

    void insertionSort()
    {
        for (int i = 1; i < length; i++)
        {
            int temp = arr[i];
            int j = i - 1;
            while (temp < arr[j] && j >= 0)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;
        }
    }

    void selectionSort()
    {
        for (int i = 0; i < length; i++)
        {
            int min = arr[i];
            for (int j = i + 1; j < length; j++)
            {
                if (arr[j] < min)
                {
                    min = arr[j];
                    swap(arr[i], arr[j]);
                }
            }
        }
    }
};

int main()
{
    int size, choice;
    char choice1;
    cout << "Enter the length of the array: ";
    cin >> size;
    cout << "Enter C for char array and I for integer array: ";
    cin >> choice1;
    switch (choice1)
    {
    case 'C':
    {
        Array<char> obj2(size);
        cout << "Enter the elements of the array: ";
        for (int i = 0; i < size; i++)
            cin >> obj2.arr[i];
        cout << "1.Press 1 to sort using bubble sort.\n2.Press 2 to sort using insertion sort.\n3.Press 3 to sort using selection sort " << endl;
        cin >> choice;
        if (choice == 1)
            obj2.bubbleSort();
        else if (choice == 2)
            obj2.insertionSort();
        else
            obj2.selectionSort();
        cout << "The sorted array is: ";
        for (int i = 0; i < size; i++)
            cout << obj2.arr[i] << " ";
        break;
    }
    case 'I':
    {
        Array<int> obj1(size);
        cout << "Enter the elements of the array: ";
        for (int i = 0; i < size; i++)
            cin >> obj1.arr[i];
        cout << "1.Press 1 to sort using bubble sort.\n2.Press 2 to sort using insertion sort.\n3.Press 3 to sort using selection sort " << endl;
        cin >> choice;
        if (choice == 1)
            obj1.bubbleSort();
        else if (choice == 2)
            obj1.insertionSort();
        else
            obj1.selectionSort();
        cout << "The sorted array is: ";
        for (int i = 0; i < size; i++)
            cout << obj1.arr[i] << " ";
        break;
    }
    }
}