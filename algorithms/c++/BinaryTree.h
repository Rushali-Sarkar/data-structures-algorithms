#include <iostream>
#include <queue>

using namespace std;

class Node {

    public:

        int data;
        Node* left;
        Node* right;

        Node() {
           this -> data = 0;
           this -> left = nullptr;
           this -> right = nullptr;
        }

        Node(int data) {
            this -> data = data;
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

        BinaryTree(int data) {
            this -> head = new Node(data);
        }

        void insert(int item) {

            queue<Node*> levels;
            levels.push(this -> head);

            while (!levels.empty()) {

                int level_size = levels.size();
                for (int i = 1; i <= level_size; i++) {

                   Node* current_node = levels.front();
                   levels.pop();

                   if (current_node -> left == nullptr) {
                       current_node -> left = new Node(item);
                       return;
                   }

                   else 
                       levels.push(current_node -> left);

                   if (current_node -> right == nullptr) {
                       current_node -> right = new Node(item);
                       return;
                   }

                   else 
                       levels.push(current_node -> right);
                }
            }
            return;
        }
};




