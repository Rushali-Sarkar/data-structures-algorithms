#include<iostream>
#include<vector>

using namespace std;

vector<int> twonumbersum(vector<int> arr, int sum) {

    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if ((arr[i] + arr[j]) == sum)
                return vector<int> {arr[i], arr[j]};
        }
    }

    return vector<int> {-1, -1};
}

int main(int argc, char* argv[]) {

    vector<int> arr{-4, -1, 1, 3, 5, 6, 8, 11};
    int sum = 10;
    
    vector<int> result = twonumbersum(arr, sum);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
