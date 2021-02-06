#include<iostream>
#include<vector>

using namespace std;

vector<int> rotate(vector<int> arr, int rotations) {

    vector<int> temp;
    int size = arr.size();

    rotations = rotations % size;
    for (int i = 0; i < rotations; i++) 
        temp.push_back(arr[i]);

    int index = 0;
    for (int i = rotations; i < size; i++)
        arr[index++] = arr[i];

    int temp_index = 0;
    for (int i = index; i < size; i++)
        arr[i] = temp[temp_index++];

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

    int rotations;
    cin >> rotations;

    arr = rotate(arr, rotations);

    for (auto element: arr) 
        cout << element << " ";

    cout << endl;

    return 0;
}
      
