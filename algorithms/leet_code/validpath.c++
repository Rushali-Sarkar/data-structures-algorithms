#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void show(vector<vector<int>> nums) {

    for (auto element: nums) {
        for (auto each: element)
            cout << each << " ";
        cout << endl;
    }

    return;
}

vector<vector<int>> makePath(vector<vector<int>> grid) {

    int rows = grid.size();
    int columns = grid[0].size();

    int path_row = 1;
    int path_column = 1;

    vector<vector<int>> path(3 * rows, vector<int>(3 * columns, 0));

    for (auto element: grid) {

        path_column = 1;
        for (auto each: element) {

            path[path_row][path_column] = 1;

            if (each == 1) {

                path[path_row][path_column - 1] = 1;
                path[path_row][path_column + 1] = 1;

            }

            if (each == 2) {

                path[path_row + 1][path_column] = 1;
                path[path_row - 1][path_column] = 1;

            }

            if (each == 3) {

                path[path_row][path_column - 1] = 1;
                path[path_row + 1][path_column] = 1;

            }

            if (each == 4) {

                path[path_row + 1][path_column] = 1;
                path[path_row][path_column + 1] = 1;

            }

            if (each == 5) {

                path[path_row][path_column - 1] = 1;
                path[path_row - 1][path_column] = 1;

            }

            if (each == 6) {

                path[path_row - 1][path_column] = 1;
                path[path_row][path_column + 1] = 1;

            }

            path_column += 3;
        }

        path_row += 3;
    }

    return path;
}

bool hasValidPath(vector<vector<int>> path) {

    int row = path.size();
    int column = path[0].size();

    queue<vector<int>> tracking;
    tracking.push({1, 1});
    while (!tracking.empty()) {
        int levelsize = tracking.size();
        for (int i = 1; i <= levelsize; i++) {
            int valid_row = tracking.front()[0];
            int valid_column = tracking.front()[1];

            path[valid_row][valid_column] = 0;

            if (valid_row == row - 2 && valid_column == column - 2)
                return true;
            tracking.pop();

            bool nextRowExsist = valid_row + 1 >= 0 && valid_row + 1 < row;
            bool previousRowExsist = valid_row - 1 >= 0 && valid_row - 1 < row;
            bool nextColumnExsist = valid_column + 1 >= 0 && valid_column + 1 < column;
            bool previousColumnExsist = valid_column - 1 >= 0 && valid_column - 1 < column;

            if (previousColumnExsist) {
                if (path[valid_row][valid_column - 1] == 1)
                    tracking.push({valid_row, valid_column - 1});
            }

             if (nextColumnExsist) {
                if (path[valid_row][valid_column + 1] == 1)
                    tracking.push({valid_row, valid_column + 1});
            }

             if (previousRowExsist) {
                if (path[valid_row - 1][valid_column] == 1)
                    tracking.push({valid_row - 1, valid_column});
            }

             if (nextRowExsist) {
                if (path[valid_row + 1][valid_column] == 1)
                    tracking.push({valid_row + 1, valid_column});
            }

        }
    }
    return false;
}




int main(int argc, char* argv[]) {

    vector<vector<int>> arr1 = {{2, 4, 3}, {6, 5, 2}};
    vector<vector<int>> path1 = makePath(arr1);
    show(path1);
    cout << endl;
    cout << hasValidPath(path1) << endl;

    vector<vector<int>> arr2 = {{1, 2, 1}, {1, 2, 1}};
    vector<vector<int>> path2 = makePath(arr2);
    show(path2);
    cout << endl;
    cout << hasValidPath(path2) << endl;

    vector<vector<int>> arr3 = {{1, 1, 2}};
    vector<vector<int>> path3 = makePath(arr3);
    show(path3);
    cout << endl;
    cout << hasValidPath(path3) << endl;


    vector<vector<int>> arr4 = {{1, 1, 1, 1, 1, 1, 3}};
    vector<vector<int>> path4 = makePath(arr4);
    show(path4);
    cout << endl;
    cout << hasValidPath(path4) << endl;

    vector<vector<int>> arr5 = {{2}, {2}, {2}, {2}, {2}, {2}, {6}};
    vector<vector<int>> path5 = makePath(arr5);
    show(path5);
    cout << endl;
    cout << hasValidPath(path5) << endl;
    return 0;
}

