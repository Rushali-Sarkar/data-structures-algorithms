#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<vector<int>> initialiseHelperArray(vector<vector<int>> arr, int rows, int columns) {
    
    for (int i = 0; i < columns; i++) 
        arr[0].push_back(i);

    for (int i = 1; i < rows; i++)
        arr[i].push_back(i);

    return arr;
}


void show(vector<vector<int>> arr) {

    for (int i = 0; i < arr.size(); i++ ) {
        for (int j = 0; j < arr[i].size(); j++) 
            cout << arr[i][j] << '\t';
        cout << endl;
    }

    return;
}

int levenshteindistance(string str1, string str2) {

    int rows = str1.length() + 1;
    int columns = str2.length() + 1;

    vector<vector<int>> referenceArray(rows, vector<int>(0, 0));
    referenceArray = initialiseHelperArray(referenceArray, rows, columns);

    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < columns; j++) {

            if (str1[i - 1] == str2[j - 1])
                referenceArray[i][j] = referenceArray[i - 1][j - 1];

            else
                referenceArray[i][j] = 1 + min(min(referenceArray[i - 1][j] , referenceArray[i][j-1]),  
                        referenceArray[i - 1][j - 1]);
        }
    }

    return referenceArray[rows - 1][columns - 1];
}

int main(int argc, char* argv[]) {

    string str1 = "abc";
    string str2 = "yabd";

    cout << levenshteindistance(str1, str2) << endl;
    return 0;
}







