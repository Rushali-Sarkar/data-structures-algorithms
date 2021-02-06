#include<iostream>
#include<vector>

using namespace std;

int min(int num1, int num2) {

    if (num1 <= num2)
        return num1;
    return num2;
}


int perfectSquareSum(int n) {


    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        dp[i] = i;
        for(int j = 1; j * j <= i; j++)
            dp[i] = min(dp[i - j * j] + 1, dp[i]);
    }

    return dp[n];
}

int main(int argc, char* argv[]) {

    cout << perfectSquareSum(13) << endl;
    return 0;
}

            
