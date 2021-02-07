#include<bits/stdc++.h>

using namespace std;

int sum(vector<int> nums) {
        int result = 0;
        for (auto each: nums)
            result = result + each;
        
        return result;
    }  
    
    
    int minAbsDifference(vector<int>& nums, int goal) {
        
        
        int min = abs(goal);
        
        int powersets = pow(2, nums.size());
        
        for (int i = 1; i < powersets; i++) {
            
            vector<int> arr;  
            for (int j = 0; j < nums.size(); j++) {
                if (i & (1 << j)) {
                    cout << nums[j] << " ";
                    arr.push_back(nums[j]);
                }
            }

            cout << endl;
            
            
            int add = sum(arr);
            if (abs(add - goal) < min)
                min = abs(add - goal);
            
        }
        
        return min;
        
    }


int main(int argc, char* argv[]) {

    vector<int> nums = {7, -9, 15, -2};
    minAbsDifference(nums, -5);
    return 0; 


}