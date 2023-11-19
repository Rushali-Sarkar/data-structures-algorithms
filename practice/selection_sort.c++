#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << '\t';
    cout << endl;
    return;
}

void swapIndices(vector<int>& arr, int index1, int index2) {
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
    return;
}

void selectionSort(vector<int>& arr) {

    for (int i = 0; i < arr.size() - 1; ++i) {
        int minimum_number_index = i;
        for (int j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[minimum_number_index])
                minimum_number_index = j;
        }
        swapIndices(arr, minimum_number_index, i);
    }
    return;
}


int main(int argc, char* argv[]) {

    vector<int> arr = {1, 2, 3, 3, 2, 1, 4,5, 6, 1, 2, 3, 0, 7, 8, 9};
    selectionSort(arr);
    print(arr);
    return 0;
}
