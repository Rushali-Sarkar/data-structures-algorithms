#include<iostream>
#include<vector>

using namespace std;

int longestIncreasingSubsequence(vector<int> sequence) {

    int size = sequence.size();
    int max_till_now = 1;
    int index_of_max = 0;
    
    vector<int> lengths (size, 1);
    vector<int> sequences (size, -1);

    for (int i = 0; i < size; i++) {
        
        int ending_element = sequence[i];

        for (int j = 0; j < i; j++) {
            
            if (sequence[j] < ending_element) {
                
                if (lengths[j] + 1 >= lengths[i]) {
                   lengths[i] = lengths[j] + 1;
                   sequences[i] = j; 
                }
            }
        }

        if (lengths[i] >= max_till_now) {
            max_till_now = lengths[i];
            index_of_max = i;
        }
    }

    vector<int> subsequences;

    while (index_of_max != -1) {

        subsequences.push_back(sequence[index_of_max]);
        index_of_max = sequences[index_of_max];
    }

    for (auto elements: subsequences)
        cout << elements << "\t";
    cout << endl;

    return max_till_now;
}


int main(int argc, char* argv[]) {
    
    vector<int> sequence{5, 7, -24, 12, 10, 2, 3, 12, 5, 6, 35};
    cout << longestIncreasingSubsequence(sequence) << endl;

    return 0;
}

