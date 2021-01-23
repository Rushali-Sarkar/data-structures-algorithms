#include <iostream>
#include <unordered_map>

using namespace std;


int nthfibonacci_helper(int n, unordered_map<int, int>& fibonacci_table) {

    if (fibonacci_table.find(n) != fibonacci_table.end())
        return fibonacci_table[n];

    fibonacci_table[n] = nthfibonacci_helper(n - 1, fibonacci_table) +  
                         nthfibonacci_helper(n - 2, fibonacci_table);
    return fibonacci_table[n];
}

int nthfibonacci(int n) {

    unordered_map<int, int> fibonacci_table;
    fibonacci_table[1] = 0;
    fibonacci_table[2] = 1;
    return nthfibonacci_helper(n, fibonacci_table);
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
