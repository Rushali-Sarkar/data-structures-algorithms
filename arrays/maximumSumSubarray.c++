/* Kaden's Algorithm
 *
 * Maximum Sum Subarray
 *
 * Given an integer array and its size return the maximum subarray sum. The array may contain both positive and negative integers
 * and is unsorted.
 *
 */

#include<iostream>

using namespace std;

int maximumSumSubarray (int arr[], int size) {

    int maxSoFar = arr[0];
    int maxEndingHere = 0;
   
    for (int i = 0; i < size; i++) {
       
        maxEndingHere = maxEndingHere + arr[i];

        if (maxEndingHere > maxSoFar)
            maxSoFar = maxEndingHere;

        if (arr[i] > maxEndingHere)
            maxEndingHere = arr[i];

   }

    return maxSoFar;
}

       
int main() {

    int size = 16;
    int arr [] = {3, 5, -9, 1, 3, -2, 3, 4, 7, 2, -9, 6, 3, 1, -5, 4};

    cout << "The array is : ";

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int maximumSum = maximumSumSubarray(arr, size);
    cout << "Maximum subarray sum is : " << maximumSum << endl; 
    return 0;
}

