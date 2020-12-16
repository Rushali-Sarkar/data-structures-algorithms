/* Given an array, find all the duplicates that exist in that array.

Input 
An array and its size

Output 
A vector with the duplicates if they exist, and an empty vector if they don’t.

Sample Input 
8

1
3
4
3
5
4
100
100
Sample Output 
100, 4, 3
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

vector <int> findDuplicates(int arr[], int arrSize) {
  vector <int> duplicates = {-1}; // Placeholder value
  unordered_set<int> help_find_duplicates;
  unordered_set<int> store_duplicates;
  
  for (int i = 0; i < arrSize; i++) {
      
      if (help_find_duplicates.find(arr[i]) != help_find_duplicates.end() &&
            store_duplicates.find(arr[i]) == store_duplicates.end()) {
                
                store_duplicates.insert(arr[i]);
                duplicates.push_back(arr[i]);
            }
            
    else
        help_find_duplicates.insert(arr[i]);
  }
  
  return duplicates;
}


int main(int argc, char* argv[]) {
    
    int size = 8;
    int arr[] = {1, 3, 4, 3, 5, 4, 100, 100};
  
    vector<int> elements = findDuplicates(arr, size);
    string result = "";
    
    while (elements.back() != -1) {
        result = result + to_string(elements.back()) + ", ";
        elements.pop_back();
    }
    
    cout << result.substr(0, result.length() - 2) << endl;
    return 0;
    
}
