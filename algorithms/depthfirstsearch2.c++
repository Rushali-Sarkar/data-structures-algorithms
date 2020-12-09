#include<iostream>
#include<vector>

using namespace std;

class Node {

    public:
        string name;
        vector<Node*> children;

        Node(string name) {
            this -> name = name;
        }

        vector<string> depthfirstSearch(vector<string>* array) {
            array -> push_back(this -> name);
            for (int i = 0; i < this -> children.size(); i++) 
                children[i] -> depthfirstSearch(array);

            return *array;
        }

        Node* addChild(string name) {
            Node* child = new Node(name);
            children.push_back(child);
            return this;
        }
};
