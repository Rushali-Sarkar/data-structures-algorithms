#include<iostream>
#include"BST.h"
#include<vector>

using namespace std;

void constructminheightBST(BinarySearchTree& bst, vector<int>& arr, int startIndex, int endIndex) {

    if (arr.size() == 0 || startIndex > endIndex)
        return;

    int index_to_insert = (startIndex + endIndex) / 2;
    bst.insertBST(arr[index_to_insert]);
    constructminheightBST(bst, arr, startIndex, index_to_insert - 1);
    constructminheightBST(bst, arr, index_to_insert + 1, endIndex);
    return;
}

BinarySearchTree minheightBST(vector<int> arr) {

    BinarySearchTree bst;
    constructminheightBST(bst, arr, 0, arr.size() - 1);
    return bst;
}

int main(int main, char* argc[]) {

    vector<int> arr = {1, 2, 5, 7, 10, 13, 14, 15, 22};
    BinarySearchTree bst = minheightBST(arr);
    bst.showInOrder();
    return 0;
}
