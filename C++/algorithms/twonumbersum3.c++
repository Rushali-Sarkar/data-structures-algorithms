#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> twonumbersum(vector<int> arr, int target_sum) {

    sort(arr.begin(), arr.end());
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {

        int possible_sum = arr[left] + arr[right];

        if (possible_sum == target_sum)
            return vector<int> {arr[left], arr[right]};

        else if (possible_sum < target_sum)
            left++;

        else if (possible_sum > target_sum)
            right--;
    }

    return vector<int> {-1, -1};
}

int main(int argc, char* argv[]) {

    vector<int> arr = {3, 5, -4, 8, 11, 8, 1, -1, 6};
    int target_sum = 10;
    vector<int> result = twonumbersum(arr, target_sum);
    cout << "[ " << result[0] << " , " << result[1] << " ]" << endl;
    return 0;
}

/* The time complexity of this algorithm is O(nlogn) which is the time complexity of the sorting.
 * Time complexity of the while loop is O(n) which is less than O(nlogn) hence we take the complexity to be the time taken by 
 * the sorting technique.
 * The space complexity however is O(1) because we are not using any drastic space to calculate.
 */
