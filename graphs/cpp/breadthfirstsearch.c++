#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

void printVector (vector<char>& arr) {
        for (char each: arr)
                cout << each << '\t';
        cout << endl;
        return;
}

vector<char> breadthFirstSearch (unordered_map<char, vector<char>>& graph, char& source_node) {

        unordered_set<char> visited;
        queue<char> breadth_queue;
        breadth_queue.push (source_node);
        vector<char> breadth_first_tree;

        while (!breadth_queue.empty()) {

                char current_node = breadth_queue.front();
                breadth_queue.pop();
                visited.insert(current_node);
                breadth_first_tree.push_back (current_node);
                for (char each: graph[current_node]) {
                        if (visited.find (each) == visited.end ())
                                breadth_queue.push(each);
                }
        }

        return breadth_first_tree;
}

int main (int argc, char* argv[]) {

        unordered_map<char, vector<char>> graph;
        graph['a'] = vector<char> {'b', 'c'};
        graph['b'] = vector<char> {'d'};
        graph['c'] = vector<char> {'e'};
        graph['d'] = vector<char> {'f'};
        graph['e'] = vector<char> {};
        graph['f'] = vector<char> {};
        char source_node = 'a';

        vector<char> breadth_first_tree = breadthFirstSearch (graph, source_node);
        printVector (breadth_first_tree);
        return 0;
}




