/* Problem Statement
 *
 * The ususal convention followed in mathematics is the infix expressin. Operations like + and * appear between the two operands
 * involved in the calculation:
 * 6 + 3 * 8 - 4
 *
 * Another convetion is the postfix expression, where the operators appear after the two operands involved in the expression. In
 * postfix, the expression written above will be presented as:
 *
 * 6 3 8 * + 4 -
 *
 * The two operands preceding an operator will be used with that operator.
 *
 * 1. From the first block of digits 6 3 8, we pick the last two which are 3 and 8.
 * 2. Reading the operators from left to right, the first one is *. The expression now becomes 3 * 8
 * 3. The next number is 6 while the next operator is +, so we have 6 + 8 * 3.
 * 4. The value of this expression is followed by 4, which is right before -. Hence we have 6 + 8 * 3 - 4.
 *
 * In this problem, you have to implement the int evaluatePostFix(string exp) function which will take a compute a postfix
 * expression given to it in a string. Your code should handle these four operators: +, - , *, /.
 *
 * Input
 *
 * A string containing a valid postfix mathematic expression. Each digit is considered a seperate number, i.e, there are no double-digit numbers.
 *
 * Output
 *
 * An integer result  of the given postfix expression.
 *
 * Sample Input
 *
 * "921*-8-4+"; // 9 - 2 * 1 - 8 + 4
 *
 * Sample Output
 *
 * 3
 */

#include<iostream>
#include<string>

using namespace std;

class myStack {

    private:
        int numElements;
        int front;
        int* arr;
        int capacity;

    public:

        myStack(int size) {
            capacity = size;
            arr = new int[capacity];
            front = -1;
            numElements = 0;
        }

        int getSize() {
            return numElements;
        }

        int getTop() {
            return arr[front];
        }

        void push(int value) {

            if (numElements == capacity) {
                cout << "The Stack is full" << endl;
                return;
            }

            numElements++;
            arr[++front] = value;
            return;
        }

        int pop() {

            if (numElements == 0) {
                cout << "The Stack is empty" << endl;
                return -1;
            }

            numElements--;
            return arr[front--];
        }

        void showStack() {
            for (int i = 0; i <= front; i++) 
                cout << arr[i] << '\t';
            cout << endl;
            return;
        }
};

char ADD = '+';
char SUBTRACT = '-';
char MULTIPLY = '*';
char DIVIDE = '/';

int evaluatePostFix (string exp) {

    myStack evaluate(exp.length());
    int result = 0;
    int operand1 = 0;
    int operand2 = 0;
    int number = 0;

    for (char element: exp) {

       

        if (element == ADD || element == SUBTRACT || element == MULTIPLY || element == DIVIDE) {
            
            operand2 = evaluate.pop();
            operand1 = evaluate.pop();

            if (element == ADD) 
                result = operand1 + operand2;

            else if (element == SUBTRACT)
               result = operand1 - operand2;

            else if (element == MULTIPLY)
               result = operand1 * operand2;

            else if (element == DIVIDE)
               result = operand1 / operand2;
           
           evaluate.push(result);
        }

        else {
           number = int(element) - int('0');
           evaluate.push(number);
        }
    }

   return evaluate.pop();
} 
        


int main() {
    cout << evaluatePostFix("921*-8-4+") << endl;
    return 0;
}
