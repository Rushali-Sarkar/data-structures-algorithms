#include<iostream>
#include<vector>

using namespace std;

vector<int> twonumbersum(vector<int> arr, int sum) {

    vector<int> result;

    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {

            if ((arr[i] + arr[j]) == sum) {
                result.push_back(arr[i]);
                result.push_back(arr[j]);
                return result;
            }
        }
    }

    return result;
}

int main(int argc, char* argv[]) {

    vector<int> arr = {3, 5, -4, 8, 11, -1, -6};
    vector<int> result = twonumbersum(arr, 10);
    if (result.size() != 0)
        cout << result[0] << " + " << result[1] << " = " << 10 << endl;
    else
        cout << "There are no two numbers in the array that adds up to " << 10 << endl;
    return 0;
}

/* This algorithm takes O(n^2) time complexity because the array is traveresed twice for the sake to find the sum
 * This algorithms takes O(1) time complexity because the array takes no extra space but accesses the values from the already present array*/

