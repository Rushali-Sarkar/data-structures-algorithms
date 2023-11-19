#include <iostream>
#include <vector>

using namespace std;

void reverseInsertionSort(vector<int>& arr) {

    for (int i = 1; i < arr.size(); ++i) {
        
        int j = i - 1;
        int current_element = arr[i];
        while (j >= 0 && current_element > arr[j]) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = current_element;
    }

    return;
}

void print(vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << ' ';
    cout << endl;
    return;
}

int main(int argc, char* argv[]) {

    vector<int> arr = {1, 7, 8, 0, 1, 4, 5, 7, 1, 2, 3, 3, 4, 0, 9, 8, 7, 6, 1, 2, 3, 3, 4};
    reverseInsertionSort(arr);
    print(arr);
    return 0;
}
