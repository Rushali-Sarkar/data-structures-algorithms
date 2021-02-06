#include <iostream>
#include <queue>

using namespace std;

class Node {

    public:

        int value;
        Node* left;
        Node* right;

        Node() {
            this -> value = 0;
            this -> left = nullptr;
            this -> right = nullptr;
        }

        Node(int value) {
            this -> value = value;
            this -> left = nullptr;
            this -> right = nullptr;
        }

};


class BinaryTree {

    public:

        Node* head;

        BinaryTree() {
            this -> head = new Node();
        }

        BinaryTree(int value) {
            this -> head = new Node(value);
        }

        void insert(int value) {

            if (this -> head == nullptr) {
                this -> head = new Node(value);
                return;
            }

            queue<Node*> nodes;
            nodes.push(this -> head);

            while (!nodes.empty()) {

                int levelsize = nodes.size();
                for (int i = 1; i <= levelsize; i++) {

                    Node* currentNode = nodes.front();
                    nodes.pop();

                    if (currentNode -> left == nullptr) {
                        currentNode -> left = new Node(value);
                        return;
                    }

                    else
                        nodes.push(currentNode -> left);

                    if (currentNode -> right == nullptr) {
                        currentNode -> right = new Node(value);
                        return;
                    }

                    else
                        nodes.push(currentNode -> right);
                }
            }

            return;
        }
};
