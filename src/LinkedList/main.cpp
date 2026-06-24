#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList<int> list;

    cout << "Is Empty: " << list.isEmpty() << endl;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);
    list.insertFront(5);

    cout << "List after insertions (should be 5 10 20 30):" << endl;
    list.display();

    cout << "Size: " << list.size() << endl;

    cout << "Get at index 2: " << list.get(2) << endl;
    list.set(2, 25);
    cout << "After setting index 2 to 25 (should be 5 10 25 30):" << endl;
    list.display();

    list.insert(2, 15);
    cout << "After inserting 15 at index 2 (should be 5 10 15 25 30):" << endl;
    list.display();

    list.remove(3);
    cout << "After removing index 3 (should be 5 10 15 30):" << endl;
    list.display();

    cout << "Contains 15: " << list.contains(15) << endl;
    cout << "Search 25: " << list.search(25) << endl;
    cout << "Find 30 (index): " << list.find(30) << endl;

    list.deleteFront();
    cout << "After deleteFront (should be 10 15 30):" << endl;
    list.display();

    list.deleteBack();
    cout << "After deleteBack (should be 10 15):" << endl;
    list.display();

    // Testing Deep Copy via Copy Constructor
    LinkedList<int> copiedList(list);
    cout << "Copied list display (should be 10 15):" << endl;
    copiedList.display();

    copiedList.insertBack(100);
    cout << "Copied list after insertBack(100) (should be 10 15 100):" << endl;
    copiedList.display();
    cout << "Original list (should remain 10 15):" << endl;
    list.display();

    // Testing Copy Assignment
    LinkedList<int> assignedList;
    assignedList = copiedList;
    cout << "Assigned list display (should be 10 15 100):" << endl;
    assignedList.display();

    assignedList.clear();
    cout << "Assigned list size after clear: " << assignedList.size() << " (Empty: " << assignedList.isEmpty() << ")" << endl;

    // Test error handling
    cout << "\nTesting error cases:" << endl;
    assignedList.deleteFront();
    assignedList.deleteBack();
    assignedList.get(0);
    assignedList.set(0, 1);
    assignedList.remove(0);
    assignedList.insert(5, 5);

    // Non-primitive types testing
    LinkedList<string> strList;
    strList.insertBack("Hello");
    strList.insertBack("World");
    cout << "\nString List display:" << endl;
    strList.display();

    return 0;
}
