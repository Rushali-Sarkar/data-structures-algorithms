#include<iostream>
#include<vector>

using namespace std;


class MinHeap {

    private:

        vector<int> minheap;
        int size;

        void swap(int& number1, int& number2) {

            int temp = number1;
            number1  = number2;
            number2  = temp;
            return;
        }

        void siftup(int current_index) {

            int parent_index = (current_index - 1) / 2;

            while (minheap[parent_index] > minheap[current_index] && current_index > 0) {
                swap(minheap[parent_index], minheap[current_index]);
                current_index = parent_index;
                parent_index = (current_index - 1) / 2;
            }

            return;
        }

        void siftdown(int current_index) {

            int first_child = 2 * current_index + 1;
            
            while (first_child < size) {

                int second_child = 2 * current_index + 2;
                int index_to_swap = first_child;

                if (second_child >= size)
                    second_child = -1;

                if (second_child != -1 && arr[second_child] < arr[first_child])
                    index_to_swap = second_child;

                if (arr[current_index] > arr[index_to_swap]) {
                    swap(arr[current_index], arr[index_to_swap]);
                    current_index = index_to_swap;
                    first_child = current_index * 2 + 1;
                }

                else
                    break;
            }

            return;
        }

        void buildheap() {

            int first_parent_index = ((size - 1) - 1) / 2;
            for (int current_index = first_parent_index; current_index >= 0; current_index--) 
                siftdown(current_index);
            return;
        }

    public:

        MinHeap(vector<int> arr) {
            minheap = arr;
            size = arr.size();
            buildheap();
        }

        void insert(int value) {

            size++;
            minheap.push_back(value);
            siftup(size - 1);
            return;
        }


        int remove() {

            if (size == 0)
                return -1;
            
            swap(minheap[0],  minheap[size - 1]);
            int minimum = minheap.back();
            minheap.pop_back();
            size--;
            siftdown(0);
            return minimum;
        }

        void show() {

            for (auto element: minheap)
                cout << element << " ";
            cout << endl;
            return;
        }
};






