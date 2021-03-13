#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


vector<vector<int>> threenumbersum(vector<int> numbers, int sum) {

    vector<vector<int>> result;
    sort(numbers.begin(), numbers.end());
    for (int i = 0; i < numbers.size() - 2; i++) {
        
        int first_number = numbers[i];
        int left = i + 1; 
        int right = numbers.size() - 1;

        while (left < right) {

            int second_number = numbers[left];
            int third_number = numbers[right];
            int target_sum = sum - first_number; 

            if ((second_number + third_number) == target_sum) {
                result.push_back({first_number, second_number, third_number});
                right--;
                left++;
            }

            else if (target_sum > (second_number + third_number)) 
                left++;

            else
                right--;

           
        }
    }

    return result;
}

int main(int argc, char* argv[]) {

    vector<int> numbers = {-8, -6, 1, 2, 3, 5, 6, 12};
    vector<vector<int>> result = threenumbersum(numbers, 0);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << '\t';
        cout << endl;
    }

    return 0;
}

