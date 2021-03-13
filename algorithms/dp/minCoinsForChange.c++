#include<iostream>
#include<vector>

using namespace std;

int minCoins(vector<int> coins, int target) {

    int size = coins.size();
    vector<int> dp(size + 1, 0);

    for (int i = 0; i <= size; i++)
        dp[i] = i;

    for (auto elements: coins) {

        for (int i = 1; i <= size; i++) {
            
            if (elements <= i)
                dp[i] = min(dp[i], 1 + dp[i - elements]);
        }
    }

    return dp[size];
}

int main(int argc, char* argv[]) {

    vector<int> arr{1, 2, 4};
    int target = 6;

    cout << minCoins(arr, target) << endl;

    return 0;
}

