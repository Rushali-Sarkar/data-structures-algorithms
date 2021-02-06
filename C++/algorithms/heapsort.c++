#include<iostream>
#include<vector>

using namespace std;

void swap (int& number1, int& number2) {

    int temp = number1;
    number1  =  number2;
    number2  = temp;
    return;
}

void siftdown(vector<int>& arr, int current_index, int ending_index) {
   
       int first_child_index = current_index * 2 + 1;

       while (first_child_index <= ending_index) {

           int second_child_index = current_index * 2 + 2;
           int index_to_swap = first_child_index;

           if (second_child_index > ending_index) 
               second_child_index = -1;

           if (second_child_index != -1 && arr[second_child_index] > arr[first_child_index])
               index_to_swap = second_child_index;

           if (arr[current_index] < arr[index_to_swap]) {
               swap(arr[current_index], arr[index_to_swap]);
               current_index = index_to_swap;
               first_child_index = 2 * current_index + 1;
           }

           else 
               break;
       }

    return; 
}


vector<int> maxheapify(vector<int> arr) {

    int first_parent_index = ((arr.size() - 1) - 1) / 2;
    for (int current_index = first_parent_index; current_index >= 0; current_index--)
        siftdown(arr, current_index, arr.size() - 1);

    return arr;
}


vector<int> heapsort(vector<int> arr) {
    
    arr = maxheapify(arr);
    for (int i = arr.size() - 1; i > 0 ; i--) {
       swap(arr[0], arr[i]);
       siftdown(arr, 0, i - 1);
    }

    return arr;
}

void show(vector<int> arr) {

    for (auto element: arr) 
        cout << element << " ";
    cout << endl;
    
    return;
}



int main(int argc, char* argv[]) {

    vector<int> arr = {8, 5, 2, 9, 5, 6, 3};
    arr = heapsort(arr);
    show(arr);
    return 0;
}


