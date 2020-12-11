#include<iostream>
#include<vector>

using namespace std;


int getNextIndex(int currentIndex, vector<int> arr) {

    int size = arr.size();
    int nextIndex = currentIndex + arr[currentIndex];

    if (nextIndex >= size)
        nextIndex = nextIndex % size;

    else if (nextIndex < 0) 
        nextIndex = size - (abs(nextIndex) % size);


   return nextIndex;
}

bool singleCycleCheck(vector<int> arr) {

    int current_index = 0;
    int number_of_elements_visited = 0;

    while (number_of_elements_visited < arr.size()) {

        if (number_of_elements_visited > 0 && current_index == 0)
            return false;

        number_of_elements_visited += 1;
        current_index = getNextIndex(current_index, arr);
    }

    return current_index == 0;
}


int main(int argc, char* argv[]) {

    vector<int> arr = {2, 3, 1, -4, -4, 2};

    cout << singleCycleCheck(arr) << endl;

    return 0;
}

