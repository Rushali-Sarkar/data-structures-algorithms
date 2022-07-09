#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> maximumCrossSubarray(vector<int>& arr, int low, int mid, int high) {

  int max_left = INT_MIN;
  int sum = 0;
  int left_index = -1;
  for (int i = mid; i >= low; --i) {
    sum += arr[i];
    if (sum > max_left) {
      max_left = sum;
      left_index = i;
    }
  }

  int max_right = INT_MIN;
  sum = 0;
  int right_index = -1;
  for (int i = mid + 1; i <= high; ++i) {
    sum += arr[i];
    if (sum > max_right) {
      max_right = sum;
      right_index = i;
    }
  }

  return vector<int> {right_index, left_index, max_left + max_right};

}


vector<int> maximumSubarray(vector<int>& arr, int low, int high) {

  if (low == high)
    return vector<int> {high, low, arr[low]};

  int mid = (int) ((high + low) / 2);
  vector<int> left = maximumSubarray(arr, low, mid);
  vector<int> right = maximumSubarray(arr, mid + 1, high);
  vector<int> cross = maximumCrossSubarray(arr, low, mid, high);

  if (cross[2] >= left[2] && cross[2] >= right[2])
    return cross;
  if (right[2] >= left[2])
    return right;
  return left;
}


int main(int argc, char* argv[]) {

  vector<int> arr = {-3, -4, -7, 0, 1, 2, 3, -1, 4, 5, 6, -10, -11, 0, -1, 2, -3};
  vector<int> result = maximumSubarray(arr, 0, arr.size() - 1);
  cout << result[1] << ", " << result[0] << ", " << result[2] << endl;

  return 0;
}


