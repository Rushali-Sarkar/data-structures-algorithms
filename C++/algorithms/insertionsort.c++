#include<iostream>
#include<vector>

using namespace std;

vector<int> insertionsort(vector<int> arr) {

    for (int i = 1; i < arr.size(); i++) {

        int index = i;

        while (index > 0 && arr[index] < arr[index - 1]) {

           int temp = arr[index];
           arr[index] = arr[index - 1];
           arr[index - 1] = temp;
           index--;

        }
    }
    return arr;
}

int main(int argc, char* argv[]) {

    vector<int> arr = {8, 5, 2, 9, 5, 6, 3};
    arr = insertionsort(arr);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
