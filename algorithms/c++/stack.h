#include<iostream>

using namespace std;


class Stack {

    public:

        int top;
        int size;
        int* arr;

        Stack(int size) {
            this -> size = size;
            this -> top = -1;
            this -> arr = new int[this -> size];
        }

        bool isEmpty() {
            return this -> top == -1;
        }

        int front() {

            if (isEmpty())
                return -1;

            return this -> arr[this -> top];
        }

        void push(int item) {

            if (this -> top == this -> size - 1)
                return;

            this -> arr[++(this -> top)] = item;
            return;
        }

        void pop() {

            if (isEmpty())
                return;
            (this -> top)--;
            return;
        }

};




