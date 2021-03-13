// [1, 2, 3, 4, 5]
// [1, 3, 6, 10, 15]

#include<iostream>
#include<vector>

using namespace std;

vector<int> runningsum(vector<int> nums) {

    for (int i = 1; i < nums.size(); i++) 
        nums[i] = nums[i - 1] + nums[i];
    return nums;
}

