#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& arr) {
        for (auto each: arr)
                cout << each << '\t';
        cout << endl;
        return;
}


void merge(vector<int>& arr, int start, int middle, int end) {

        vector<int> arr1;
        vector<int> arr2;

        for (int i = start; i <= middle; ++i)
                arr1.push_back(arr[i]);
        for (int i = middle + 1; i <= end; ++i)
                arr2.push_back(arr[i]);

        int pointer1 = 0;
        int pointer2 = 0;
        int pointer3 = start;

        while (pointer1 < (middle - start + 1) && pointer2 < (end - middle)) {

                int number1 = arr1[pointer1];
                int number2 = arr2[pointer2];

                if (number1 <= number2) {
                        arr[pointer3] = number1;
                        ++pointer1;
                }
                else if (number2 <= number1) {
                        arr[pointer3] = number2;
                        ++pointer2;
                }

                ++pointer3;
        }

        while (pointer1 < (middle - start + 1)) {
                int number1 = arr1[pointer1];
                arr[pointer3] = number1;
                ++pointer1;
                ++pointer3;
        }

        while (pointer2 < (end - middle)) {
                int number2 = arr2[pointer2];
                arr[pointer3] = number2;
                ++pointer2;
                ++pointer3;
        }

        return;
}


void mergeSort(vector<int>& arr, int start, int end) {

        if (start < end) {
                int middle = (start + end) / 2;
                mergeSort(arr, start, middle);
                mergeSort(arr, middle + 1, end);
                merge(arr, start, middle, end);
        }

        return;
}


int main(int argc, char* argv[]) {

        vector<int> arr = {1, 4, 5, 90, -23, 45, 67, -9, 21, 44, 1, 0, -6, -9, 1};
        print(arr);
        mergeSort(arr, 0, arr.size() - 1);
        print(arr);
        return 0;
}
