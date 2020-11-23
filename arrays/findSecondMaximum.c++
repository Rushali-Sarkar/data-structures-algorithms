/* Given an array, can you find the second maximum element in the array ? Implement your solution in C++ and see if your output
 * matches the correct output!
 *
 * Problem Statement
 *
 * Implement a function findSecondMaximum(int arr[], int size) which takes an array arr and its size as input and returns the
 * second maximum element in the array. If no such element found then return secondmax varible.
 *
 * Assumption: Array should contain at least two unique elements.
 *
 * Input
 *
 * An array of integers and its size
 *
 * Output
 *
 * Second maximum element in the array
 *
 * Sample Input
 *
 * [9, 2, 3, 6]
 *
 * Sample Output
 *
 * 6
 *
 * Take a close look and design a step-by-step algorithm first before jumping on to the implementation.
 *
 */

#include<bits/stdc++.h>

using namespace std;

int findSecondMaximum(int arr[], int size) {
    int secondmax = INT_MIN;
    int maximum = INT_MIN;
    //Write your code here
    for (int i = 0; i < size; i++) {
        if (arr[i] > maximum)
            maximum = arr[i];
        if (arr[i] > secondmax && arr[i] < maximum)
            secondmax = arr[i];
    }

    return secondmax;
}

int main() {
    int size = 5;
    int arr[size] = {-2, -33, -10, -33, -456};
    
    cout << "Array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    int secMax = findSecondMaximum(arr, size);
    cout << "Second maximum: " << secMax << endl;
    return 0;
}
