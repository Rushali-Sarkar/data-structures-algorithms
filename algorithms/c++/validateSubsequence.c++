#include<iostream>
#include<vector>

using namespace std;

bool validatesubsequence(vector<int> sequence, vector<int> subsequence) {

    int sequence_index = 0;
    int subsequence_index = 0;

    while (sequence_index < sequence.size() && subsequence_index < subsequence.size()) {

        if (sequence[sequence_index] == subsequence[subsequence_index])
            subsequence_index++;

        sequence_index++;
    }

    return subsequence_index == subsequence.size();
}

int main(int argc, char* argv[]) {

    vector<int> sequence{5, 1, 22, 25, 6, -1, 8, 10};
    vector<int> subsequence{1, 6, -1, 10};

    cout << validatesubsequence(sequence, subsequence) << endl;
    return 0;
}
