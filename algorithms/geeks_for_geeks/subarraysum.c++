#include<iostream>
#include<vector>

using namespace std;

int subarray(vector<int> arr, int target) {

    int min_length = arr.size() + 1;
    int l = 0;
    int current_sum = 0;

    int start = 0;
    int end = 0;

    while (end < arr.size()) {

        if (current_sum <= target) {
            current_sum = current_sum + arr[end++];
            l++;
        }

        else {

            if (min_length > l)
                min_length = l;

            current_sum = current_sum - arr[start++];
            l--;
        }
    }

    if (min_length == arr.size() + 1)
        return -1;

    return min_length;
}

int main(int argc, char* argv[]) {

    int size;
    vector<int> arr;
    cin >> size;

    for (int i = 0; i < size; i++) {
        int element;
        cin >> element;
        arr.push_back(element);
    }

    int target;
    cin >> target;

    cout << subarray(arr, target) << endl;
    return 0;
}



