/* Arrange elements in such a way that the maximum element appears at the first, then the minimum at the second, then the second maximum at the third position, and second minimum at the fourth and so on.
 *
 * Problem Statement
 *
 * Implement a function maxMin(int arr[], int size) which takes a sorted array arr and its size and will re-arange the elements
 * of a sorted array such that the first position will have the largest number, the second will have the smallest, and the third
 * will have the second-largest and so on. In other words, all the even-numbered indices will have the largest nunbers in the array
 * in The given array is sorted in ascending order.
 *
 * Input
 *
 * A sorted array and its size
 *
 * Output
 *
 * A list with elements in max/min form
 *
 * Sample Input
 *
 * [1, 2, 3, 4, 5]
 *
 * Sample Output
 *
 * [5, 1, 4, 2, 3]
 *
 */

#include<iostream>

using namespace std;

void maxMin(int arr[], int size) {
    //Write your code here
    
    int* copy = new int[size];

    for (int i = 0, j = size - 1; i < size; i++, j--) {
        copy[i] = arr[i];
    }
    
    int ascendingindex = 0;
    int descendingindex = size - 1;

    for (int i = 0; i < size; i++) {

        if (i % 2 == 0) 
            arr[i] = copy[ascendingindex++];

        else 
            arr[i] = copy[descendingindex--];
    }

     return;
}

int main() {
    int size = 6;
    int arr[size] = {1, 2, 3, 4, 5, 6};
    cout << "Array before min/max: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    maxMin(arr, size);

    cout << "Array after min/max: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
