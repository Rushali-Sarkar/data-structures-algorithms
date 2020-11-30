/* Problem Statement 
 * You have to implement myStack sortStack(myStack stack, int size) function which will take a stack and sort all its elements in
 * ascending order.
 *
 * Input
 *
 * A stack of integers
 *
 * Output
 *
 * Returns the stack with all its elements sorted.
 *
 * Sample Input
 *
 *  // input stack where 23 is the top
 *  23, 60, 42, 4, 97, 2
 *
 *  Sample Output
 * 
 * //resultant stack where 2 is the top
 * 2, 4, 12, 23, 42, 60, 97
 */

#include<iostream>

using namespace std;


class myStack {

    private:
        int capacity;
        int front;
        int* arr;
        int numElements;

    public:

        myStack(int value) {
            capacity = value;
            arr = new int[capacity];
            front = -1;
            numElements = 0;
        }

        bool isEmpty() {
            return numElements == 0;
        }

       int getTop() {
           return arr[front];
       }

        void push(int value) {

            if (numElements == capacity) {
                cout << "The stack is full" << endl;
                return;
            }

            arr[++front] = value;
            numElements++;
            return;
        }

        int pop() {

            if (numElements == 0) {
                cout << "The stack is empty" << endl;
                return -1;
            }

            numElements--;
            return arr[front--];
        }

        int getSize() {
            return numElements;
        }

        void showStack() {

            for (int i = 0; i <= front; i++)
                cout << arr[i] << '\t';
            cout << endl;
            return;
        }
};

myStack sortStack(myStack stack, int size) {

    myStack temporary(size);
    int temp = stack.pop();
    temporary.push(temp);
    
    while (!stack.isEmpty()) {

        temp = stack.pop();
        
        
        while (!temporary.isEmpty() && temporary.getTop() > temp) {

            stack.push(temporary.getTop());
            temporary.pop();
    }

        temporary.push(temp);
    }

    return temporary;
                    
}

int main() {

    myStack stack(7);
    stack.push(2);
    stack.push(97);
    stack.push(4);
    stack.push(42);
    stack.push(12);
    stack.push(60);
    stack.push(23);
   (sortStack(stack, 7)).showStack();
}   





