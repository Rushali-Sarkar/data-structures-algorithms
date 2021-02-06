/* Given an array and a number `value`, find two numbers from an array that sum to `value`. Implement your solution in C++ and see
 * if your output matches with the correct output.
 * Problem Statement
 *
 * Implement a function findSum(int arr[], int value, int size) which takes an array arr, a number value and size of the
 * array as input and returns an array of two numbers that add up to value. In case there is more than one pair in the array
 * containing numbers that add up to value, you are required to return only one such pair. If no such pair found then simply return
 * the array.
 *
 * Input
 *
 * An array, value, and size of the array
 *
 * Output
 *
 * An array with two integers that add up to value
 *
 * Sample Input
 *
 * [1, 21, 3, 14, 5, 60, 7, 6]
 *
 * 81
 *
 * Sample Output
 *
 * [21, 60]
 *
 * For example, in this illustration, we are given 81 as the number value and when we traverse the whole array we find
 * that 21 and 60 are the integers that add up to 81.
 *
 * Take a close look and design a step-by-step algorithm first before jumping on to the implementation.
 *
 */

#include<iostream>

using namespace std;

//Return 2 elements of arr that sum to the given value


int * findSum(int arr[], int value, int size) {
    // Sorting function is prepended as sort(arr, low, high)
    

    //Write your code here
    
    for ( int i = 0; i < size; i++) {
        int first_number = arr[i];
        for (int j = i + 1; j < size; j++) {
            int second_number = arr[j];
            if ((first_number + second_number) == value) {
                arr[0] =  first_number;
                arr[1] = second_number;
                return arr;
            }
        }
    }
    
    return arr;
}

int main() {

    int size = 5, value = 9;
    int arr[size] = {2, 4, 5, 7, 8};

    if (size > 0) {
        int * arr2 = findSum(arr, value, size);
        int num1 = arr2[0];
        int num2 = arr2[1];

        if ((num1 + num2) != value)
                cout << "Not Found" << endl;
        else {
        cout << "Number 1 = " << num1 << endl;
        cout << "Number 2 = " << num2 << endl;
        cout << "Sum = " << num1 + num2 << endl;
        }

   }

   else {
       cout << "Input Array is Empty!" << endl;
   }

}

 

 
