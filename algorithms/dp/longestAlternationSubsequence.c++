#include<iostream>
#include<vector>

using namespace std;


int longestAlternatingSubsequence(vector<int> sequence) {

    int size = sequence.size();
    int result = 1;
    
    vector<int> last_greater (size, 1);
    vector<int> last_smaller (size, 1);

    for (int i = 1; i < size; i++) {

        for (int j = 0; j < i; j++) {

            if (sequence[i] < sequence[j]) {
                if (last_smaller[i] < last_greater[j] + 1) 
                    last_smaller[i] = last_greater[j] + 1;
            }

            if (sequence[i] > sequence[j]) {
                if (last_greater[i] < last_smaller[j] + 1) 
                    last_greater[i] = last_smaller[j] + 1;
            }
        }

        if (result < max(last_greater[i], last_smaller[i]))
            result = max(last_greater[i], last_greater[i]);
    }

    return result;
}

int main(int argc, char* argv[]) {

    vector<int> sequence {10, 22, 9, 33, 49, 50, 31, 60};
    cout << longestAlternatingSubsequence(sequence) << endl;

    return 0;
}




