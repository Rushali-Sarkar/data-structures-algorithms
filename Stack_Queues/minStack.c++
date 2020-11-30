/* You have to implement the minStack class which will have a min() function. Whenever min() is called, the minimum value of the
 * stack is returned in O(1) time. The element is not popped from the stack. Its value is simply returned.
 *
 * Output
 *
 * Returns minimum number in O(1) time
 *
 * Sample Output
 * //minStack = {9, 3, 1, 4, 2, 5}
 * minStack.min()
 * 1
 */

#include<iostream>

using namespace std;

class newStack {

    private:
        int numElements;
        int top;
        int* arr;
        int* minStack;
        int capacity;

    public:

        newStack(int size) {
            capacity = size;
            arr = new int[capacity];
            minStack = new int[capacity];
            top = -1;
            numElements = 0;
        }

        int getSize() {
            return numElements;
        }

        bool isEmpty() {
            return numElements == 0;
        }

        int min() {
            return minStack[top];
        }

        int getTop() {
            return arr[top];
        }

        void push(int value) {

            if (numElements == capacity) {
                cout << "The Stack is Full" << endl;
                return;
            }

            if (numElements == 0){
                numElements++;
                minStack[++top] = value;
                arr[top] = value;
                return;
            }

            int minimum = min();
            if (minimum < value)
                minStack[++top] = minimum;
            else
                minStack[++top] = value;

            numElements++;
            arr[top] = value;
            return;
        }

        int pop() {

            if (numElements == 0) {
                cout << "The Stack is Empty" << endl;
                return -1;
            }

            numElements--;
            return arr[top--];
        }

        void showstack() {
            for (int i = 0; i <= top; i++) 
                cout << arr[i] << '\t';
            cout << endl;
            return;
        }

};

int main() {

    newStack stack(6);
    stack.push(5);
    stack.push(2);
    stack.push(4);
    stack.push(1);
    stack.push(3);
    stack.push(9);

    cout << stack.min() << endl;
    stack.pop();
    stack.pop();
    stack.pop();
    cout << stack.min() << endl;

    return 0;
}

