#include<iostream>
#include<queue>
#include"BT.h"

using namespace std;


int nodeDepths(BinaryTree bst) {

    int nd = 0;
    int node_depth = 0;
    queue<Node*> levelOrderQueue;
    int levelSize;
    levelOrderQueue.push(bst.getRoot());

    while (!levelOrderQueue.empty()) {

        levelSize = levelOrderQueue.size();

        for (int i = 0; i < levelSize; i++) {

            Node* currentNode = levelOrderQueue.front();
            levelOrderQueue.pop();

            if (currentNode -> leftChild != nullptr)
                levelOrderQueue.push(currentNode -> leftChild);

            if (currentNode -> rightChild !=  nullptr)
                levelOrderQueue.push(currentNode -> rightChild);
        }

        nd = nd + levelSize * node_depth;
        node_depth++;
    }

    return nd;
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

    cout << nodeDepths(bt) << endl;
    return 0;
}
    

/* The time complexity of the algorithms is O(n) where n is the number of nodes and space complexity is O(n) at most beacuse
 * we are storing the queue n at most.*/
