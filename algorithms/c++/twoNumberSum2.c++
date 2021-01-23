#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> twonumbersum(vector<int> arr, int sum) {

    sort(arr.begin(), arr.end());
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {

        int expected_sum = arr[left] + arr[right];

        if (expected_sum == sum) 
            return vector<int> {arr[left], arr[right]};

        if (expected_sum > sum)
            right--;

        if (expected_sum < sum)
            left++;

    }

    return vector<int> {-1, -1};
}

int main(int argc, char* argv[]) {

    vector<int> arr{-4, -1, 1, 3, 5, 6, 8, 11};
    int sum = 10;

    vector<int> result = twonumbersum(arr, sum);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
