#include<iostream>
#include<vector>

using namespace std;

void show(vector<int> arr) {
    for (auto each: arr)
        cout << each << " ";
    cout << endl;
    return;
}

int change(int amount, vector<int>& coins) {
    
    vector<int> dp_table (amount + 1, 0);
    vector<int> current (amount + 1, 0);
    dp_table[0] = 1;
    
    for (auto coin: coins) {

        show(dp_table);
        for (int i = 1; i <= amount; i++) {
            if (coin <= i)
                dp_table[i] = dp_table[i] + dp_table[i - coin];
        }
    }

    show(dp_table);
    return dp_table[amount];        
}

int main(int argc, char* argv[]) {
    
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    change(amount, coins);

    return 0;
}

