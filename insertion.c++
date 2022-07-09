#include <iostream>
#include <vector>

using namespace std;

vector<int> reverseInsertionSort (vector<int>& arr) {

        for (int i = 1; i < arr.size(); ++i) {
                int key = arr[i];
                int j = i - 1;
                while (j >= 0 && arr[j] < key) {
                        arr[j + 1] = arr[j];
                        --j;
                }
                arr[j + 1] = key;
        }
        return arr;
}

void printArr (vector<int>& arr) {
        for (int each: arr)
                cout << each << '\t';
        cout << endl;
        return;
}

int main (int argc, char* argv[]) {

        vector<int> arr = {1, 8, 10, 24, 3, 7, 8, 2, 24, 24, 90, 4, 4, 4, 9, 10, 11};
        arr = reverseInsertionSort (arr);
        printArr (arr);
        return 0;
}
