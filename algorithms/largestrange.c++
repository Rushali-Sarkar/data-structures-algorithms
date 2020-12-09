#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> longestrange(vector<int> arr) {

    int longest_range = 1;
    int start_index = 0;
    int end_index   = 0; 

    for (int i = 1; i < arr.size(); i++) {

        int possible_longest_range = 1;
        int s = i - 1;
        int e   = i - 1; 
      
        while (arr[i - 1] + 1 == arr[i]) {            
            possible_longest_range++;
            e = i;
            i++;
        }

        if (possible_longest_range > longest_range) {
            longest_range     = possible_longest_range;
            start_index = s;
            end_index = e;
        }
    }

    return vector<int> {start_index, end_index};

}

int main(int argc, char* argv[]) {

    vector<int> arr = {1, 11, 3, 0, 15, 5, 2, 4, 0, 7, 12, 6};
    sort(arr.begin(), arr.end());
    vector<int> result = longestrange(arr);

    for (int i = result[0]; i <= result[1]; i++) 
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
