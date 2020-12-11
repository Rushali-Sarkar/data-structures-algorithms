/* Given an array, return an array where each index stores the produxt of all numbers in the array except the number at the index
 * itself.
 *
 * Problem Statement
 *
 * Implement a function, findProduct(int arr[], int size) which takes an array arr and its size as an input and returns an array
 * so that each index has a product of all the numbers present in the array except the number stored at that index.
 * size should be equal to or greater than 2.
 *
 * Input: 
 *
 * An array of integers and its size
 *
 * Output: 
 * 
 * An array such that each index has a product of all the numbers in the array except the number stored at that index.
 *
 * Sample Input
 * [1, 2, 3, 4]
 *
 * Sample Output
 * [24, 12, 8, 6]
 *
 * Take a close look and design a step-by-step algorithm first before jumping on to the implementation.
 *
 */

#include<iostream>

using namespace std;

int * findProduct(int arr[], int size) {

    int * product = new int[size];
    // Write your code here
    int * postfixproduct = new int[size];
    int * prefixproduct = new int[size];

    postfixproduct[size - 1] =  1;
    prefixproduct[0] = 1;

    int post = 1, pre = 1;

    for (int i = 1, j = size - 2; i < size, j >= 0; i++, j--) {

        pre = pre * arr[i - 1];
        post = post * arr[j + 1];

        prefixproduct[i] = pre;
        postfixproduct[j] = post;

    }

    for (int i = 0; i < size; i++) {
        product[i] = prefixproduct[i] * postfixproduct[i];
    }


    return product;
}

int main() {
    int size = 4;
    int arr[size] = {1, 3, 4, 5};

    cout << "Array before product: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int * prodArray = findProduct(arr, size);

    cout << "Array after product: ";
    for (int i = 0; i < size; i++) {
        cout << prodArray[i] << " ";
    }
    cout << endl;
    delete [] prodArray;
    return 0;
}
