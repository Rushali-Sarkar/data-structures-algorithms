#include<iostream>
#include<vector>

using namespace std;

class Node {

    public:
        string name;
        vector<Node*> children;

        Node() {
            name = "";
        }

        Node(string n) {
            name = n;
        }
};


class graph {

    public:
        Node* headNode;
        vector<string> depthSearch;

        graph(){
            headNode = new Node();
        }

        graph(string name) {
            headNode = new Node(name);
        }

        Node* getHead() {
            return headNode;
        }

        void addChild (Node* currentNode, string name) {
            Node* child = new Node(name);
            currentNode -> children.push_back(child);
        }

        void depthfirstsearch(Node* currentNode) {

            depthSearch.push_back(currentNode -> name);

            if (currentNode -> children.size() == 0)
                return;

            for (int i = 0; i < currentNode -> children.size(); i++)
                depthfirstsearch(currentNode -> children[i]);

        }

        void show() {

            depthfirstsearch(headNode);

            for (int i = 0; i < depthSearch.size(); i++)
                cout << depthSearch[i] << " ";
            cout << endl;

            return;
        }
};

int main(int argc, char* argv[]) {

    
    
    graph g("A");

    Node* node = g.getHead();

    g.addChild(node, "B");
    g.addChild(node, "C");
    g.addChild(node, "D");

    Node*  node2 = node -> children[0];

    g.addChild(node2, "E");
    g.addChild(node2, "F");

    Node* node3 = node2 -> children[1];

    g.addChild(node3, "I");
    g.addChild(node3, "J");

    Node* node4 = node -> children[2];

    g.addChild(node4, "G");
    g.addChild(node4, "H");

    Node* node5 = node4 -> children[0];

    g.addChild(node5, "K");

    g.show();
    return 0;
}


    


