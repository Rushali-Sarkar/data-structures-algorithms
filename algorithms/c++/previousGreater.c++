#include<iostream>
#include<vector>
#include"stack.h"

using namespace std;

vector<int> previousGreater(vector<int> nums) {

    int size = nums.size();

    vector<int> result;
    Stack tracking(size);

    result.push_back(-1);
    tracking.push(nums[0]);

    for (int i = 1; i < size; i++) {
        
        while (!tracking.isEmpty()) {
            if (nums[i] < tracking.front()) {
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
    vector<int> result1 = previousGreater(arr1);
    show(result1);

    vector<int> arr2 = {8, 7, 3, 9, 7, 4, 6, 8, 2};
    vector<int> result2 = previousGreater(arr2);
    show(result2);

    return 0;
}
