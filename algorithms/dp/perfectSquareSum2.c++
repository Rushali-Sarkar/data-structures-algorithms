#include<iostream>
#include<unordered_map>

using namespace std;


int min(int num1, int num2) {

    if (num1 <= num2)
        return num1;
    return num2;
}

int perfectSquareSum(int n, unordered_map<int, int>& memoize) {

    if (n == 0)
        return 0;

    if (memoize.find(n) != memoize.end())
        return memoize[n];

    int ans = n;
    for (int i = 1; i * i <= n; i++)
        ans = min(perfectSquareSum(n - i * i, memoize) + 1, ans);

    memoize[n] = ans;
    return memoize[n];
}

int main(int argc, char* argv[]) {

    unordered_map<int, int> memoize;
    cout << perfectSquareSum(13, memoize) << endl;

    return 0;
}
