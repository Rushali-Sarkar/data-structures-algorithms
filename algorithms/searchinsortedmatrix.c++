#include<iostream>
#include<vector>

using namespace std;


vector<int> indexofTarget(vector<vector<int>> arr, int target) {

    int row = 0;
    int column = arr[0].size() - 1;

    while (row < arr.size() && column >= 0) {

        if (target < arr[row][column])
            column--;

        else if (target > arr[row][column])
            row++;

        else
            return vector<int> {row, column};
    }

    return vector<int> {-1, -1};

}


int main(int argc, char* argv[]) {

    vector<vector<int>> arr = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 18, 20}};
    int rows = 4;
    int columns = 5;

    vector<int> result1 = indexofTarget(arr, 11);
    vector<int> result2 = indexofTarget(arr, 7);
    vector<int> result3 = indexofTarget(arr, 2);

    cout << "Index of 11 : " << result1[0] << " " << result1[1] << " (2, 0) " << endl;
    cout << "Index of 7  : " << result2[0] << " " << result2[1] << " (1, 1) " << endl;
    cout << "Index of 8  : " << result3[0] << " " << result3[1] << " (0, 1) " << endl;

    return 0;
}

    
