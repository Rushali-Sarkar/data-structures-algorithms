/* Given a sorted array of n integers that have been right rotated an unknown 
number of times, write code to find an element in the array. 
You may assume that the array was originally sorted in ascending order.

Input 
A sorted array that has been rotated a number of times

Output 
The index of the element

Sample Input 
7
7
8
9
0
3
5
6
0 // Index of the start of the array
6 // Index of the end of the array
3 // Element that is being searched for
Sample Output 
4 // Index of the element that was searched for

*/

#include <iostream>

using namespace std;

int searchRotatedArray(int arr[], int left, int right, int s) {
  
  int middle = (left + right) / 2;
  
  while (left < right) {
      
      if (arr[left] < arr[middle]) {
          
          if (s > arr[left] && s < arr[middle])
                right = middle - 1;
            
          else if (arr[left] == s)
                return left;
        
          else if (arr[middle] == s)
                return middle;
                
          else 
                left = middle + 1;
          
      }
      
      else {
          
          if (s > arr[middle] && s < arr[right])
                left = middle + 1;
            
          else if (arr[right] == s)
                return right;
        
          else if (arr[middle] == s)
                return middle;
                
          else 
                right = middle - 1;
          
          
      }
      
      middle = (left + right) / 2;
  }
  
  return -2;
}

int main(int argc, char* argv[]) {
    
    int size = 7;
    int arr[] = {7, 8, 9, 0, 3, 5, 6};
    int left = 0;
    int right = 6;
    int s = 3;
        
    cout << searchRotatedArray(arr, left, right, s) << endl;
    return 0;
}
