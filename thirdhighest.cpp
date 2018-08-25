#include <iostream>

using namespace std;

/*
Write a program to find third highest from an array

- Sort array, and find [lenofarr-2] element (sort algo took nlogn in worst case)
- Iterate array and store three highest numbers in three variable ( linear O(n) but hard coded
   for 3rd highest.)

*/
int find3rdhighest(int arr[], int len) {
    int first = 0, second = 0, third = 0;
    for(int i=0; i<len; ++i) {
        if(arr[i] > first) {
            third = second;
            second = first;
            first = arr[i];
        }        
        else if(arr[i] > second && arr[i] < first) {
            third = second;
            second = arr[i];
        }
        else if(arr[i] > third && arr[i] < second) {
            third = arr[i];
        }
    }
    return third;
}
int main() {
    int arr[] = {12,15,40,32,40,25,40,1,2,3};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout << "Third highest number : " << find3rdhighest(arr, len);
}