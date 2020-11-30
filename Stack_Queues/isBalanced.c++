/* Problem Statement
 *
 * In this problem, you have to implement the isBalanced() function which will take a string containing only {}, square[], and 
 * round () parantheses. The function tell us whether all the parantheses in the string are balanced or not.
 *
 * For all the paranthesis to be balanced, every opening parenthesis must have a closing one. The order in which they appear also 
 * matters. For example, {[]} is balanced, but {[}] is not.
 *
 * Input 
 *
 * A string consisting solely of (, ), {, }, [, and ]
 *
 * Output
 *
 * Returns false if the expression doesn't have balanced parantheses. If it does, the function returns true.
 *
 * Sample Input
 *
 * "{[({})]}"
 *
 *Sample Output
 * 
 * True
 */

#include<iostream>
#include<string>

using namespace std;

class Stack {

    private:
        int capacity;
        int numElements;
        int* arr;
        int top;

    public:
        Stack(int size) {
            capacity = size;
            arr = new int[capacity];
            numElements = 0;
            top = -1;
        }

        void push(int value) {

            if (numElements == capacity) {
                cout << "The Stack is full" << endl;
                return;
            }

            numElements++;
            arr[++top] = value;
            return;
        }

        int pop() {

            if (numElements == 0) {
                cout << "The Stack is empty" << endl;
                return -1;
            }

            numElements--;
            return arr[top--];
        }

        bool isEmpty() {
            return numElements == 0;
        }

        int getTop() {
            return arr[top];
        }
};

char BRACE_OPEN = '{';
char BRACE_CLOSE = '}';

char PARANTHESIS_OPEN = '(';
char PARANTHESIS_CLOSE = ')';

char BRACKET_OPEN = '[';
char BRACKET_CLOSE = ']';

bool isBalanced(string exp) {

    Stack balanced(exp.length());

    for (char symbol: exp) {

        if (symbol == BRACE_OPEN || symbol == PARANTHESIS_OPEN || symbol == BRACKET_OPEN)
            balanced.push(symbol);

        else if (symbol == BRACE_CLOSE && balanced.pop() != BRACE_OPEN)
            return false;

        else if (symbol == PARANTHESIS_CLOSE && balanced.pop() != PARANTHESIS_OPEN)
            return false;

        else if (symbol == BRACKET_CLOSE && balanced.pop() != BRACKET_OPEN)
            return false;
    }

    return true;
}

int main() {
    cout << isBalanced("{[()]}") << endl;
    cout << isBalanced("[{(}]") << endl;
    return 0;
}
