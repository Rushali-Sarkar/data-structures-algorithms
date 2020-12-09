#include<unordered_set>
#include<iostream>

using namespace std;

bool isSubset(int* arr1, int* arr2, int size1, int size2) {

    unordered_set<int> powerset;
    
    for (int i = 0; i < size1; i++) 
        powerset.insert(arr1[i]);

    for (int i = 0; i < size2; i++) {

        if (powerset.find(arr2[i]) == powerset.end())
            return false;
    }

    return true;
}

int main(int argc, char* argv[]) {

    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {3, 4, 5};

    int arr3[] = {3, 4, 5, 6};

    cout << isSubset(arr1, arr2, 5, 3) << endl;
    cout << isSubset(arr1, arr3, 5, 4) << endl;

    return 0;
}

