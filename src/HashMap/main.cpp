#include <iostream>
#include <string>
#include "HashMap.h"

using namespace std;

int main()
{
    HashMap<string, int> map;

    cout << "Is Empty: " << map.isEmpty() << endl;
    cout << "Initial Capacity: " << map.bucketCount() << endl;

    // Insert elements to trigger collision and verify separate chaining
    map.insert("Alice", 100);
    map.insert("Bob", 200);
    map.insert("Charlie", 300);
    map.insert("Dave", 400);
    map.insert("Eve", 500);

    cout << "\nAfter inserting 5 elements:" << endl;
    cout << "Size: " << map.size() << endl;
    cout << "Load Factor: " << map.loadFactor() << endl;
    map.display();

    // Insert more elements to trigger rehashing (> 0.75 load factor: 6/8 = 0.75, 7/8 = 0.875 > 0.75)
    map.insert("Frank", 600);
    map.insert("Grace", 700);

    cout << "\nAfter inserting 2 more elements (should trigger rehash):" << endl;
    cout << "Size: " << map.size() << endl;
    cout << "Capacity: " << map.bucketCount() << endl;
    cout << "Load Factor: " << map.loadFactor() << endl;
    map.display();

    // Testing get, update, containsKey
    cout << "\nGet Alice: " << map.get("Alice") << endl;
    map.update("Alice", 150);
    cout << "Get Alice (after update): " << map.get("Alice") << endl;
    cout << "Contains Bob: " << map.containsKey("Bob") << endl;
    cout << "Contains Zach: " << map.containsKey("Zach") << endl;

    // Testing remove
    map.remove("Bob");
    cout << "\nAfter removing Bob:" << endl;
    cout << "Size: " << map.size() << endl;
    cout << "Contains Bob: " << map.containsKey("Bob") << endl;
    map.display();

    // Testing Deep Copy via Copy Constructor
    HashMap<string, int> copiedMap(map);
    cout << "\nCopied map size: " << copiedMap.size() << " (Capacity: " << copiedMap.bucketCount() << ")" << endl;
    copiedMap.display();

    // Modify copy
    copiedMap.insert("Zach", 999);
    cout << "\nCopied map after inserting Zach:" << endl;
    copiedMap.display();
    cout << "\nOriginal map (should not have Zach):" << endl;
    map.display();

    // Testing Copy Assignment Operator
    HashMap<string, int> assignedMap;
    assignedMap = map;
    cout << "\nAssigned map size: " << assignedMap.size() << " (Capacity: " << assignedMap.bucketCount() << ")" << endl;
    assignedMap.display();

    // Testing error handling
    cout << "\nError handling tests:" << endl;
    map.get("Zach");
    map.update("Zach", 100);
    map.remove("Zach");

    // Clear test
    map.clear();
    cout << "\nOriginal map after clear:" << endl;
    cout << "Size: " << map.size() << " (IsEmpty: " << map.isEmpty() << ")" << endl;
    map.display();

    return 0;
}
