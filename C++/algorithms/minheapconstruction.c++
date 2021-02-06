#include<iostream>
#include<vector>

using namespace std;

class MinHeap {
    
    
    private:

        vector<int> minheap;
        int size;

        void swap(int& number1, int& number2) {

            int temp = number1;
            number1 = number2;
            number2 = temp;
            return;
        }

        void siftup(int current_index) {
            int parent_index = (current_index - 1) / 2;
            while (current_index > 0 && minheap[parent_index] > minheap[current_index]) {
                swap(minheap[parent_index], minheap[current_index]);
                current_index = parent_index;
                parent_index = (current_index - 1) / 2;
                }
            return;
        }

        void siftdown(int current_index) {
            int first_child  = current_index * 2 + 1;
            while (first_child < size) {
                int second_child = current_index * 2 + 2;
                int index_to_swap = first_child;
                if (second_child > size)
                    second_child = -1;
                if  (second_child != -1 && minheap[second_child] < minheap[first_child])
                    index_to_swap = second_child;
                if (minheap[current_index] > minheap[index_to_swap]) {
                    swap(minheap[current_index], minheap[index_to_swap]);
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
            size = minheap.size();
            buildheap();
        }

        int peak() {
            return minheap[0];
        }
      
        void insert(int value) {
            minheap.push_back(value);
            size++;
            siftup(size - 1);
            return;
        }

        int remove() {

            if (size == 0) {
                cout << "Sorry The Heap has no value to remove" << endl;
                return -1;
            }

            swap(minheap[0], minheap[size - 1]);
            int value_to_remove = minheap.back();
            minheap.pop_back();
            size--;
            siftdown(0);
            return value_to_remove;
        }

        void show() {

            for (int index = 0; index < size; index++) 
                cout << minheap[index] << " ";
            cout << endl;
            return;
        }

};


int main(int argc, char* argv[]) {

    vector<int> arr = {12, 56, 78, 90, 34, 71, 22, 16, 85, 100, 154};
    MinHeap minheap(arr);
    minheap.show();
    minheap.insert(65);
    minheap.show();
    cout << minheap.remove() << endl;
    cout << minheap.remove() << endl;
    cout << minheap.remove() << endl;
    minheap.show();
    return 0;
}








