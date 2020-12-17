#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> trackNumbers;
        
        int i = 0;
        
        for (auto element: nums) {
            
            int possible_match = target - element;
            if (trackNumbers.find(possible_match) != trackNumbers.end())
                return vector<int> {trackNumbers[possible_match], i};
        
            trackNumbers[element] = i;
            i++;
        }
        
        return vector<int> {-1, -1};
        
    }

    int main(int argc, char* argv[]) {

        vector<int> nums {3, 2, 4};
        int target = 6;

        vector<int> result = twoSum(nums, target);
        cout << result[0] << '\t' << result[1] << endl;

        return 0;
    }
