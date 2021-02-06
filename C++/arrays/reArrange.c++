/* Given an array, can you re-arrange its elements in such a way that the negative elements appear at one side and positive elements
 * appear in the other? Solve this problem in C++ and see if your code runs correctly!
 *
 * Problem Statement
 *
 * Implement a function reArrange(int arr[], int size) which takes an array arr and its size as input and rearranges the elements
 * such that all the negative elements appear on the left and positive elements appear at the right.
 * Consider 0 as a positive number.
 *
 * Input: 
 *
 * An array of integers and its size
 *
 * Output: 
 *
 * A rearranged array with negative elements at the left and positive elements at the right
 *
 * Sample Input
 * [10, -1, 20, 4, 5, -9, -6]
 *
 * Sample Output
 * [-1, -9, -6, 10, 20, 4, 5]
 *
 * Take a close look and design a step-by-step algorithm first before jumping on implementation
 *
 */

#include<iostream>

using namespace std;

void swap (int& arg1, int& arg2) {
    int temp = arg1;
    arg1 = arg2;
    arg2 = temp;
    return;
}



//Re-Arrange Positive and Negative Values of Given Array
void reArrange(int arr[], int size) {
    //A swap function is prepended. Use it like swap(arg1, arg2)    
    // Write your code here
    
    int index = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            swap(arr[i], arr[index]);
            index++;
        }
    }

    return;
}
     
int main() {
    int size = 6;
    int arr[size] = {2, 3, -6, 0, -5, -10};
   
    cout << "Array before rearranging: ";
    for (int i = 0; i < size; i++) 
        cout << arr[i] << " ";
    cout << endl;

    reArrange(arr, size);

    cout << "Array after rearranging: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
