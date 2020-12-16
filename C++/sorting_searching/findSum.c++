/* Implement a function that takes an array arr, 
a number s, and the size of the array as an input, 
and returns two numbers which add up to s.

Input 
An array, value, and size of the array

Output 
An array with two integers that add up to s

Sample Input 
8
1
21
3
14
5
60
7
6
81
Sample Output 
21 60
For example, in this illustration, 
we are given 81 as the number s. When we traverse the whole array, 
we find that 21 and 60 are the integers that add up to 81.
*/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> findSum(int arr[], int arrSize, int s) {

  vector<int> elements;
  sort(arr, arr + arrSize);
  
  int left = 0;
  int right = arrSize - 1;
  
  while (left < right) {

      if ((arr[left] + arr[right]) == s) {
          elements.push_back(arr[left]);
          elements.push_back(arr[right]);
          return elements;
      } 
        
      else if ((arr[left] + arr[right]) > s) 
        right--;
    
     else
        left++;
  }
  
  return elements;
}


int main(int argc, char* argv[]) {
    
    int size = 8;
    int arr[] = {1, 21, 3, 14, 5, 60, 7, 6};
    int s = 81;
    
    vector<int> elements = findSum(arr, size, s);

    if (elements.size() == 0) { 
        cout << "-1" << endl;
        return 0;
    }

    cout << elements[0] << " " << elements[1] << endl;
    
    return 0;
}
