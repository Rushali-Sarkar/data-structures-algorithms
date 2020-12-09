#include<iostream>
#include<vector>

using namespace std;


vector<int> spiraltraverse(vector<vector<int>> matrix) {

    int begin_row = 0;
    int begin_column = 0;
    int end_row = matrix.size() - 1;
    int end_column = matrix[0].size() - 1;
    int i = 0;
    int j = 0;

    vector<int> traversed;

    while (begin_row <= end_row && begin_column <= end_column) {

        for (int column = begin_column; column <= end_column; column++)
            traversed.push_back(matrix[begin_column][column]);
     
        for (int row = begin_row + 1; row <= end_row; row++)
            traversed.push_back(matrix[row][end_row]);
        
        for (int column = end_column - 1; column >= begin_column; column--)
            traversed.push_back(matrix[end_column][column]);

        for (int row = end_row - 1; row > begin_row; row--)
             traversed.push_back(matrix[row][begin_row]);

        begin_column++;
        begin_row++;
        end_row--;
        end_column--;
    }
    return traversed;
}

int main(int argc, char* argv[]) {

    vector<vector<int>> arr = {{1, 2, 3, 4}, {12, 13, 14, 5}, {11, 16, 15, 6}, {10, 9, 8, 7}};
    vector<int> traversed = spiraltraverse(arr);
    for (auto element: traversed)
        cout << element << " ";
    cout << endl;
    return 0;
}
