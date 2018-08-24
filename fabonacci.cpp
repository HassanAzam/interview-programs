#include <iostream>

using namespace std;

/*

Fabonacci series
0 1 1 2 3 5 8 13 21 34 . . .

- Generate this series using loops
- Generate this series using recursion

*/


// Function to print first n numbers in fabonacci series
void fab_loop(int n) {
    int prev = 0, curr = 1, next;
    cout << "\n" << prev << " " << curr;

    // n-2; since we already printed two elems
    for(int i = 0; i < n-2; i++) {
        next = prev + curr;
        cout << " " << next;
        prev = curr;
        curr = next;
    }
}

// Function to return nth element in Fabonacci series using recursion
int fab_rec(int n) {
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return fab_rec(n-1)+fab_rec(n-2);
}

int main() {
    cout << "\n via Loops";
    fab_loop(10);
    cout << "\n via Recursion \n ";
    for(int i = 0; i < 10; i++) {
        cout << " " << fab_rec(i);
    }
}
