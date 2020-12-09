#include<iostream>
#include<vector>

using namespace std;


void show(vector<int> arr) {

    for (auto element: arr)
        cout << element << " ";
    cout << endl;
    return;
}

void swap(int& num1, int& num2) {

    int temp = num1;
    num1 = num2;
    num2 = temp;
    return;
}

vector<int> sort012(vector<int> arr) {

    int low = 0;
    int mid = 0;
    int high = arr.size() - 1;

    while (mid <= high) {

    
        if (arr[mid] == 1) 
            mid++;

        else if (arr[mid] == 0) {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }

        else if (arr[mid] == 2) {
            swap(arr[mid], arr[high]);
            high--;
        }
    }

    return arr;
}


int main(int argc, char* argv[]) {

    vector<int> arr = {1, 1, 0, 0, 1, 2, 2, 2, 0, 0, 1, 1, 0, 1};
    arr = sort012(arr);
    show(arr);

    vector<int> arr2 = {2, 0, 0, 1, 2, 1, 0};
    arr2 = sort012(arr2);
    show(arr2);

    vector<int> arr3 = {2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0};
    arr3 = sort012(arr3);
    show(arr3);

    vector<int> arr4 = {0, 0, 0, 1, 2, 1, 0};
    arr4 = sort012(arr4);
    show(arr4);

    return 0;
}
          
