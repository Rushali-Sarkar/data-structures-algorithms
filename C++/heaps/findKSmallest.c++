/* Problem Statement
 *
 * Implement a function findKSmallest(int arr[], int size, int k) that takes an unsorted integer array as input
 * and returns the "k" smallest elements in the array using Heap. The minHeap class is prepended to this exercise,
 * so feel free to use it! Have a look at the illustration given for a clearer picture of the problem.
 *
 * Output
 *
 * Returns integer vector that contains the first k smallest elements form the given array.
 *
 * Sample Input
 *
 *  7
 *  9
 *  4
 *  7
 * -2
 *  6
 *  5
 *  3
 *
 *  Sample Output
 *
 *  -2, 1, 3
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;


class minHeapify {

    private:

        vector<int> minHeap;
        int size;

        void swap(int& number1, int& number2) {

            int temporary = number1;
            number1 = number2;
            number2 = temporary;
            return;
        }


        void siftup(int current_index) {

            int parent_index = (current_index - 1) / 2;

            while (minHeap[parent_index] > minHeap[current_index] && current_index > 0) {

                swap(minHeap[parent_index], minHeap[current_index]);
                current_index = parent_index;
                parent_index = (current_index) - 1 / 2;
            }

            return;
        }

        void siftdown(int current_index) {

            int first_child_index = 2 * current_index + 1;

            while (first_child_index < size) {

                int second_child_index = 2 * current_index + 2;
                int index_to_swap = first_child_index;

                if (second_child_index < size && minHeap[second_child_index] < minHeap[first_child_index])
                    index_to_swap = second_child_index;

                if (minHeap[index_to_swap] < minHeap[current_index]) {
                    
                    swap(minHeap[index_to_swap], minHeap[current_index]);
                    current_index = index_to_swap;
                    first_child_index = 2 * current_index + 1;
                }

                else
                    break;
            }

            return;
        }

        void buildheap() {

            int first_parent_index = ((size - 1) - 1) / 2;

            for (int i = first_parent_index; i >= 0; i--)
                siftdown(i);

            return;
        }

    public:

        minHeapify(vector<int> arr) {

            minHeap = arr;
            size = arr.size();
            buildheap();
        }

        void insert(int item) {

            minHeap.push_back(item);
            size++;
            siftup(size - 1);
            return;
        }

        int remove() {

            int minimum = minHeap[0];
            swap(minHeap[0], minHeap[size - 1]);
            minHeap.pop_back();
            size--;
            siftdown(0);
            return minimum;
        }

        void show() {

            for (int i = 0; i < size; i++)
                cout << minHeap[i] << '\t';
            cout << endl;
            
            return;
        }
};


string elements(vector<int> arr) {

    int size = arr.size();
    string result;

    for (int i = 0; i < size - 1; i++)
        result = result + to_string(arr[i]) + ", ";

    result = result + to_string(arr[size - 1]);
    return result;
}

vector<int> convertArraytoVector(int arr[], int size) {

    vector<int> result;

    for (int i = 0; i < size; i++) 
        result.push_back(arr[i]);

    return result;
}

vector<int> findKSmallest(int arr[], int size, int k) {

    vector<int> array = convertArraytoVector(arr, size);
    vector<int> ksmallelements;

    minHeapify minHeap(array);
    for (int i = 0; i < k; i++)
        ksmallelements.push_back(minHeap.remove());

    return ksmallelements;
}

int main(int argc, char* argv[]) {

    int arr[] = {7, 9, 1, 7, -2, 6, 5, 3};
    int size = 8;
    int k = 3;

    string ksmallelements = elements(findKSmallest(arr, size, 3));
    cout << ksmallelements << endl;

    return 0;
}






