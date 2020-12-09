#include<iostream>
#include<vector>

using namespace std;


vector<vector<int>> getUnvisitedNeighbours(int i, int j, vector<vector<int>> matrix, vector<vector<int>>& visited) {

    vector<vector<int>> unvisitedneighbours;
    int columnlength = matrix.size();
    int rowlength = matrix[i].size();

    if ((i + 1) < columnlength && !visited[i + 1][j])
      unvisitedneighbours.push_back({i + 1, j});

    if ((i - 1) >= 0 && !visited[i - 1][j])
         unvisitedneighbours.push_back({i - 1, j});

    if ((j + 1) < rowlength && !visited[i][j + 1])
         unvisitedneighbours.push_back({i, j + 1});

    if ((j - 1) >= 0 && !visited[i][j - 1])
         unvisitedneighbours.push_back({i, j - 1});

    return unvisitedneighbours;
}


void traversenode(int i, int j, vector<vector<int>> matrix, vector<vector<int>>& visited, vector<int>& sizes) {
    int currentRiverSize = 0;
    vector<vector<int>> nodesToExplore;
    nodesToExplore.push_back({i, j});

    while (nodesToExplore.size() != 0) {

        vector<int> currentNode = nodesToExplore.back();
        nodesToExplore.pop_back();

        i = currentNode[0];
        j = currentNode[1];
        if (visited[i][j])
            continue;

        visited[i][j] = true;
        if (matrix[i][j] == 0)
            continue;

        currentRiverSize = currentRiverSize + 1;
        vector<vector<int>> unvisitedNeighbours = getUnvisitedNeighbours(i, j, matrix, visited);

        for (auto neighbours: unvisitedNeighbours)
            nodesToExplore.push_back(neighbours);
    }

    if (currentRiverSize > 0) 
        sizes.push_back(currentRiverSize);

    return;
}

vector<int> riverSizes(vector<vector<int>> matrix) {

    vector<int> sizes;
    vector<vector<int>> visited(matrix.size(), vector<int>(matrix[0].size(), false));

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {

            if (visited[i][j]) 
                continue;

            traversenode(i, j, matrix, visited, sizes);
        }
    }

    return sizes;
}


int main(int argc, char* argv[]) {

    vector<vector<int>> matrix = {{1, 0, 0, 1, 0}, {1, 0, 1, 0, 0}, {0, 0, 1, 0, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 0}};
    vector<int> sizes = riverSizes(matrix);
    for (auto size: sizes)
        cout << size << " ";
    cout << endl;

    return 0;
}
