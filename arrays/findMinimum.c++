/* Given an array, can you d find the minumum value in an array ? Implement your solution in C++ and see if your output matches the
 * expected output.
 *
 * Problem Statement
 *
 * Implement a function findMinimum(int arr[], int size) which takes an array arr and its size and returns the smallest number
 * in the given array.
 *
 * Input: 
 * An array of integets
 *
 * Output: 
 * The smallest number in the array
 *
 * Sample Input
 *
 * [9, 2, 3, 6]
 *
 * Sample Output
 *
 * 2
 * 
 * Take a close look and design a step-by-step algorithm first before jumping on to the implementation.
 */

#include<iostream>

using namespace std;

//Returns minimum value from given Array

int findMinimum(int arr[], int size) {
    int minimum = arr[0];
    //Write your code here
    for (int i = 1; i < size; i++) {
        if (arr[i] < minimum) 
            minimum = arr[i];
    }
    return minimum;
}

int main() {
    int size = 4;
    int arr[size] = {9, 2, 3, 6};

    cout << "Array : ";
    for (int i = 0; i < size; i++) 
        cout << arr[i] << " ";
    cout << endl;

    int min = findMinimum(arr, size);
    cout << "Minimum in the Array: " << min << endl;
    return 0;
}
