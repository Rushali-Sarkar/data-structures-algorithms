#include<iostream>
#include<vector>
#include <algorithm> 

using namespace std;

int min_attempts(int eggs, int floors) {


    vector<vector<int>> dp (eggs + 1, vector<int> (floors + 1, 0));

    for (int i = 1; i <= floors; i++)
        dp[1][i] = i;


    for (int i = 2; i <= eggs; i++) {

        for (int j = 1; j <= floors; j++) {
            
            vector<int> maxes;

           for (int k = 1; k <= j; k++) 
                maxes.push_back(max(dp[i - 1][k - 1], dp[i][j - k]));

            dp[i][j] = 1 + *min_element(maxes.begin(), maxes.end());
       
        }
    }
    return dp[eggs][floors];
}


int main(int argc, char* argv[]) {

    int eggs = 3;
    int floors = 13;

    cout << min_attempts(eggs, floors) << endl;

    return 0;
}

