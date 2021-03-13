/* Given two sorted arrays, merge then into one array which should also be sorted. 
 * Implement the solution in c++ and see if your code runs successfully
 *
 * Problem Statement
 *
 * Implement a function mergeArrays(int arr1[], int arr2[], int arr1Size, int arr2Size) which merges two sorted arrys
 * into another sorted array. The definition of the function is given.
 *
 * Input: 
 * Two sorted array and their sizes.
 *
 * Output: 
 * A merged sorted array consisting of all elements of both input arrays.
 *
 * Sample Input
 *
 * [1, 3, 4, 5]
 * [2, 6, 7, 8]
 *
 * Sample Output
 *
 * [1, 2, 3, 4, 5, 6, 7, 8]
 *
 * Take a close look and design a step-by-step algorithm first before jumping on implementation.
 *
 */

#include<iostream>

using namespace std;

int* mergeArrays(int arr1[], int arr2[], int arr1Size, int arr2Size) {
    
    int * arr3 = new int[arr1Size + arr2Size];
    //Write your code here
    int index = 0;
    int* i = &arr1[0];
    int* j = &arr2[0];

    while (i <= &arr1[arr1Size - 1] && j <= &arr2[arr2Size - 1]) {

        if (*i <= *j) {
            arr3[index++] = *i;
            i++;
        }

        else {
            arr3[index++] = *j;
            j++;
        }
    }

    if (i > &arr1[arr1Size - 1]) {
        while (j <= &arr2[arr2Size - 1]) {
            arr3[index++] = *j;
            j++;
        }
    }

    else {
        while (i <= &arr1[arr1Size - 1]) {
            arr3[index++] = *i;
            i++;
        }
    }

    return arr3;
}

int main() {

    int size1 = 5, size2 = 3;
    int arr[size1] = {1, 12, 14, 17, 23}; //creating array1
    int arr1[size2] = {11, 19, 27}; //creating array2
    int* arr2 = mergeArrays(arr, arr1, size1, size2); //calling mergeArrays
    for (int i = 0; i < size1 + size2; i++) {
       cout << arr2[i] << " ";
    }
   cout << endl;
   delete arr2; //deleting pointers
   return 0;

}

 
