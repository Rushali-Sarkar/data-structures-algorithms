#include <iostream>
#include <vector>

using namespace std;

vector<int> linearSearch(vector<int>& arr, int element) {
    vector<int> indexes;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == element)
            indexes.push_back(i);
    }
    return indexes;
}

void print(vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << '\t';
    cout << endl;
    return;
}

int main(int argc, char* argv[]) {
    vector<int> arr = {1, 2, 2, 3, 4, 5, 1, 2, 3, 2, 3, 4, 5, 6, 7, 8, 9, 2, 2, 0, 2};
    vector<int> result1 = linearSearch(arr, 2);
    vector<int> result2 = linearSearch(arr, 90);
    print(result1);
    print(result2);
    return 0;
}
