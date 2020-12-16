/* Implement a function that returns the index of the target string in a sorted, sparsed array of strings.



Input 

A sparsed, sorted array of strings and the target string whose location needs to be found.



Output 



Index (location) of the target string.



Sample Input 



12

""

"educative"

""

""

""

"hello"

""

"learning"

"world"

""

""

""

"educative"



Sample Output 



1
*/

#include<iostream>
#include<string>

using namespace std;

int searchForString(string array[], int size, string target) {
  
  int left = 0;
  int right = size - 1;
  
  while (left < right) {
      
      
      if (array[left] == target)
        return left;
        
      if (array[right] == target)
        return right;
        
      if (array[left] == "" || target > array[left])
        left++;
        
      if (array[right] == "" || target < array[right])
        right--;
        
        
  }
  return -1;
}

int main(int argc, char* argv[]) {
    
    int size = 12;
    string array[] = {"", "educative", "", "", "", "hello", "", "learning", 
    "world", "", "", ""};
    string target = "educative";
    
    cout << searchForString (array, size, target) << endl;
    return 0;
}
