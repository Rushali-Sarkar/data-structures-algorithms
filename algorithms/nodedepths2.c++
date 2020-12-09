#include<iostream>
#include<vector>
#include"BT.h"


using namespace std;

struct Level {
    Node* rootNode;
    int depth;
};

int nodedepths(BinaryTree bt) {

    Node* rootNode = bt.getRoot();

    int depth_sum = 0;
    vector<Level> stack = {{rootNode, 0}};
    while (stack.size() > 0) {
        Node* node = stack.back().rootNode;
        int depth = stack.back().depth;
        stack.pop_back();
        if (node == nullptr)
            continue;

        depth_sum = depth_sum + depth;

        stack.push_back(Level{node -> leftChild, depth + 1});
        stack.push_back(Level{node -> rightChild, depth + 1});
    }
    return depth_sum;
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
    bt.insert(10);

    cout << nodedepths(bt) << endl;
    return 0;
}

/* Time complexity is O(n)
 * Space complexity is also O(n)*/
