#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

vector<int> twonumbersum(vector<int> arr, int sum) {


    unordered_set<int> possiblematch;

    for (auto element: arr) {

        int potential_match = sum - element;
        if (possiblematch.find(potential_match) != possiblematch.end())
            return vector<int> {element, potential_match};
        else
            possiblematch.insert(element);
    }

    return vector<int> {-1, -1};
}

int main(int argc, char* argv[]) {

    vector<int> arr = {3, 5, -4, 8, 11, 8, 1, 1, -1, 6};
    int sum = 10;
    vector<int> result = twonumbersum(arr, sum);
    cout << "[ " << result[0] << " , " << result[1] << " ]" << endl;
    return 0;
} 

/* This algorithm takes a time complexity of O(n) since the array is traveresed just once 
 * It take a space complecity of O(n) since there is a hash table involved which is being used and saved in this process and
 * which can contain atmost n elements.*/
