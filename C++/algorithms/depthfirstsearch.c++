#include<iostream>
#include<vector>
#include<queue>

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
        vector<string> breadthSearch;

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

        void breadthfirstsearch(Node* currentNode) {

            queue<Node*> breadthFirstSearch;
            breadthFirstSearch.push(getHead());
            
            while (!breadthFirstSearch.empty()) {
            
                int levelSize = breadthFirstSearch.size();

                for (int i = 0; i < levelSize; i++) {
                    
                    Node* currentNode = breadthFirstSearch.front();
                    breadthSearch.push_back(currentNode -> name);
                    breadthFirstSearch.pop();

                    int size = currentNode -> children.size();

                    for (int j = 0; j < size; j++)
                        breadthFirstSearch.push(currentNode -> children[j]);
                }

            }
        }
                  


        void show() {

            breadthfirstsearch(headNode);

            for (int i = 0; i < breadthSearch.size(); i++)
                cout << breadthSearch[i] << " ";
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


    


