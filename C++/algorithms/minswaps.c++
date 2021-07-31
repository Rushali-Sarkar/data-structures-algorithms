#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int getWindowSize(vector<int> arr) {

    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 1)
            count++;
    }
    return count;
}

int minswaps(vector<int> arr) {
    int window_size = getWindowSize(arr);
    int minimum_swaps = INT_MAX;
    for (int i = 0; i < arr.size(); i++) {
        int limit = i + window_size;
        if (limit <= arr.size()) {
            int swaps = 0;
            for (int j = i; j < limit; j++) {
                if (arr[j] == 0)
                    swaps++;
            }
            if (swaps < minimum_swaps)
                minimum_swaps = swaps;
        }
        else 
            return minimum_swaps;
    }
    return minimum_swaps;
}

int main(int argc, char* argv[]) {

    vector<int> arr1 = {1, 0, 1, 0, 1};
    vector<int> arr2 = {0, 0, 0, 1, 0};
    vector<int> arr3 = {1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1};

    cout << minswaps(arr1) << endl;
    cout << minswaps(arr2) << endl;
    cout << minswaps(arr3) << endl;

    return 0;
}

    
