#include<bits/stdc++.h>

using namespace std;

void show(unordered_map<int, int> freq) {
    for (auto each: freq) 
        cout << each.first << ": " << each.second << endl;
    return;
}

int countSpecials(int arr[], int sizeof_array, int K) {
    
    int f = floor(sizeof_array/K);
    cout << f << endl;
    unordered_map<int, int> frequencies;
    int count = 0;
    
    for (int i = 0; i < sizeof_array; i++)
       frequencies[arr[i]] += 1;
    
    for (auto each: frequencies) {

        if (each.second == f)
            count += 1;
    }

    show(frequencies);
    
 return count;
}

int main(int argc, char* argv[]) {

    int arr[] = {1, 4, 1, 2, 4};
    int n = 5;
    int k = 2;
    cout << countSpecials(arr, n, k) << endl;
    return 0;

}

