#include<iostream>
#include<cmath>

using namespace std;

int perfectSquareSum(int n) {
     
    if (n == 0)
        return 0;

    if (n <= 3)
        return n;
    
    int x = sqrt(n);
    if (x * x == n)
        return 1;

    return perfectSquareSum(n - (x * x)) + 1;
}

int main(int argc, char* argv[]) {
    cout << perfectSquareSum(13) << endl;
    return 0;
}
