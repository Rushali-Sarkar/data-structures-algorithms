#include<iostream>


using namespace std;

int power(int n, int p) {

    int res = 1;

    while (p > 0) {

       if (p % 2 == 1) 
            res *= n;
        n *= n;
        p /= 2;
    }
    return res;
}

int main(int argc, char* argv[]) {


    cout << power(2, 2) << endl;
    cout << power(2, 5) << endl;
    cout << power(4, 7) << endl;
    cout << power(10, 4) << endl;
    return 0;
}
