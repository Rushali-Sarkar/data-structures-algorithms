/* Implement a function that tells whether a given target is present in the sorted matrix or not. The sorted matrix has all elements sorted both row wise and column wise.

Input 
A sorted matrix and the target that needs to be checked if it is present or not.

Output 


Return 1 if the target is found, or 0 if the target is not found.

Sample Input 


4 // number of rows
4 // number of columns
10 
11
12
13
14
15
16
17
27
29
30
31 
32
33
39
80

target = 30
Sample Output 
1
*/

#include <iostream>
#include <vector>

using namespace std;

bool is_present(vector<vector<int>> arr, int target) {
    
    int row = 0;
    int column = arr[0].size() - 1;
    
    while (row < arr.size() && column >= 0) {
        
        if (target < arr[row][column])
            column--;
            
        else if(target > arr[row][column])
            row++;
            
        else
            return true;
    }
    
    return false;
}

int main(int argc, char* argv[]) {
    
    int rows = 4;
    int columns = 4;
    vector<vector<int>> arr {
    	{10, 11, 12, 13},
    	{14, 15, 16, 17},
    	{27, 29, 30, 31},
    	{32, 33, 39, 80}};
   
    int target = 80;
    cout << is_present(arr, target) << endl;
    return 0;
}
