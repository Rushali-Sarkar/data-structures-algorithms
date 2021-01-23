#include<iostream>
#include<cmath>

using namespace std;

int perfectSquareSum(int n) {

    int x = sqrt(n);

    if (x * x == n)
        return 1;

    for (int i = 1; i * i <= n; i++) {

        int num1 = i * i;
        int num2 = n - num1;
        int y = sqrt(num2);
        if (y * y == num2)
            return 2;
    }

    while (n % 4 == 0)
        n = n / 4;

    if ((n - 7) % 8 == 0)
        return 4;

    return 3;
}

int main(int argc, char* argv[]) {

    cout << perfectSquareSum(13) << endl;
    return 0;
}
