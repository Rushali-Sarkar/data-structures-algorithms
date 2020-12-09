#include<iostream>
#include<vector>

using namespace std;

void doMerge(vector<int>* mainArray, int start_index, int middle_index, int end_index, vector<int>* auxilliaryArray) {

    int i = start_index;
    int j = start_index;
    int k = middle_index + 1;

    while (i <= middle_index && k <= end_index) {

        if (auxilliaryArray -> at(i) <= auxilliaryArray -> at(k) )
           mainArray -> at(j++)  = auxilliaryArray -> at(i++) ;

        else
            mainArray -> at(j++)  = auxilliaryArray -> at(k++) ;
    }

    while (i <= middle_index)
        mainArray -> at(j++)  = auxilliaryArray -> at(i++) ;

    while (k <= end_index)
        mainArray -> at(j++)  = auxilliaryArray -> at(k++);
    
    return;
}


void mergeSortHelper(vector<int>* mainArray, int start_index, int end_index, vector<int>* auxilliaryArray) {

    if (start_index == end_index)
        return;

    int middle_index = (start_index + end_index) / 2;
    mergeSortHelper(auxilliaryArray, start_index, middle_index, mainArray);
    mergeSortHelper(auxilliaryArray, middle_index + 1, end_index, mainArray);
    doMerge(mainArray, start_index, middle_index, end_index, auxilliaryArray);
    return;
}

vector<int> mergeSort(vector<int> array) {

    if (array.size() <= 1)
        return array;

    vector<int> auxilliaryArray = array;
    mergeSortHelper(&array, 0, array.size() - 1, &auxilliaryArray);
    return array;
}

void show(vector<int> arr) {

    for (auto element: arr)
        cout << element << " ";
    cout << endl;
    return;
}

int main(int argc, char* argv[]) {

    vector<int> arr = {23, 2345,68, 19, 22, 11, 50, 1, 4, 7, 2, 35};
    arr = mergeSort(arr);
    show(arr);
    return 0;
}
