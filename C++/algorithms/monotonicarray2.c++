#include<iostream>
#include<vector>

using namespace std;

bool is_monotonic(vector<int> arr) {

    bool is_decreasing = true;
    bool is_increasing = true;

    for (int i = 0; i < arr.size() - 1; i++) {

        if (arr[i] > arr[i + 1])
            is_increasing = false;

        if (arr[i] < arr[i + 1])
            is_decreasing = false;
    }

    return (is_decreasing || is_increasing);
}

int main(int argc, char* argv[]) {

    vector<int> arr = {1, 1, 1, 2, 3, 4, 3, 4, 5};
    vector<int> arr2 = {-1, -5, -10, -1100, -1100, -1101, -1102, -9001};
    vector<int> arr3 = {1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << is_monotonic(arr) << endl << is_monotonic(arr2) << endl << is_monotonic(arr3) << endl;
    return 0;
}


