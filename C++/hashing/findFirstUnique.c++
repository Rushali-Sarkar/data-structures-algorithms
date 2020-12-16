/* Problem Statement 

Implement a function, findFirstUnique(int arr[], int size), 
which takes an array and its size as input and returns the first unique integer 
in the array. The function returns -1 if no unique number is found.

Input 

An array of integers and its size

Output 

The first unique element in the array

Sample Input 
6
2
3
9
2
3
6

Sample Output 

9
*/


#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std; 
  
int findFirstUnique(int arr[], int size) { 

   vector<bool> is_unique(size, true);
   unordered_map<int, vector<int>> numbersToIndices;
   
   for (int i = 0; i < size; i++) {
       
       if (numbersToIndices.find(arr[i]) != numbersToIndices.end()) {
           int false_index = numbersToIndices[arr[i]].back();
           numbersToIndices[arr[i]].push_back(i);
           is_unique[false_index] = false;
           is_unique[i] = false;
       }
       
       else 
            numbersToIndices[arr[i]] = {i};
   }
   
   for (int i = 0; i < size; i++) {
       if (is_unique[i])
            return arr[i];
   }
   
   return -1;
} 

int main(int argc, char* argv[]) {
    
    int size = 6;
    int arr[] = {2, 3, 9, 2, 3, 6};
    cout << findFirstUnique(arr, size) << endl;
    return 0;
}
