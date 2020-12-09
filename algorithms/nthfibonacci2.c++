#include<iostream>
#include<unordered_map>

using namespace std;


int helper(int n, unordered_map<int, int> memoize) {

    if (memoize.find(n) != memoize.end())
        return memoize[n];

    memoize[n] = helper(n - 1, memoize) + helper(n - 2 , memoize);
    return memoize[n];

}


int nthfibonacci(int n) {

    unordered_map<int, int> memoize({{1, 0}, {2, 1}});
    return helper(n, memoize);

}

int main(int argc, char* argv[]) {

    for (int i = 1; i <= 30; i++)
        cout << nthfibonacci(i) << " ";
    cout << endl;
    return 0;
}

/* The space comlexity of the algorithm is O(n) since we are storing n number of function calls in the call stack each time
 * The time complexity of the algorithm is also O(n) since we are calculating each value only once we dont make function
 * calls for the same n twice.*/




