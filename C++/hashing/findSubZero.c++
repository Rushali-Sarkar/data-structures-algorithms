/*Problem Statement 

You must implement the bool findSubZero(int* arr, int size) function, 
which will take in an array of positive and negative integers. 
It will tell us if there exists a subarray in which the sum of all elements is zero. 
The term subarray implies that the elements whose sum is 0 must occur consecutively.

An array with these contents would return true:

{6, 4, -7, 3, 12, 9}

Whereas this would return false as the elements which sum up to be 0 do not 
appear together:

{-7, 4, 6, 3, 12, 9}

Input 

An array containing positive and negative integers and its size.

Output 

Returns 1(true) if there exists a subarray with its sum equal to 0. 
Otherwise, the function returns 0(false.)

Sample Input 

Input = 6
6
4
-7
3
12
9 


Sample Output = 1
*/

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <iostream>
using namespace std;

bool findSubZero(int* arr, int size) {
    
    unordered_set<int> consecutiveSums;
    int sum = 0;
    
    for (int i = 0; i < size; i++) {
        sum = sum + arr[i];
        if (sum == 0 || consecutiveSums.find(sum) != consecutiveSums.end())
            return true;
        else
            consecutiveSums.insert(sum);
    }
    
    return false;
}

int main(int argc, char* argv[]) {
    
    int size = 6;
    int arr[] = {6, 4, -7, 3, 12, 9};
    cout << findSubZero(arr, size) << endl;
    return 0;
}
