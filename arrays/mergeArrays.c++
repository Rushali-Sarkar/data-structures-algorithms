#include<iostream>

using namespace std;

int * mergeArrays(int arr1[], int arr2[], int arr1Size,int arr2Size) {
    int* arr3 = new int[arr1Size + arr2Size];
    int index = 0;
    for (int i = 0; i < arr1Size; i++) {
        arr3[index] = arr1[i];
        index++;
    }
                    
    for (int i = 0; i < arr2Size; i++) {
        arr3[index] = arr2[i];
        index++;
    }
                        
    for (int i = 0; i < arr1Size + arr2Size; i++) {
        for (int j = i; j < arr1Size + arr2Size; j++) {
            if (arr3[j] < arr3[i]) {
                int temporary = arr3[i];
                arr3[i] = arr3[j];
                arr3[j]= temporary;
             }
         }
     }
     return arr3;
}

int main() {
    int size1 = 5, size2 = 3;
    int arr[size1] = {1,12,14,17,23}; // creating array 1
    int arr1[size2] = {11,19,27};  // creating array 2
    int * arr2 = mergeArrays(arr, arr1, size1, size2); // calling mergeArrays
    for(int i=0; i< size1+size2 ; i++) {
         cout << arr2[i] << " ";
    }
    delete arr2;  // deleting pointer
    return 0;
}
