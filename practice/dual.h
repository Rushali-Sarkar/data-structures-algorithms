#include <iostream>

using namespace std;

class Queue {

    private:
        int head;
        int tail;
        int* queue_arr;
        int length;

    public:
        Queue() {
            this -> head = 0;
            this -> tail = 0;
            this -> length = 0;
            this -> queue_arr = new int(0);
        }

        Queue(int length) {
            this -> head = 0;
            this -> tail = 0;
            this -> length = length;
            this -> queue_arr = new int(this -> length + 1);
        }

        bool isEmpty() {
            return this -> head == this -> tail;
        }
        
        bool isFull() {
            if (this -> tail == this -> length && this -> head == 0)
                return true;
            return this -> head = this -> tail + 1;
        }

        void enqueue(int element) {
            if (this -> isFull())
                return;
            this -> queue_arr[this -> tail] = element;
            this -> tail += 1;
            if (this -> tail == this -> length + 1)
                this -> tail = 0;
            return;
        }
        
        int dequeue() {
            if (this -> isEmpty())
                return -1;
            int dequeue_element = this -> queue_arr[this -> head];
            this -> head += 1;
            if (this -> head == this -> length + 1)
                this -> head = 0;
            return dequeue_element;
        }
        
        int peekHead() {
            if (this -> isEmpty())
                return -1;
            return this -> queue_arr[this -> head];
        }
        
        int peekTail() {
            if (this -> isEmpty())
                return -1;
            if (this -> tail == 0)
                return this -> queue_arr[this -> length];
            return this -> queue_arr[this -> tail - 1];
        }
        
        void print() {
            if (this -> isEmpty())
                return;
            if (this -> head < this -> tail) {
                for (int i = this -> head; i < this -> tail; ++i)
                    cout << this -> queue_arr[i] << '\t';
                cout << endl;
            }
            for (int i = this -> head; i <= this -> length; ++i)
                cout << this -> queue_arr[i] << '\t';
            for (int i = 0; i < this -> tail; ++i)
                cout << this -> queue_arr[i] << '\t';
            cout << endl;
            return;
        }
};
        
class Stack {

    private:
        int top;
        int n;
        int* stack_arr;

    public:
        Stack() {
            this -> top = -1;
            this -> n = 0;
            this -> stack_arr = new int(this -> n);
        }

        Stack(int n) {
            this -> top = -1;
            this -> n = n;
            this -> stack_arr = new int(this -> n);
        }

        bool isEmpty() {
            return this -> top == -1;
        }

        bool isFull() {
            return this -> top == this -> n - 1;
        }

        void push(int element) {
            if (this -> isFull())
                return;
            this -> top += 1;
            this -> stack_arr[this -> top] = element;
            return;
        }

        int pop() {
            if (this -> isEmpty())
                return -1;
            int pop_element = this -> stack_arr[this -> top];
            return pop_element;
        }

        int peek() {
            if (this -> isEmpty())
                return -1;
            return this -> stack_arr[this -> top];
        }

        void print() {
            for (int i = 0; i <= this -> top; ++i)
                cout << this -> stack_arr[i] << '\t';
            cout << endl;
            return;
        }
};

class QueueUsingStack {


    private:
        Stack* stack1;
        Stack* stack2;
        int n;
        int items;
    
    public:
        QueueUsingStack() {
            this -> stack1 = new Stack();
            this -> stack2 = new Stack();
            this -> n = 0;
            this -> items = 0;
        }

        QueueUsingStack(int n) {
            this -> stack1 = new Stack(n);
            this -> stack2 = new Stack(n);
            this -> n = n;
            this -> items = 0;
        }

        bool isEmpty() {
            return this -> items == 0;
        }

        bool isFull() {
            return this -> items == this -> n;
        }

        void enqueue(int element) {
            if (this -> isFull())
                return;
            this -> stack1 -> push(element);
            this -> items += 1;
            return;
        }

        int dequeue() {
            if (this -> isEmpty())
                return -1;
            this -> items -= 1;
            if (!this -> stack2 -> isEmpty())
                return this -> stack2 -> pop();
            while (!this -> stack1 -> isEmpty())
                this -> stack2 -> push(this -> stack1 -> pop());
            return this -> stack2 -> pop();
        }

};


class StackUsingQueue {

    private:
        int n;
        int items;
        Queue* queue1;
        Queue* queue2;

    public:
        StackUsingQueue() {
            this -> queue1 = new Queue();
            this -> queue2 = new Queue();
            this -> n = 0;
            this -> items = 0;
        }

        StackUsingQueue(int n) {
            this -> queue1 = new Queue(n);
            this -> queue2 = new Queue(n);
            this -> n = n;
            this -> items = 0;
        }

        bool isEmpty() {
            return this -> items == 0;
        }

        bool isFull() {
            return this -> items == this -> n;
        }

        void push(int element) {
            if (this -> isFull())
                return;
            this -> items += 1;
            if (this -> queue2 -> isEmpty()) {
                this -> queue1 -> enqueue(element);
                return;
            }
            this -> queue2 -> enqueue(element);
            return;
        }

        int pop() {
            if (this -> isEmpty())
                return -1;
            int last_element_popped = -1;
            this -> items -= 1;
            if (this -> queue1 -> isEmpty()) {
                while (!this -> queue2 -> isEmpty()) {
                    last_element_popped = this -> queue2 -> dequeue();
                    if (this -> queue2 -> isEmpty())
                        return last_element_popped;
                    this -> queue1 -> enqueue(last_element_popped);
                }
                return last_element_popped;
            }
            while (!this -> queue1 -> isEmpty()) {
                last_element_popped = this -> queue1 -> dequeue();
                if (this -> queue1 -> isEmpty())
                    return last_element_popped;
                this -> queue2 -> enqueue(last_element_popped);
            }
            return last_element_popped;
        }
};