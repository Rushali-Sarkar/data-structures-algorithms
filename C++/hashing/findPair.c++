/* Problem Statement
 *
 * In this problem, you have to implement the string findPair(int* arr, int size)function, which will find two
 * pairs[a, b] and [c, d] in an array such that:
 *
 * a + b = c + d
 *
 * You have to find any two pairs in the array which satisfies the above condition.
 *
 * Input
 *
 * An array of distince integers and their size.
 *
 * Output 
 *
 * A string containing two pairs(a, b) and (c, d) which satisfy a + b = c + d in {a, b}{c, d} format
 *
 * Input = 6
 * 3
 * 4
 * 7
 * 1
 * 12
 * 9
 *
 * Output = {{4, 12},{7, 9}}
 */



#include<unordered_map>
#include<iostream>
#include<string>
#include<vector>

using namespace std;


string findPair(int* arr, int size) {

    unordered_map<int, vector<int>> sum_pairs;
    string result;

    for (int i = 0; i < size; i++) {
        int a = arr[i];
        for (int j = i + 1; j < size; j++) {
            int b = arr[j];

            if (sum_pairs.find((a + b)) != sum_pairs.end()) {
                vector<int> other_pair = sum_pairs[(a + b)];
                int c = other_pair[0];
                int d = other_pair[1];
                return ("{{" + to_string(c) + ", " + to_string(d) + "}{" + to_string(a) + ", " + to_string(b) +  "}}");
            }

            else 
                sum_pairs[(a + b)] = {a, b};
        }
    }

    return "Such a Pair not Found";

}

int main(int argc, char* argv[]) {

    int arr[] = {3, 4, 7, 1, 12, 9};
    int size = 6;
    cout << findPair(arr, size) << endl;
    return 0;
}
                



