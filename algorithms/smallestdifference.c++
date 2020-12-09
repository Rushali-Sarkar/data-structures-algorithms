#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> smallestdifference(vector<int> arr1, vector<int> arr2) {

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int first_number = arr1[0];
    int second_number = arr2[arr2.size() - 1];
    int difference = abs(first_number - second_number);
    int left = 0;
    int right = 0;

    while (left < arr1.size() and right < arr2.size()) {

        if (arr1[left] == arr2[right]) {
            first_number = arr1[left];
            second_number = arr2[right];
            break;
        }

        if (abs(arr1[left] - arr2[right]) < difference) {
            first_number = arr1[left];
            second_number = arr2[right];
            difference = abs(first_number - second_number);
        }

        if (arr1[left] < arr2[right])
            left++;

        else
            right++;

    }

    return vector<int> {first_number, second_number};
}

int main(int argc, char* argv[]) {

    vector<int> arr1 = {-1, 5, 10, 20, 28, 3};
    vector<int> arr2 = {26, 134, 135, 15, 17};

    vector<int> result = smallestdifference(arr1, arr2);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}
