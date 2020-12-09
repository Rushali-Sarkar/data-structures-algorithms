#include<iostream>
#include<vector>

using namespace std;

vector<int> bubblesort(vector<int> arr){

    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {

            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }

        }
    }

    return arr;
}

int main(int argc, char* argv[]) {

    vector<int> arr = {8, 5, 2, 9, 5, 6, 3};
    arr = bubblesort(arr);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}

