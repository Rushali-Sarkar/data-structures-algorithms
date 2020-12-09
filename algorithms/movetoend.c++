#include<iostream>
#include<vector>

using namespace std;

vector<int> movetoend(vector<int> arr, int element) {

    int index = 0;
    
    for (auto number: arr) {
        
        if (number != element) {
            arr[index] = number;
            index++;
        }

    }

    for (int i = index; i < arr.size(); i++)
        arr[i] = element;

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

