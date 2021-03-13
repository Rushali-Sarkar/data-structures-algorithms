#include<iostream>
#include<vector>
#include"stack.h"

using namespace std;

vector<int> previousSmaller(vector<int> nums) {

    int size = nums.size();

    vector<int> result;
    Stack tracking(size);

    result.push_back(-1);
    tracking.push(nums[0]);

    for (int i = 1; i < size; i++) {

        while (!tracking.isEmpty()) {

            if (nums[i] > tracking.front()) {
                result.push_back(tracking.front());
                tracking.push(nums[i]);
                break;
            }

            tracking.pop();
            if (tracking.isEmpty()) {
                result.push_back(-1);
                tracking.push(nums[i]);
                break;
            }
        }
    }

    return result;
}

void show(vector<int> nums) {

    for (auto each: nums) 
        cout << each << " ";
    cout << endl;
    return;
}

int main(int argc, char* argv[]) {

    vector<int> arr1 = {8, 7, 3, 6, 7, 4};
    vector<int> result1 = previousSmaller(arr1);

    show(result1);
    return 0;
}
