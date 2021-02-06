/* Problem Statement
 *
 * By definition, (a, b) and (c, d) are symmeteric pairs, if, a = d and b = c. In this problem, you have to
 * implement the string findSymmetric(int arr[][2], int size) function, which will find all the symmetric pairs
 * in the given array.
 *
 * Input
 *
 * A 2-D Array and the number of rows in the array.
 *
 * Note: The first value in the pair should be unique.
 *
 * Output
 *
 * A string containing all the symmetric pairs of integers in the input array.
 *
 * Sample Input
 *
 * 5
 * 3
 * 4
 * 1
 * 2
 * 5
 * 9
 * 4
 * 3
 * 9
 * 5
 *
 * Sample Output
 *
 * {4, 3}{3, 4}{9, 5}{5, 9}
 */


#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

string findSymmetric(int arr[][2], int size) {

    string result = "";
    unordered_map<int, int> findpairs;


    for (int i = 0; i < size; i++) {

        if (findpairs.find(arr[i][0]) != findpairs.end() && findpairs[arr[i][0]] == arr[i][1])
            result = result + 
                     "{" + to_string(arr[i][0]) + ", " + to_string(arr[i][1]) + "}" +
                     "{" + to_string(arr[i][1]) + ", " + to_string(arr[i][0]) + "}" ;

        else
            findpairs[arr[i][1]] = arr[i][0];
    }

    return result;
}

int main(int argc, char* argv[]) {

    int arr[][2] = {{3, 4}, {1, 2}, {5, 9}, {4, 3}, {9, 5}};
    string result = findSymmetric(arr, 5);

    cout << result << endl;
    return 0;
}

























