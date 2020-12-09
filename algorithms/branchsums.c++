#include<iostream>
#include<vector>
#include"BT.h"

using namespace std;

void helper(Node* currentNode, vector<int>& sums, int runningsum) {
    

    if (currentNode == nullptr)
        return;

    runningsum = runningsum + currentNode -> value;
    if (currentNode -> leftChild == nullptr && currentNode -> rightChild == nullptr) {
        sums.push_back(runningsum);
        return;
    }
    
    
    helper(currentNode -> leftChild, sums, runningsum);
    helper(currentNode -> rightChild, sums, runningsum);
    
    return;
       
}

vector<int> branchsums(BinaryTree bt) {
    vector<int> sums;
    helper(bt.getRoot(), sums, 0);
    return sums;
}

int main(int argc, char* argv[]) {

    BinaryTree bt(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);
    bt.insert(5);
    bt.insert(6);
    bt.insert(7);
    bt.insert(8);
    bt.insert(9);

    vector<int> sums = branchsums(bt);
    for (int i = 0; i < sums.size(); i++) 
        cout << sums[i] << " ";
    cout << endl;
    return 0;
}
    
/* This algorithm is going to take O(n) time complexity since we are traversing to each node of the tree
 * And it will take O(log(n)) space complexity as it will be adding one function call to the callstack after eliminating half 
 * of the binary tree each time*/

