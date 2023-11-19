#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr) {

    for (int i = 1; i < arr.size(); ++i) {
        int j = i - 1;
        int current_element = arr[i];
        while (j >= 0 && arr[j] > current_element) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = current_element;
    }

    return;
}

void printVector(vector<int>& arr) {
    for (int i = 0 ; i < arr.size(); ++i)
        cout << arr[i] << '\t';
    cout << endl;
    return;
}

int main(int argc, char* argv[]) {

    vector<int> arr = {2, 4, 1, 1, 9, 0, 1, 1, 3, 4, 2, 7, 8, 4, 6, 0};
    insertionSort(arr);
    printVector(arr);
    return 0;
}
