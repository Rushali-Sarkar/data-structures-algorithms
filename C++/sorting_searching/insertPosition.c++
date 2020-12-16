/* Given a sorted array and a target value, return the index where the target value would be if it were inserted in order. If the target index is already present in the array, return the index of where it is found. You may assume that no duplicates are in the array.

Input 
A sorted array, its size, and a target value

Output 
The index at which the array should be inserted OR the index at which it is already present.

Sample Input 
4

1

3

5

6

5
Sample Output 
2
*/

#include <iostream>

using namespace std;

int insertPosition(int arr[], int arrSize, int s) {   
  
  int left = 0;
  while (left < arrSize) {
      
      if (arr[left] >= s)
        return left;
    
        left++;
  }
  
  return arrSize;
}

int main(int argc, char* argv[]) {
    
    int size = 4;
    int arr[] = {1, 3, 5, 6};
    int s = 5;
   
    cout << insertPosition(arr, size, s) << endl;
    return 0;
}