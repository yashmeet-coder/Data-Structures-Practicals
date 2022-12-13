#include <iostream>
using namespace std;

class binarySearch
{
public:
    int *arr;
    int size;

    binarySearch(int n)
    {
        size = n;
        arr = new int[size];
    }

    int BinarySearch(int target)
    {
        int start = 0;
        int end = size - 1;
        for (int i = start; i < end; i++)
        {
            int middle = (start + end) / 2;
            if (arr[middle] == target)
                return middle;
            else if (target < arr[middle])
                end = middle - 1;
            else if (target > arr[middle])
                start = middle + 1;
        }
        return -1;
    }
};

int main()
{
    int length, element;
    cout << "Enter the length of the array: ";
    cin >> length;
    binarySearch obj(length);
    cout << "Enter the elements of the array: ";
    int i = 0;
    while (i < obj.size)
    {
        cin >> obj.arr[i];
        i++;
    }
    cout << "Enter the element to be searched for: ";
    cin >> element;
    int result = obj.BinarySearch(element);
    if (result == -1)
        cout << "The element was not found";
    else
        cout << "The element was found at index " << result;
    return 0;
}