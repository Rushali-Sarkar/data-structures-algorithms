#include<iostream>
#include<vector>

using namespace std;


bool is_monotonic(vector<int> arr) {

    bool is_decreasing = false;
    bool is_increasing = false;

    for (int i = 0; i < arr.size() - 1; i++) {

        if (!is_decreasing && !is_increasing) {
            if (arr[i] < arr[i + 1])
                is_increasing = true;

            if (arr[i] > arr[i + 1])
                is_decreasing = true;

            continue;
        }

        else {

            if (is_increasing && arr[i] > arr[i + 1])
                return false;

            if (is_decreasing && arr[i] < arr[i + 1])
                return false;
        }
    }

    return true;
}

int main(int argc, char* argv[]) {

    vector<int> arr = {-1, -10, -1100, -1100, -1101, -1102, -9001};
    cout << is_monotonic(arr) << endl;
    return 0;
}
