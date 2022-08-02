#include <iostream>

using namespace std;

class Deque {

    private:
        int head;
        int tail;
        int length;
        int* arr;

    public:
        Deque() {
            this -> head = 0;
            this -> tail = 0;
            this -> length = 0;
            this -> arr = new int(0);
        }

        Deque(int length) {
            this -> head = 0;
            this -> tail = 0;
            this -> length = length;
            this -> arr = new int(this -> length + 1);
        }

        bool isEmpty() {
            return this -> head == this -> tail;
        }

        bool isFull() {
            if (this -> tail == this -> length && this -> head == 0)
                return true;
            return this -> head = this -> tail + 1;
        }

        void pushHead(int element) {
            if (this -> isFull())
                return;
            if (this -> head == 0)
                this -> head = this -> length;
            else
                this -> head -= 1;
            this -> arr[this -> head] = element;
            return;
        }

        void pushTail(int element) {
            if (this -> isFull())
                return;
            this -> arr[this -> tail] = element;
            this -> tail += 1;
            if (this -> tail == this -> length + 1)
                this -> tail = 0;
            return;
        }

        int popHead() {
            if (this -> isEmpty())
                return -1;
            int pop_element = this -> arr[this -> head];
            this -> head += 1;
            if (this -> head == this -> length + 1)
                this -> head = 0;
            return pop_element;
        }

        int popTail() {
            if (this -> isEmpty())
                return -1;
            if (this -> tail == 0)
                this -> tail = this -> length;
            else
                this -> tail -= 1;
            return this -> arr[this -> tail];
        }

        void print() {
            if (this -> isEmpty())
                return;
            if (this -> head < this -> tail) {
                for (int i = this -> head; i < this -> tail; ++i)
                    cout << this -> arr[i] << '\t';
                cout << endl;
                return;
            }
            for (int i = this -> head; i <= this -> length; ++i)
                cout << this -> arr[i] << '\t';
            for (int i = 0; i < this -> tail; ++i)
                cout << this -> arr[i] << '\t';
            cout << endl;
            return;
        }
};


