#include<iostream>
#include<vector>

using namespace std;

void swap(int& num1, int& num2) {

    int temp = num1;
    num1 = num2;
    num2 = temp;
    return;
}

vector<int> movetoend(vector<int> arr, int element) {

    int left  = 0;
    int right = arr.size() - 1;

    while (left < right) {

        if (arr[right] == element) 
            right--;

        else {

            if (arr[left] == element) {
                swap(arr[right], arr[left]);
            }

            else 
                left++;
        }
    }

    return arr;
}

int main(int argc, char* argv[]) {

    vector<int> arr = {2, 1, 2, 2, 2, 3, 4, 2};
    arr = movetoend(arr, 2);
    for (auto number: arr)
        cout << number << " ";
    cout << endl;
    return 0;
}
