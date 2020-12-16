/* Problem Statement 

You have to implement the bool isDisjoint(int* arr1, int* arr2, int size1, int size2) 
function, which checks whether two given arrays are disjoint or not.

Two arrays are disjoint if there are no common elements between them. 
The assumption is that there are no duplicate elements in each array.

Input 

Two arrays of integers and their lengths.

Output 

It returns true if the two arrays are disjoint. Otherwise, it returns false.

Sample Input 
7
9
4
3
1
-2
6
5
3
7
10
8

Sample Output 

1*/

#include <unordered_set>
#include <iostream>
using namespace std;

bool isDisjoint(int* arr1, int* arr2, int size1, int size2) {
    
    unordered_set<int> set1;
    for (int i = 0; i < size1; i++)
        set1.insert(arr1[i]);
    
    for (int i = 0; i < size2; i++) {
        
        if (set1.find(arr2[i]) != set1.end())
            return false;
    }
    
    return true;
}


int main(int argc, char* argv[]) {
    
    int arr1[] = {9, 4, 3, 1, -2, 6, 5};
    int size1 = 7;

    int arr2[] = {7, 10, 8};
    int size2 = 3;

        
    cout << isDisjoint(arr1, arr2, size1, size2) << endl;
    return 0;
    
}
