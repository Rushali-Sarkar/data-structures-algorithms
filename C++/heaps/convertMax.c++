/* Problem Statement
 *
 * Implement a function convertMax(vector<int> maxHeap), which will convert a binary Max-Heap into binary
 * Min-Heap. Where maxHeap is a vector which is given in the maxHeap form, i.e., the parent is greater than its
 * children.
 *
 * Output
 * Returns converted list in string format
 *
 * Sample Input
 * 7 // size of vector
 *
 *  9
 *  4
 *  7
 *  1
 * -2
 *  6
 *  5
 *
 *  Sample Output
 *
 *  "-2, 1, 5, 9, 4, 6, 7"
 */

#include<iostream>
#include<vector>
#include<string>

using namespace std;


string elements(vector<int> arr) {

    string result = "";
    for (int i = 0; i < arr.size() - 1; i++)
        result = result + to_string(arr[i]) + ", ";

    result = result + to_string(arr[arr.size() - 1]);
    return result;
}

vector<int> positionIndex(vector<int> arr, int current_index) {

    int first_child_index = 2 * current_index + 1;
    int size = arr.size();

    while (first_child_index < size) {

        int second_child_index = 2 * current_index + 2;
        int index_to_swap = first_child_index;

        if (second_child_index < size && arr[second_child_index] < arr[first_child_index])
            index_to_swap = second_child_index;

        if (arr[index_to_swap] < arr[current_index]) {

            swap(arr[index_to_swap], arr[current_index]);
            current_index = index_to_swap;
            first_child_index = 2 * current_index + 1;
        }

        else
            break;

    }

    return arr;
}

string convertMax(vector<int> maxHeap) {

    int size = maxHeap.size();
    int first_parent_index = ((size - 1) - 1) / 2;

    for (int i = first_parent_index; i >= 0; i--)
        maxHeap = positionIndex(maxHeap, i);

    return elements(maxHeap);
}

int main(int argc, char* argv[]) {

    vector<int> maxHeap {9, 4, 7, 1, -2, 6, 5};
    cout << convertMax(maxHeap) << endl;

    return 0;
}    
