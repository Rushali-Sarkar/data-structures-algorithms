#include<iostream>
#include<vector>

using namespace std;

void swap(int& num1, int& num2) {

    int temp = num1;
    num1 = num2;
    num2 = temp;
    return;
}

void helperfunction(vector<int>& arr, int starting_index, int ending_index) {

    if (starting_index >= ending_index)
        return;


    int pivot_index = starting_index;
    int left  = pivot_index + 1;
    int right = ending_index;

    while (right >= left) {


        if (arr[right] < arr[pivot_index] && arr[left] > arr[pivot_index])
            swap(arr[right], arr[left]);

        if (arr[left] <= arr[pivot_index])
            left++;

        if (arr[right] >= arr[pivot_index])
            right--;
    }

    /*  sorting the smaller array first for optimum space complexity */

    swap(arr[pivot_index], arr[right]);
    if ((right - starting_index - 1) < (ending_index - right - 1)) {
        helperfunction(arr, starting_index, right - 1);
        helperfunction(arr, right + 1, ending_index);
    }

    else {
        helperfunction(arr, right + 1, ending_index);
        helperfunction(arr, starting_index, right - 1);
    }

    return;

}

vector<int> quicksort(vector<int> arr) {

    helperfunction(arr, 0, arr.size() - 1);
    return arr;
}

void show(vector<int> arr) {

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
    return;
}

int main(int argc, char* argv[]) {

    vector<int> arr = {8, 5, 2, 9, 5, 6, 3};
    arr = quicksort(arr);
    show(arr);
    return 0;
}
