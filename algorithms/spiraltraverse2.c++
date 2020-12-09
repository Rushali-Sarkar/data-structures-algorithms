#include<iostream>
#include<vector>

using namespace std;


void helptraverse(vector<vector <int>> matrix, vector<int>& traversed,
                    int begin_row, int end_row,
                    int begin_column, int end_column) {

    if (begin_row > end_row || begin_column > end_column)
        return;

    for (int row = begin_row; row <= end_row; row++)
        traversed.push_back(matrix[begin_row][row]);

    for (int column = begin_column + 1; column <= end_column; column++)
        traversed.push_back(matrix[column][end_column]);

    for (int row = end_row - 1; row >= begin_row; row--)
        traversed.push_back(matrix[end_row][row]);

    for (int column = end_column - 1; column > begin_column; column--)
        traversed.push_back(matrix[column][begin_column]);

    return helptraverse(matrix, traversed, begin_row + 1, end_row - 1, begin_column + 1, end_column - 1);
}


vector<int> spiraltraverse(vector<vector<int>> matrix) {

    vector<int> traversed;
    helptraverse(matrix, traversed, 0, matrix.size() - 1, 0, matrix[0].size() - 1);
    return traversed;
}

int main(int argc, char* argv[]) {

    vector<vector<int>> matrix = {{1, 2, 3, 4}, {12, 13, 14, 5}, {11, 16, 15, 6}, {10, 9, 8, 7}};
    vector<int> traversed = spiraltraverse(matrix);
    for (auto number: traversed)
        cout << number << " ";
    cout << endl;
    return 0;
}
