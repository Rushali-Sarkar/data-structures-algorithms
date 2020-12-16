/* Problem Statement
 *
 * Implement the is Subset(int* arr1, int* arr2, int size1, int size2) function, which will take two arrays and
 * their sizes as input and check whether one array is the subset of the other.
 *
 * Note: The input arrays do not contain duplicate values.
 *
 * Input
 *
 * Two arrays of integers and their sizes.
 *
 * Output
 *
 * true if arr2 is a subset of arr1.
 *
 * Sample Input
 *
 * 7
 * 9
 * 4
 * 7
 * 1
 * -2
 *  6
 *  5
 *  3
 *  7
 *  1
 *  -2
 *
 *  Sample Output
 *
 *  1
 *
 */

#include<unordered_set>
#include<iostream>

using namespace std;

bool isSubset(int* arr1, int* arr2, int size1, int size2) {

    unordered_set<int> powerset;
    
    for (int i = 0; i < size1; i++) 
        powerset.insert(arr1[i]);

    for (int i = 0; i < size2; i++) {

        if (powerset.find(arr2[i]) == powerset.end())
            return false;
    }

    return true;
}

int main(int argc, char* argv[]) {

    int arr1[] = {9, 4, 7, 1, -2, 6, 5};
    int arr2[] = {7, 1, -2};

    cout << isSubset(arr1, arr2, 7, 3) << endl;
    return 0;
}

