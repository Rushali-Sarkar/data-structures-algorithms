#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int binarysearch (vector<int> arr, int value, int left, int right) {

    if (left > right)
        return -1;
    
    int middle = (left + right) / 2;
    int potential_match = arr[middle];
        
    
    if (potential_match == value)
        return middle;

    else if (potential_match < value)
        return binarysearch(arr, value, middle + 1, right);

    else
        return binarysearch(arr, value, left, middle - 1);

    return -1;
}

int main(int argc, char* argv[]) {

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << binarysearch (arr, 10, 0, 9) << endl;
    cout << binarysearch (arr, 11, 0, 9) << endl; 
    cout << binarysearch (arr, 1, 0, 9) << endl; 
    cout << binarysearch (arr, 13, 0, 9) << endl; 
    cout << binarysearch (arr, 7, 0, 9) << endl; 
    return 0;
}
