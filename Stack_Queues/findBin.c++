/* Problem Statement
 *
 * Implement a function string* findBin(int n) which will generate binary numbers from 11 to nn stored in an array of type string
 * by making use of queue.
 *
 * Input
 *
 * A positive integer n
 *
 * Output
 *
 * An array of type string (result) containing binary  numbers from 1 up to n
 *
 * Sample Input
 *
 * 3
 *
 * Sample Output
 *
 * {"1", "10", "11"}
 *
 * An illustration is also provided for your understanding.
 */

#include<iostream>
#include<cstdlib>
#include<cassert>
#include<string>

using namespace std;

class myQueue {
    public:
        int capacity;
        int* queueArr;
        int front;
        int back;
        int numElements;

       
        myQueue(int size) {
            capacity = size;
            queueArr = new int[size];
            assert( queueArr != NULL);
            numElements = 0;
            front = 0;
            back = -1;
        }

        bool isEmpty() {
            return (numElements == 0);
        }

        int getFront() {
            if (isEmpty()) {
                cout << "Queue Empty" << endl;
                return -1;
            }
            else 
                return queueArr[front];
            return 0;
        }

        void enqueue(int value) {
            if (numElements == capacity) {
                cout << "Queue Full" << endl;
                return;
            }

            if (back == capacity - 1)
                back = -1;

            queueArr[++back] = value;
            numElements++;
        }

        int dequeue() {
            if (isEmpty()) {
                cout << "Queue Empty" << endl;
                return -1;
            }
            int temp = queueArr[front++];

            if (front == capacity)
                front = 0;
            numElements--;
            return temp;
        }

        int getSize() {
            return numElements;
        }

        void showqueue() {
            int i = front;
            int count = 0;
            while (count != numElements) {
                cout << '\t' << queueArr[i % capacity];
                i++;
                count++;
            }
            cout << endl;
        }

        string findBin(int n);
};
            



string* findBin(int n) {

    string* binary = new string[n + 1];
    int counter = 1;
    binary[0] = "1";
    string element = "";

    myQueue binaryqueue(n + 1);

    binaryqueue.enqueue(stoi("1"));
    while (counter < n) {

        element = to_string(binaryqueue.dequeue());
        string first = element + "0";
        string second = element + "1";
        binary[counter++] = first;
        binary[counter++] = second;
        binaryqueue.enqueue(stoi(first));
        binaryqueue.enqueue(stoi(second));
    }

    return binary;
}


int main() {
    auto output = findBin(4);
    for (int i = 0; i < 4; i++)
        cout << output[i] <<  " ";
    cout << endl;
}
