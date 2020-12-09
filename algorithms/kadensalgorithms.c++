#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

vector<int> kadensalgorithm(vector<int> arr) {

    int maxTillNow = 0;
    int currentMax = INT_MIN;
    int start_index = -1;
    int end_index = -1;
    
    for (int i = 0; i < arr.size(); i++) {

        if ((maxTillNow + arr[i]) > arr[i])
           maxTillNow  = maxTillNow + arr[i];

        else {
           maxTillNow = arr[i];
           start_index = i;
        }

        if (currentMax <  maxTillNow) {
            currentMax = maxTillNow;
            end_index = i;
        }

    }

    return vector<int> {start_index, end_index, currentMax};
}

int main(int argc, char* argv[]) {

    vector<int> arr = {3, 5, -9, 1, 3, -2, 3, 4, 7, 2, -9, 6, 3, 1, -5, 4};
    vector<int> result = kadensalgorithm(arr);

    cout << "The array is : " << endl;
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;

    int start_index = result[0];
    int end_index = result[1];
    int maxSum = result[2];

    cout << "The sub-array with maximum sum is : " << endl;
    for (int i = start_index; i <= end_index; i++) 
        cout << arr[i] << " ";
    cout << endl;

    cout << "The maximum sum is: " << maxSum << endl;
    return 0;
}
