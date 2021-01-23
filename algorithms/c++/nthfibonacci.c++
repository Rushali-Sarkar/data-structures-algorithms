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

    cout << nthfibonacci(6) << endl;
    cout << nthfibonacci(5) << endl;
    cout << nthfibonacci(4) << endl;
    cout << nthfibonacci(3) << endl;
    cout << nthfibonacci(2) << endl;
    cout << nthfibonacci(1) << endl;
    return 0;
}
