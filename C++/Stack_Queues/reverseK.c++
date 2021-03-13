/* Problem Statement
 *
 * Implement the function myQueue reverseK(myQueue queue, int k) which takes a queue and a number k as input and reverses the first
 * k elements of the queue. An illustration is also provided for your understanding.
 *
 * Input
 *
 * A queue and an integer k such that 0 <= k <= size of queue
 *
 * Output
 *
 * Queue with the first k elements reversed
 *
 * Sample Input
 *
 * [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
 *
 * 5
 *
 * Sample Output
 *
 * [5, 4, 3, 2, 1, 6, 7, 8, 9, 10]
 *
 */

#include<iostream>
#include<cassert>

using namespace std;

class myQueue {

    public:
        int capacity;
        int* queuearr;
        int front;
        int back;
        int numElements;


        myQueue(int size) {
            capacity = size;
            queuearr = new int[capacity];
            assert(queuearr != NULL);
            front = 0;
            back = -1;
            numElements = 0;
        }

        bool isEmpty() {
            return (numElements == 0);
        }

        void enqueue(int value) {

            if (numElements == capacity) {
                cout << "The Queue is full" << endl;
                return;
            }

            if (back == capacity - 1)
                back = -1;

            queuearr[++back] = value;
            numElements++;
            return;
        }

        int dequeue() {
            
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
                return -1;
            }

            int element = queuearr[front++];
            if (front == capacity)
               front = 0;
           numElements--;
          return element;
        }

       int getSize() {
          return numElements;
       }

      int getFront() {
         if (isEmpty()) {
            cout << "Queue is Empty" << endl;
           return - 1;
         }

         return queuearr[front];
      }

      void showqueue() {
          for (int i = 0; i < numElements; i++) 
              cout << queuearr[i] << " ";
          cout << endl;
          return;
      }
};

class stack {

    private:
        int size;
        int numElements;
        int front;
        int* stackarr;

   public:

        stack(int value) {
            size = value;
            stackarr = new int[size];
            numElements = 0;
            front = -1;
        }

        void push(int value) {
            if (front == size - 1) {
                cout << "Stack is full" << endl;
                return;
            }

            stackarr[++front] = value;
            numElements++;
        }

        int getLength() {
            return numElements;
        }

        int pop() {

            if (front == -1) {
                cout << "The stack is empty" << endl;
                return -1;
            }

            int element = stackarr[front];
            front--;
            numElements--;
            return element;
        }

        void print() {
            for (int i = 0; i < numElements; i++)
                cout << stackarr[i] << '\t' ;
            cout << endl;
            return;
        }
};


myQueue reverseK(myQueue queue, int k) {
    
    int size = queue.getSize();
    
    stack temp(k);
    myQueue result(size);
    
    for (int i = 0; i < k; i++) {
        int element = queue.dequeue();
        temp.push(element);
    }

    for (int i = 0; i < k; i++) {
        int element = temp.pop();
        result.enqueue(element);
    }

    for (int i = 0; i < size - k; i++) {
        int element = queue.dequeue();
        result.enqueue(element);
    }

    return result;
}




int main() {

    myQueue mQ(10);

    mQ.enqueue(1);
    mQ.enqueue(2);  
    mQ.enqueue(3);  
    mQ.enqueue(4);  
    mQ.enqueue(5);  
    mQ.enqueue(6);  
    mQ.enqueue(7);  
    mQ.enqueue(8);  
    mQ.enqueue(9);  
    mQ.enqueue(10);
    
    mQ = reverseK(mQ, 5);
    mQ.showqueue(); // show queue prepended in the hidden code;
}//Your code here  
