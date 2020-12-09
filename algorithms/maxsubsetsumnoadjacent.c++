#include<iostream>
#include<vector>

using namespace std;

int maxSumWithoutAdjacent(vector<int> arr) {

    vector<int> maxSums {arr[0], arr[1]};
    for (int i = 2; i < arr.size(); i++) {

        if (maxSums[i - 1] > (maxSums[i - 2] + arr[i]))
           maxSums.push_back(maxSums[i - 1]);

        else
           maxSums.push_back((maxSums[i - 2] + arr[i]));
    }

   return maxSums.back(); 
}



int main(int argc, char* argv[]) {

    vector<int> arr = {7, 10, 12, 7, 9, 14};
    vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> arr3 = {1, 64, 21, 4, 34, 7, 55};
    vector<int> arr4 = {1, 64, 21, 4, 110, 7, 99};

    cout << maxSumWithoutAdjacent(arr)  << endl;
    cout << maxSumWithoutAdjacent(arr2) << endl;
    cout << maxSumWithoutAdjacent(arr3) << endl;
    cout << maxSumWithoutAdjacent(arr4) << endl;

    return 0;
}
