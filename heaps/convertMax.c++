#include<iostream>
#include<string>
#include<vector>

using namespace std;

int parent_index(int index) {
    return (index - 1) / 2;
}

void swap(int* num1, int* num2) {
    int* temp = num1;
    num1 = num2;
    num2 = temp;
   return;
} 

string convertMax(vector<int> arr) {
    

    int length = arr.size();
    int child = 0;
    int parent = 0;
    string minHeap = "";

    for (int i = length - 1 ; i > 0; i--) {

        child = i;
        parent = parent_index(i);

        if (arr[child] > arr[parent])
            continue;

        while (arr[child] < arr[parent]) {
            swap(arr[parent], arr[child]);
            child = parent;
            parent = parent_index(child);
        }
    }

    for (int i = 0; i < length - 1; i++) {
        minHeap = minHeap + to_string(arr[i]) + ",";
    }
    minHeap = minHeap + to_string(arr[length - 1]);

    return minHeap;
}

int main() {

    vector<int> x;
    x.push_back(9);
    x.push_back(4);
    x.push_back(7);
    x.push_back(1);
    x.push_back(-2);
    x.push_back(6);
    x.push_back(5);

    cout << convertMax(x) << endl;
    return 0;
}

