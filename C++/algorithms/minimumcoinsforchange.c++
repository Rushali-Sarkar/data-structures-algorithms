#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;


vector<int> update(vector<int> changeTillTarget, int coin) {

    for (int i = 1; i < changeTillTarget.size(); i++) {

        if (coin <= i)
            changeTillTarget[i] = min(changeTillTarget[i], (1 + changeTillTarget[i - coin]));

    }

    return changeTillTarget;
}

int minimumChanges(vector<int> coindenominations, int target_sum) {

    vector<int> changeTillTarget (target_sum + 1, INT_MAX);
    changeTillTarget[0] = 0;

    for (int coin: coindenominations) 
        changeTillTarget = update(changeTillTarget, coin);

    return changeTillTarget.back();
}

int main(int argc, char* argv[]) {

    vector<int> coindenominations = {1, 2, 4};
    int target_sum = 6;

    cout << minimumChanges(coindenominations, target_sum) << endl;
    return 0;
}

