#include<iostream>
#include<vector>

using namespace std;

bool validatesubsequence(vector<int> sequence, vector<int> subsequence) {

    int subsequence_index = 0;

    for (auto element: sequence) {

        if (element == subsequence[subsequence_index])
            subsequence_index++;

        if (subsequence_index == subsequence.size())
            return true;
    }

    return false;
}

int main(int argc, char* argv[]) {

    vector<int> sequence{5, 1, 22, 25, 6, -1, 8, 10};
    vector<int> subsequence{1, 6, -1, 10};

    cout << validatesubsequence(sequence, subsequence) << endl;
    return 0;
}
