#include <iostream>

using namespace std;

class TwoStack {

    private:
        int top1;
        int top2;
        int n;
        int* arr;

    public:
        TwoStack() {
            this -> top1 = -1;
            this -> top2 = 0;
            this -> n = 0;
            this -> arr = new int(this -> n);
        }

        TwoStack(int n) {
            this -> top1 = -1;
            this -> top2 = n;
            this -> n = n;
            this -> arr = new int(this -> n);
        }

        bool isEmpty1() {
            return this -> top1 == -1;
        }

        bool isEmpty2() {
            return this -> top2 == this -> n;
        }

        bool isFull() {
            return this -> top2 == this -> top1 + 1;
        }

        void push1(int element) {
            if (this -> isFull())
                return;
            this -> top1 += 1;
            this -> arr[this -> top1] = element;
            return;
        }

        void push2(int element) {
            if (this -> isFull())
                return;
            this -> top2 -= 1;
            this -> arr[this -> top2] = element;
            return;
        }

        int pop1() {
            if (this -> isEmpty1())
                return -1;
            int pop_element = this -> arr[this -> top1];
            this -> top1 -= 1;
            return pop_element;
        }

        int pop2() {
            if (this -> isEmpty2())
                return -1;
            int pop_element = this -> arr[this -> top2];
            this -> top2 += 1;
            return pop_element;
        }

        int peek1() {
            if (this -> isEmpty1())
                return -1;
            return this -> arr[this -> top1];
        }

        int peek2() {
            if (this -> isEmpty2())
                return -1;
            return this -> arr[this -> top2];
        }

        void print1() {
            if (this -> isEmpty1())
                return;
            for (int i = 0; i <= this -> top1; ++i)
                cout << this -> arr[i] << '\t';
            cout << endl;
            return;
        }

        void print2() {
            if (this -> isEmpty2())
                return;
            for (int i = this -> n - 1; i >= this -> top2; --i)
                cout << this -> arr[i] << '\t';
            cout << endl;
        }

};
