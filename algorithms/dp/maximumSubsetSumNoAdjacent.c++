#include<iostream>
#include<vector>

using namespace std;


int maximumSum(vector<int> arr) {

    int size = arr.size();
    int first = 0;
    int second = arr[0];

    for (int i = 1; i < size; i++) {
   
        int maximum = max(first + arr[i], second);
        first = second;
        second = maximum;
    }

    return second;
}

int main(int argc, char* argv[]) {

    vector<int> arr{50, 1, 2, 70, 3, 90, 7, 5};
    cout << maximumSum(arr) << endl;
    return 0;
}
