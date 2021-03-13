/* Given an array, can you rotate its elements by one index from right to left? Implement your solution in C++ and see if your code
 * runs successfully!
 *
 * Problem Statement
 *
 * Implement a function rightRotate(int arr[], int size) which takes an array arr and rotate it right by 1. This means that the
 * right-most elements will appear at the left-most position in the array.
 *
 * Input
 *
 * An array of integers and its size
 *
 * Output
 *
 * The given array rotated by 1
 *
 * Sample Input
 *
 * [1, 2, 3, 4, 5]
 *
 * Sample Output
 *
 * [5, 1, 2, 3, 4]
 *
 * Take a close look and design a step-by-step algorithm first before jumping to the implementation.
 *
 */

#include<iostream>

using namespace std;

void rightRotate(int arr[], int size) {
    //Write your code here
    
    int lastElement  = arr[size - 1];
    for (int i = size - 1; i >  0; i--) {
        arr[i] = arr[i - 1];
    }

    arr[0] = lastElement;
    return;
}

int main() {
    int size = 6;
    int arr[size] = {3, 6, 1, 8, 4, 2};
    cout << "Array before rotation: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    rightRotate(arr, size);

    cout << "Array after rotation: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
