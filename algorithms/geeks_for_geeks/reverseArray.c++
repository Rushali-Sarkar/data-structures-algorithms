#include<iostream>
#include<vector>

using namespace std;

void swap(int& number1, int& number2) {
    
    int temp = number1;
    number1 = number2;
    number2 = temp;

    return;
}

vector<int> reverseArray(vector<int> arr) {

    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {

        swap(arr[left], arr[right]);
        left = left + 1;
        right = right - 1;
    }

    return arr;
}

int main(int argc, char* argv[]) {

    int size;
    int element;
    vector<int> arr;

    cin >> size;

    for (int i = 0; i < size; i++) {
        cin >> element;
        arr.push_back(element);
    }

    arr = reverseArray(arr);
    for (auto each: arr) 
        cout << each << " ";
    cout << endl;

    return 0;
}
