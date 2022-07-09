#include <iostream>
#include <vector>

using namespace std;

bool linearSearch (vector<int>& arr, int& target) {
        for (auto each: arr) {
                if (each == target)
                        return true;
        }
        return false;
}

int main(int argc, char* argv[]) {
        vector<int> arr = {1, 4, 20, 304, 20, 10, 20, 39, 56, 78, 99, 100, 23, 4, 5};
        int target1 = 39;
        int target2 = 25;
        cout << linearSearch(arr, target1) << endl;
        cout << linearSearch(arr, target2) << endl;
        return 0;
}


