#include<iostream>
#include<vector>

using namespace std;


void swap(int& number1, int& number2) {

    int temp = number1;
    number1 = number2;
    number2 = temp;
    
    return;
}

vector<int> moveZeroes(vector<int> arr) {

    int index = 0;
    int size = arr.size();

    for (int i = 0; i < size; i++) {

        if (arr[i] != 0)
            swap(arr[index++], arr[i]);
    }

    return arr;
}

int main(int argc, char* argv[]) {

    int size;
    vector<int> arr;
    cin >> size;
    

    for (int i = 0; i < size; i++) {
        int element;
        cin >> element;
        arr.push_back(element);
    }

    arr = moveZeroes(arr);

    for (auto element: arr)
        cout << element << " ";

    cout << endl;

    return 0;
}
