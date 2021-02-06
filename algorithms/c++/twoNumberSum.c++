#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

vector<int> twonumbersum(vector<int> arr, int sum) {

    unordered_set<int> trackPossibleSum;
    for (auto element: arr) {

        int possible_match = sum - element;

        if (trackPossibleSum.find(possible_match) != trackPossibleSum.end())
            return vector<int> {possible_match, element};

        trackPossibleSum.insert(element);
    }

    return vector<int> {-1, -1};
}

int main(int argc, char* argv[]) {

    vector<int> arr{3, 5, -4, 8, 11, 1, -1, 6};
    int sum = 10;

    vector<int> result = twonumbersum(arr, sum);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
