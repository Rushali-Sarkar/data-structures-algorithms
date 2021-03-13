#include<iostream>
#include<vector>

using namespace std;

int coinChange(vector<int> coins, int sum) {

    vector<int> dp (sum + 1, 0);
    dp[0] = 1;

    for (auto each: coins) {

        for (int i = 1; i <= sum; i++) {
            if (i >= each)
                dp[i] = dp[i] + dp[i - each];
        }
    }

    return dp[sum];
}


int main(int argc, char* argv[]) {

    cout << coinChange(vector<int> {1, 2, 3}, 5) << endl;
    return 0;
}
