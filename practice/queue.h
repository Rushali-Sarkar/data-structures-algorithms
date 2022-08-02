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
        
