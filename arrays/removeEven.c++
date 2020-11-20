/* Given an array, remove  all even integers from it. Implement this solution in c++ and see if it runs without an error.
 * Implement a function removeEven( int *& Arr, int size) which takes an array arr and its size and removes all the even elements
 * from a given array.
 * Input
 * An array with integers and size.
 * Note: The array passed to the funtions have been created dynamically.
 * Output
 * An array with only odd integers
 * Sample Input
 * [1, 2, 4, 5, 10, 6, 3]
 * Sample Output
 * [1, 5, 3]
 * Take a close look and design a step-by-step algorithm first before jumping onto the implementation */

#include<iostream>

using namespace std;

int * removeEven( int *& Arr, int size) {
    // Write your code here
    int oddCount = 0;
    for (int i = 0; i < size; i++) {
        if (Arr[i] % 2 == 1) 
            oddCount++;
    }

    int* temp = new int[oddCount];
    int j = 0;

    for (int i = 0; i < size; i++) {
        if (Arr[i] % 2 == 1) {
           temp[j] = Arr[i];
           j++;
        }
    }

   delete [] Arr;
   Arr = temp;
   return Arr;
}

int main() {
    int * arr;      // declaring array
    arr = new int[10];   // memory allocation
    cout << "Before remove even: "; 
    for ( int i = 0; i < 10; i++ ) {
        arr[i] = i;      // assigning values
        cout << arr[i] << " ";
    }
    cout << endl;
    arr = removeEven(arr,10);   // calling removeEven
    cout << "After remove even: ";
    for ( int i = 0; i < 5; i++ ) {
        cout << arr[i] << " ";    // prinitng array
    }
    cout << endl;
    delete [] arr;  // deleting allocated memory
    return 0;
}

