#include<iostream>
#include<vector>

using namespace std;

void doMerge(vector<int>& mainArray, int start_index, int middle_index, int end_index, vector<int>& auxiliaryArray) {

    int k = start_index;
    int i = start_index;
    int j = middle_index + 1;

    while (i <= middle_index && j <= end_index) {

        if (auxiliaryArray[i] <= auxiliaryArray[j])
            mainArray[k++] = auxiliaryArray[i++];

        else
            mainArray[k++] = auxiliaryArray[j++];

    }

    while (i <= middle_index)
        mainArray[k++] = auxiliaryArray[i++];

    while (j <= end_index)
        mainArray[k++] = auxiliaryArray[j++];

    return;
}

void mergeSortHelper(vector<int>& mainArray, int start_index, int end_index, vector<int>& auxiliaryArray) {

    if (start_index == end_index)
        return;

    
    int middle_index = (start_index + end_index) / 2;
    mergeSortHelper(auxiliaryArray, start_index, middle_index, mainArray);
    mergeSortHelper(auxiliaryArray, middle_index + 1, end_index, mainArray);
    doMerge(mainArray, start_index, middle_index, end_index, auxiliaryArray);
    return;
}

vector<int> mergeSort(vector<int> array) {

    if (array.size() <= 1) 
        return array;

    vector<int> auxiliaryArray = array;
    mergeSortHelper(array, 0, array.size() - 1, auxiliaryArray);
    return array;
}

void show(vector<int> arr) {

    for (int i = 0; i < arr.size(); i++) 
        cout << arr[i] << " ";
    cout << endl;
    return;
}


int main(int argc, char* argv[]) {

    vector<int> arr = {23, 2345,68, 19, 22, 11, 50, 1, 4, 7, 2, 35};
    arr = mergeSort(arr);
    show(arr);
    return 0;
}

