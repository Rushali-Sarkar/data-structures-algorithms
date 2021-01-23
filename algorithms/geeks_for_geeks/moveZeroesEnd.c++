#include<iostream>
#include<vector>

using namespace std;

vector<int> moveZeroes(vector<int> arr) {

    int count_zeroes = 0;
    int count_non_zeroes = 0;

    for (auto element: arr) {

        if (element == 0)
            count_zeroes ++;

        else
            arr[count_non_zeroes++] = element;
       

    }

    for (int i = 0; i < count_zeroes; i++) 
       arr[count_non_zeroes++] = 0; 

    return arr;
}

int main(int argc, char* argv[]) {

    int size;
    cin >> size;
    vector<int> arr;

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



