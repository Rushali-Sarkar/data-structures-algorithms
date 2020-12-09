#include<iostream>
#include<vector>

using namespace std;


vector<int> update(vector<int> waysTillTarget, int coin) {

    for (int i = 1; i < waysTillTarget.size(); i++) {

       if (i >= coin) 
          waysTillTarget[i] = waysTillTarget[i] + waysTillTarget[i - coin];

    }

   return waysTillTarget;
}


int numberofWaystomakeChange(vector<int> coindenominations, int target_sum) {

    vector<int> waysTilltarget (target_sum + 1, 0);
    waysTilltarget[0] = 1;

    for (auto coin: coindenominations) {

        if (coin > target_sum)
            continue;

        waysTilltarget = update(waysTilltarget, coin);
    }

    return waysTilltarget.back();
}



int main(int argc, char* argv[]) {

    vector<int> coindenominations = {1, 5, 10, 25};
    int coin = 10;

    cout << numberofWaystomakeChange(coindenominations, coin) << endl;
    return 0;
}


   


