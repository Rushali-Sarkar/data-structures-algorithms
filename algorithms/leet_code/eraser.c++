#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void show(vector<int> arr) {

    for (auto each: arr) 
        cout << each << " ";
    cout << endl;
    return; 
}

vector<int> prefixSum(vector<int> arr) {

    int previous_sum = 0;

    for (int i = 0; i < arr.size(); i++) {
        previous_sum = previous_sum + arr[i];
        arr[i] = previous_sum;
    }

    return arr;
}

 int maximumUniqueSubarray(vector<int>& nums) {

    unordered_map<int, int> lookup_table;
    vector<int> prefix_sum = prefixSum(nums);
    int size = nums.size();
    int maximumsum = 0;
    int currentsum = 0;
    int start_index = 0;
    show(prefix_sum);

    for (int i = 0; i < size; i++) {

        if (lookup_table.find(nums[i]) == lookup_table.end())
            currentsum = currentsum + nums[i];

        else if (lookup_table[nums[i]] >= start_index) {     
                start_index = lookup_table[nums[i]] + 1;
                currentsum = prefix_sum[i] - prefix_sum[lookup_table[nums[i]]];
        }
        else
           currentsum = currentsum + nums[i];

        lookup_table[nums[i]] = i;
        maximumsum = max(currentsum, maximumsum);
    }

    return maximumsum;  
}

int main(int argc, char* argv[]) {

    vector<int> nums1 = {4, 2, 4, 5, 6};
    show(nums1);
    cout << maximumUniqueSubarray(nums1) << endl;

    vector<int> nums2 = {5, 2, 1, 2, 5, 2, 1, 2, 5};
    show(nums2);
    cout << maximumUniqueSubarray(nums2) << endl;

    vector<int> nums3 = {187,470,25,436,538,809,441,167,477,110,275,133,666,345,411,
    459,490,266,987,965,429,166,809,340,467,318,125,165,809,610,31,585,970,306,42,
    189,169,743,78,810,70,382,367,490,787,670,476,278,775,673,299,19,893,817,971,
    458,409,886,434};
    show(nums3);
    cout << maximumUniqueSubarray(nums3) << endl;

    return 0;
}
