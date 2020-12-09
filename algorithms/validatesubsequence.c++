#include<iostream>
#include<vector>

using namespace std;

bool validateSubsequence(vector<int> sequence, vector<int> subsequence) {

    int start_sequence = 0;
    int start_subsequence = 0;
    int end_sequence = sequence.size();
    int end_subsequence = subsequence.size();

    while (start_sequence < end_sequence && start_subsequence  < end_subsequence) {

        if (sequence[start_sequence] == subsequence[start_subsequence]) 
            start_subsequence++;

        start_sequence++;

    }

    return start_subsequence == end_subsequence;
}

int main(int argc, char* argv[]) {

    vector<int> sequence = {5, 1, 22, 25, 6, -1, 8, 10};
    vector<int> subsequence = {1, 6, -1, 10};
    cout << validateSubsequence(sequence, subsequence) << endl;
    return 0;
}

/* The time complexity of this algorithm is O(n) since it is atmost traversing the sequence array completely.
 * The space complecity is O(1) since there is no significant extra use of space for the purpose of computing the result.
 */
