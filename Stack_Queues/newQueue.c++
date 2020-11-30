/* Problem Statement
 *
 * You have to implement enqueue() and dequeue() functions in the newQueue class using the myStack the class we created 
 * earlier. enqueue() will insert a value into the queue and dequeue will remove a value from the queue.
 *
 * Input
 * enqueue(int value): A value to insert into the queue
 * dequeue(): Does not require inputs.
 *
 * Output
 *
 * enqueue(): Returns True after inserting the value into the queue.
 * dequeue(): Pops out and returns the oldest value in the queue.
 *
 * Sample Input
 *
 * value = 5 // queue = [1, 2, 3, 4]
 * enqueue(value)
 * dequeue()
 *
 * Sample Output
 *
 * True //queue = [1, 2, 3, 4, 5]
 * 1 // queue = [2, 3, 4, 5]
 */

#include<iostream>

using namespace std;


class myStack {
    public: 
        int capacity;
        int* stackarr;
        int front;
        int numElements;

  
        myStack(int size) {
            capacity = size;
            stackarr = new int[capacity];
            front = -1;
            numElements = 0;
        }

        int getSize() {
            return numElements;
        }

        void push(int value) {

            if (front == capacity - 1) {
                cout << "Stack is full" << endl;
                return;
            }
            
            numElements++;
            stackarr[++front] = value;
            return;
        }

        int pop() {

            if (front == -1) {
                cout << "The stack is empty" << endl;
                return -1;
            }
            
            numElements--;
           return stackarr[front--];
        }

        void showstack() {
            for (int i = 0; i < numElements; i++) 
                cout << stackarr[i] << '\t';
            cout << endl;
            return;
        }

        
};

class newQueue {

    private:

       int size;
       int queueelements;
       int helperelements;
       myStack* queue;
       myStack* helper;

       void addtohelper() {

           if (queueelements == 0) {
               cout << "The Queue is empty" << endl;
               return;
           }

           while (queueelements > 0) {
               helper -> push (queue -> pop());
               helperelements++;
               queueelements--;
           }
           return;
       }

    public:

       newQueue(int value){
        size = value;
        queue = new myStack(size);
        helper = new myStack(size);
        queueelements = 0;
        helperelements = 0;
        }

       void enQueue(int value) {

            if (queueelements == size) {
                cout << "The queue is full" << endl;
                return;
            }

            queue -> push(value);
            queueelements++;
            return;
       }

       int deQueue() {

           if (helperelements == 0)
               addtohelper();
            
           if (helperelements == 0)
               return -1;

           helperelements--;
           return helper -> pop();
       }
  
};

int main() {

    newQueue queue(5);
    
    queue.enQueue(1);
    queue.enQueue(2);
    queue.enQueue(3);
    queue.enQueue(4);
    queue.enQueue(5);
                       
    cout << queue.deQueue() << endl;
    cout << queue.deQueue() << endl;
    cout << queue.deQueue() << endl;
    cout << queue.deQueue() << endl;
    cout << queue.deQueue() << endl;
    cout << queue.deQueue() << endl;
    return 0;
}
