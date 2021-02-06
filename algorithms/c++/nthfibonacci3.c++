#include<iostream>

using namespace std;

int nthfibonacci(int n) {

    if (n == 1)
        return 0;

    if (n == 2)
        return 1;

    int fibonacci_arr[] = {0, 1};

    for (int i = 1; i < n - 1; i++) {
        
        int sum = fibonacci_arr[0] + fibonacci_arr[1];
        fibonacci_arr[0] = fibonacci_arr[1];
        fibonacci_arr[1] = sum;
    }

    return fibonacci_arr[1];
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
