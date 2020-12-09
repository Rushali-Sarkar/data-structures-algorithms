#include<iostream>
#include<vector>

using namespace std;

int greatestSubsetSum(vector<int> setofNumbers) {

    int currentMax = setofNumbers[0];
    int maxTillNow = setofNumbers[0];

    for (auto number: setofNumbers) {

        currentMax = max(maxTillNow, number);
        maxTillNow = max(maxTillNow, 0);
        maxTillNow = maxTillNow + number;
    }

    return 0;
}

