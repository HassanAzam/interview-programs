#include <iostream>
#include <unordered_map>

using namespace std;

/*
Find unique element in an array

- Sort the array, and find unique elem 
- Use HashTable 
- Use XOR if you are sure that only one element is unique

*/

// This function will return hashtable with element occurences stored as value
// and elements stored as key
// Then we can iterate it, to find unique, duplicate elements
unordered_map<int,int> find_unique(int arr[], int n) {
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
    int testarr[] = {1,1,2,9,8,9,5,2,8};
    int len = sizeof(testarr)/sizeof(*testarr);
    // Big O Notation : O(n) and O(n) extra space is required.
    unordered_map<int,int> map = find_unique(testarr, len);

    //print frequency of elems
    cout << "\n Frequency of elements \n";
    for (auto& elem : map)
        cout << elem.first << " : " << elem.second << endl;

    //print unique elems
    cout << "\n Unique elements \n";
    for (auto& elem : map)
        if(elem.second == 1)
            cout << elem.first << endl;

    // XOR Logic
    // Big O Notation : O(n) and no extra space is required.
    int result = testarr[0];
    for(int j = 1; j < len; ++j) {
        result = result ^ testarr[j];
    }
    cout << "Unique Element is  : " << result;
}