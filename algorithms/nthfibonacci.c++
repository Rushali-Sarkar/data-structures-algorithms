#include<iostream>

using namespace std;

int nthfibonacci(int n) {

    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    return nthfibonacci(n - 1) + nthfibonacci(n - 2);
}

int main(int argc, char* argv[]) {

    for (int i = 1; i <= 30; i++) 
        cout << nthfibonacci(i) << " ";
    cout << endl;
    return 0;
}

/* The time complexity of this algorithm is O(2^n), since everytime we call two other times.
 * The space complecity of this algorithm is O(n), since at every call there is one layer added to call stack till n
 * and something is returned.*/
