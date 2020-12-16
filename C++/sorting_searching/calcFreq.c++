/* Given a sorted array of integers, find the frequency of the occurrence of a given target value in the array.

If the value is not found in the array at all, return 0

Input 
A sorted array and a target value

Output 
The number of times that it occurs in the array

Sample Input 
9

-5
-3
0
1
3
3
3
4
5
3
Sample Output 
3
*/

#include <iostream>
using namespace std;

int calcFreq(int arr[], int arrSize, int s) {
  
  int frequency = 0;
  
  for (int i = 0; i < arrSize; i++) {
      
      if (arr[i] == s)
        frequency++;
        
      if (arr[i] > s)
        break;
  }
  
  return frequency;
}

int main(int argc, char* argv[]) {
    
    int size = 9;
    int arr[] = {-1, -3, 0, 1, 3, 3, 3, 4, 5};
    int s = 3;
   
    cout << calcFreq(arr, size, s) << endl;
    
            
}
