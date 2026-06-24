#include <iostream>
#include "DynamicArray.h"

using namespace std;

int main()
{
    DynamicArray<int> arr;

    cout << "Is Empty: " << arr.isEmpty() << endl;

    arr.append(10);
    arr.append(20);
    arr.append(30);
    arr.append(40);
    arr.append(50);

    cout << "\nArray Elements:" << endl;

    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr.get(i) << " ";
    }
     cout << endl;

    cout << "\nSize: " << arr.size() << endl; 
    cout << "Capacity: " << arr.capacity() << endl;

    arr.insert(2, 100); 

    cout << "\nAfter Insert at Index 2:" << endl;

    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr.get(i) << " ";
    }
cout << endl;

    arr.remove(3);

    cout << "\nAfter Remove Index 3:" << endl;

    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr.get(i) << " ";
    }
cout << endl;

    cout << "\nElement at Index 2: " << arr.get(2) << endl;

    arr.set(2, 200);

    cout << "\nAfter Set Index 2 = 200:" << endl;

    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr.get(i) << " ";
    }cout << endl;

    cout << "\nFind 200: " << arr.find(200) << endl;

    if(arr.contains(50))
    {
        cout << "50 Found" << endl;
    }
    else
    {
        cout << "50 Not Found" << endl;
    }
    arr.clear();

    cout << "\nAfter Clear:" << endl;
    cout << "Size: " << arr.size() << endl;
    cout << "Is Empty: " << arr.isEmpty() << endl;

    return 0;
}
