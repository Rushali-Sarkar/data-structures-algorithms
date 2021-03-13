/* Problem Statement
 *
 * Implement a function findKLargest(int arr[], int size, int k) that takes an unsorted integer array as input
 * and returns the kk largest elements using a Max Heap. The maxHeap class is prepended in this exercise, so feel
 * free to use it! Have a look at the illustration given for a clearer picture of the problem.
 *
 * Output
 *
 * Reutrns integer vector containing first k largest elements from arr
 *
 * Sample Input
 *
 * 7
 * 9
 * 4
 * 7
 * 1
 * -2
 *  6
 *  5
 *  3
 *
 *  Sample Output
 *
 *  9, 7, 6
 *
 *  Explanation 
 *
 *  As "k" is 3, so we need to find the top 3 maximum elements from given array. 9 is the largest value in the
 *  array, while 7 is the second maximum, and 6 is the third max.
 */

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class maxHeapify {

    private:

        int* maxHeap;
        int size;

        void swap(int& number1, int& number2) {
            
            int temporary = number1;
            number1 = number2;
            number2 = temporary;
            return;
        }

        void siftup(int current_index) {

            int parent_index = (current_index - 1) / 2;

            while (current_index > 0 && maxHeap[current_index] > maxHeap[parent_index]) {

                swap(maxHeap[current_index], maxHeap[parent_index]);
                current_index = parent_index;
                parent_index = (current_index - 1) / 2;
            }

            return;

        }

        void siftdown(int current_index) {

            int first_child_index  = 2 * current_index + 1;

            while (first_child_index < size) {

                int second_child_index = 2 * current_index + 2;
                int index_to_swap = first_child_index;

                if (second_child_index < size && maxHeap[second_child_index] > maxHeap[first_child_index])
                    index_to_swap = second_child_index;

                if (maxHeap[index_to_swap] > maxHeap[current_index]) {

                    swap(maxHeap[index_to_swap], maxHeap[current_index]);
                    current_index = index_to_swap;
                    first_child_index = 2 * current_index + 1;
                }

                else
                    break;

            }

            return;
        }

        void buildHeap() {

            int first_parent_index = ((size - 1) - 1) / 2;

            for (int i = first_parent_index; i >= 0; i--)
                siftdown(i);

            return;
        }

    public:

        maxHeapify(int* arr, int capacity) {

            maxHeap = arr;
            size = capacity;
            buildHeap();
        }

        int remove() {

            int maximum = maxHeap[0];
            maxHeap[0] = maxHeap[size - 1];
            size--;
            siftdown(0);
            return maximum;
        }

};


string elements(vector<int> arr) {

    string result = "";

    for (int i = 0; i < arr.size() - 1; i++)
        result = result + to_string(arr[i]) + ", ";

    result = result + to_string(arr[arr.size() - 1]);
    return result;

}


vector<int> findKLargest(int arr[], int size, int k) {

    maxHeapify maxHeap(arr, size);
    vector<int> kmaximumelements;

    k = k <= size ? k : size;
    for (int i = 0; i < k ; i++)
        kmaximumelements.push_back(maxHeap.remove());

    return kmaximumelements;
}

int main(int argc, char* argv[]) {

    int arr[] = {7, 9, 4, 1, -2, 6, 5, 3};
    int size = 8;
    int k = 3;

    string kmaximumelements = elements(findKLargest(arr, size, k));
    cout << kmaximumelements << endl;

    return 0;
}



        

        



                



