#include<iostream>
#include<vector>

using namespace std;

vector<int>  runningsum(vector<int> nums) {
    int size = nums.size();
    vector<int> result;

    for (int i = 0; i < size; i++) { 
        int sum = 0;
        for (int j = 0; j <= i; j++)             
            sum = sum + nums[j];
        result.push_back(sum);
    }

    return result;
