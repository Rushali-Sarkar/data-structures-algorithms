#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int binarysearch(vector<int> arr, int value) {

    sort(arr.begin(), arr.end());
    int left = 0;
    int right = arr.size() - 1;
    int middle = (left + right) / 2;

    while (left <= right) {

        if (arr[middle] == value)
            return middle;

        if (value < arr[middle])
            right = middle - 1;

        if (value > arr[middle])
            left = middle + 1;

        middle = (right + left) / 2;
    }

    return  -1;
}

int main(int argc, char* argv[]) {

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << binarysearch(arr, 13) << endl;
    return 0;
}

    
