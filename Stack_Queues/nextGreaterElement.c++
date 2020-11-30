/* Problem Statement
 *
 * You must implement the int* nextGreaterElement(int* arr, int size) fucntion. For each element in an array, it finds the next
 * greater element in that array.
 *
 * Note: The next greater element is the first element towrds the right, which is greater than the current element.
 *
 * For example, in the array[1, 3, 8, 4, 10, 5], the next greater element of 3 is 8, and the next greater element for 8 is 10.
 * To keep it simple, the next greater element for the last or maximum value in the array is -1.
 * In each iteration, we only check the array elements appearing after the current element.
 *
 * Input
 *
 * An Integer array and its size.
 *
 * Output
 *
 * An array containing the next greater element of each element from the input list. For the maximum value in the list, the next
 * greater value in the list, the next greater value is -1.
 *
 * Sample Input
 *
 * {4, 6, 3, 2, 8, 1};
 *
 * Sample Output
 *
 * {6, 8, 8, 8, -1, -1}
 */

#include<iostream>

using namespace std;

class Stack {

    private:
        int numElements;
        int top;
        int capacity;
        int* stackArr;

    public:

        Stack(int size) {
            capacity = size;
            top = -1;
            numElements = 0;
            stackArr = new int[capacity];
        }

        int getSize() {
            return numElements;
        }

        int getTop() {
            return stackArr[top];
        }

        bool isEmpty() {
            return numElements == 0;
        }

        void push(int value) {

            if (numElements == capacity) {
                cout << "The Stack is Full" << endl;
                return;
            }

            numElements++;
            stackArr[++top] = value;
            return;
        }

        int pop() {

            if (numElements == 0) {
                cout << "The Stack is Empty" << endl;
                return -1;
            }

            numElements--;
            return stackArr[top--];
        }

        void showStack() {
            for (int i = 0; i <= top; i++)
                cout << stackArr[i] << '\t';
            cout << endl;
            return;
        }
};

int* nextGreaterElement(int* arr, int size) {

    Stack nextGreater(size);
    int* result = new int[size];
    int nextG = -1;
    for (int i = size - 1; i >= 0; i--) {

        if (nextGreater.isEmpty() || arr[i] == nextG) {
            nextG = -1;
            nextGreater.push(arr[i]);
        }

        if (arr[i] < nextGreater.getTop()) {
            nextG = nextGreater.getTop();
            nextGreater.push(arr[i]);
        }

        if (arr[i] > nextGreater.getTop()) {
            nextGreater.pop();
            nextGreater.push(arr[i]);
        }

        result[i] = nextG;
    }

    return result;
}

int main() {

   int arr[] = {4, 6, 3, 2, 8, 1, 9, 9};
   int arr_size = sizeof(arr) / sizeof(arr[0]);
   int* res = nextGreaterElement(arr, arr_size);
   cout << "____Result___" << endl;
   for (int i = 0; i < arr_size; i++)
       cout << arr[i] << " ---> " << res[i] << endl;
}

    


