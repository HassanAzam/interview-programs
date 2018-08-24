#include <iostream>
#include <unordered_map>

using namespace std;

/*
An array with duplicate elements {1,2,2,3,4,5,5,5,6,7,7,8}
Find duplicates or ignore them

- Sort the array, and find duplicates 
- Use HashTable - O(1) for insertion/searching in a HashTable | we will use this 
- Can be done via BinaryTree

*/

// This function will return hashtable with element occurences stored as value
// and elements stored as key
// Then we can iterate it, to find unique, duplicate elements
unordered_map<int,int> ignore_duplicate(int arr[], int n) {
    //Using Hashtable implementation in C++11, unordered_map<type,type>
    unordered_map<int,int> map;
    for(int i=0; i<n; ++i) {
        // If this element arr[i] is not in hashtable, then add it else ignore
        if(map.find(arr[i]) == map.end()) {
            map.insert({arr[i],1});
        }
        else {
            map[arr[i]] += 1;
        }
    }
    return map;
}

int main() {
    int testarr[] = {8,5,6,6,3,2,1,1,4,5,3};
    int len = sizeof(testarr)/sizeof(*testarr);
    unordered_map<int,int> map = ignore_duplicate(testarr, len);

    //print frequency of elems
    cout << "\n Frequency of elements \n";
    for (auto& elem : map)
        cout << elem.first << " : " << elem.second << endl;

    //print unique elems
    cout << "\n Unique elements \n";
    for (auto& elem : map)
        if(elem.second == 1)
            cout << elem.first << endl;

    //print duplicate elems
    cout << "\n Duplicate elements \n";
    for (auto& elem : map)
        if(elem.second > 1)
            cout << elem.first << endl;
    //
}