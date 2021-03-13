/* Given an array, find the first integer which is unique in the array. Unique means the number does not repeat and appears only
 * once in the whole array. Implement your solution in C++ and see if it runs correctly!
 *
 * Problem Statement
 *
 * Implement a function, findFirstUnique(int arr[], int size) which takes an array and its size as input and returns the first
 * unique integer in the array. The function returns -1 if no unique number is found.
 *
 * Input
 *
 * An array of integers and its size
 *
 * Output
 *
 * The first unique element in the array
 *
 * Sample Input
 *
 * [2, 3, 9, 2, 3, 6]
 *
 * Sample Output
 *
 * 9
 *
 * Take a close look and design a step-by-step algorithm before jumping on to the implementation.
 */

 #include<iostream>

using namespace std;

int findFirstUnique(int arr[], int size) {
    //Write your code here
    
    for (int i = 0; i < size; i++) {
        bool first_unique = true;
        for (int j = i + 1; j < size; j++) {
           if (arr[i] == arr[j]) {
              first_unique = false; 
              break;
           }
        }

        if (first_unique)
            return arr[i];
    }

    return -1;
}

int main() {
    int size = 6;
    int arr[size] = {2, 54, 7, 2, 6, 54};

    cout << "Array : ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    int unique = findFirstUnique(arr, size);
    cout << "First Unique in an Array: " << unique << endl;
    return 0;
}

