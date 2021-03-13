#include<iostream>
#include<vector>

using namespace std;

vector<int> selectionsort(vector<int> arr) {

    for (int i = 0; i < arr.size() - 1; i++) {

        int minimum = arr[i];
        int index = i;

        for (int j = i + 1; j < arr.size(); j++) {

            if (arr[j] < minimum) { 
                minimum = arr[j];
                index = j;
            }
        }

        arr[index] = arr[i];
        arr[i] = minimum;
    }

    return arr;
}


int main(int argc, char* argv[]) {

    vector<int> arr = {8, 5, 2, 9, 5, 6, 3};
    arr = selectionsort(arr);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}

