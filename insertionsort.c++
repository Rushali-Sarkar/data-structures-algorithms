#include <iostream>
#include <vector>

using namespace std;

vector<int> insertionSort (vector<int>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; ++i) {
                int key = arr[i];
                int j = i - 1;
                while (j >= 0 && arr[j] > key) {
                        arr[j + 1] = arr[j];
                        --j;
                }
                arr[j + 1] = key;
        }
        return arr;
}

void printArr (vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i)
                cout << arr[i] << '\t';
        cout << endl;
        return;
}


int main (int argc, char* argv[]) {
        vector<int> arr = {1, 6, 9, 9, 10, 2, 4, 5, 1, 7};
        arr = insertionSort (arr);
        printArr (arr);
        return 0;
}
