#include <iostream>
using namespace std;

template <typename T> 
class Lower_Triangle
{
public:
    T *arr;
    int size;

    Lower_Triangle(int n)
    {
        size = n;
        arr = new T[n];
    }

    void set(int i, int j, T value);
    T get(int i, int j);
};

template <typename T>
void Lower_Triangle<T>::set(int i, int j, T value)
{
    if ((i < j) || (i > size || i < 0) || (j > size || j < 0))
    {
        cout << "Invalid arguments." << endl;
        return;
    }
    else
    {
        int k = ((i * (i - 1)) / 2) + (j - 1);
        *(arr + k) = value;
        return;
    }
}

template <typename T>
T Lower_Triangle<T>::get(int i, int j)
{
    if ((i < j) || (i > size || i < 0) || (j > size || j < 0))
    {
        cout << "Invalid arguments." << endl;
        return 1;
    }
    else
    {
        int k = ((i * (i - 1)) / 2) + (j - 1);
        return *(arr+k);
    }
}

int main()
{
    int order;
    int choice;
    cout << "Enter the order of the matrix- ";
    cin >> order;
    Lower_Triangle<int> obj(order);
    while (true)
    {
        cout << "Enter 1 to set value in the matrix.\nEnter 2 to get a value from the matrix.\nEnter 3 to exit.\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int i, j;
            int temp;
            cout << "Enter the position at which value is to be set- "<<endl;
            cin >> i;
            cin >> j;
            cout << "Enter the value to be set- ";
            cin >> temp;
            obj.set(i, j, temp);
            break;

        case 2:
            int h, k;
            cout << "Enter the position from which value is wanted- "<<endl;
            cin >> h;
            cin >> k;
            cout << "The value at " << h << "," << k << " is " << obj.get(h, k)<<endl;
            break;

        case 3:
            exit(0);
        }
    }
}