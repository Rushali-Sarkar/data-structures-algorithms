/* Problem Statement
 *
 * Implement the following functions to implement two stacks using a single array to store elements. You can make changes to the
 * constructor as well.
 *
 * Function Prototypes
 *
 * void push1(int value);
 * void push2(int value);
 * void pop1();
 * void pop2();
 *
 * Input/Output
 *
 * push1(value)
 *
 * Input
 *
 * an integer
 *
 * Output
 * inserts the given value in the first stack, i.e., stack1
 *
 * push2(value)
 *
 * Input
 *
 * an integer
 *
 * Output
 * inserts the given value in the second stack, i.e., stack2
 *
 * pop1()
 *
 * Output
 * returns and removes the top of stack1
 *
 * pop2()
 * Output
 *
 * returns and removes the top value if stack2
 *
 */

#include<iostream>

using namespace std;


class twoStacks {

    private:

        int size;
        int* arr;
        int top1, top2;
    
    public:
   

        twoStacks(int n) {
            size =  n;
            arr = new int[2 * size];
            top1 = -1;
            top2 = n - 1;

        }

        void push1(int value) {

            if (top1 == size - 1) {
                cout << "Stack 1 is full" << endl;
                return;
            }

            arr[++top1] = value;
            return;
        }

        

        void push2(int value) {

            if (top2 == 2 * size - 1) {
                cout << "Stack 2 is full" << endl;
                return;
            }

            arr[++top2] = value;
            return;
        }

        int pop1() {

            if (top1 == -1) {
                cout << "Stack 1 is empty" << endl;
                return -1;
            }

            return arr[top1--];
        }

        int pop2() {
            if (top2 == size  - 1) {
                
                cout << "Stack 2 is empty" << endl;
                return -1;
            }

            return arr[top2--];
        }
};

int main() {
    twoStacks tS(5);
    tS.push1(11);
    tS.push1(3);
    tS.push1(7);
    tS.push2(1);
    tS.push2(9);

    cout << tS.pop1() << endl;
    cout << tS.pop2() << endl;
    cout << tS.pop2() << endl;
    cout << tS.pop2() << endl;
    cout << tS.pop1() << endl;

   return 0;
} 
