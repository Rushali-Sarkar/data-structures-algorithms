#include <iostream>

using namespace std;

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
