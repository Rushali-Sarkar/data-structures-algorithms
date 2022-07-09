#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>

using namespace std;

void printVector (vector<char>& arr) {
        for (char each: arr)
                cout << each << '\t';
        cout << endl;
        return;
}

vector<char> depthFirstSearch (unordered_map<char, vector<char>>& graph, char& start_node) {

        vector<char> depth_first_tree;
        unordered_set<char> visited;
        stack<char> depth_stack;
        depth_stack.push (start_node);

        while (!depth_stack.empty()) {

                char current_vertex = depth_stack.top();
                visited.insert (current_vertex);
                depth_first_tree.push_back (current_vertex);
                depth_stack.pop();

                for (char each: graph[current_vertex]) {
                        if (visited.find(each) == visited.end())
                                depth_stack.push(each);
                }
        }
        
        return depth_first_tree;
}

int main (int argc, char* argv[]) {
        
        char start_node = 'a';
        unordered_map<char, vector<char>> graph;
        graph['a'] = vector<char> {'b', 'c'};
        graph['b'] = vector<char> {'d'};
        graph['c'] = vector<char> {'e'};
        graph['d'] = vector<char> {'f'};
        graph['e'] = vector<char> {};
        graph['f'] = vector<char> {};

        vector<char> depth_first_tree = depthFirstSearch(graph, start_node);
        printVector (depth_first_tree);
        return 0;
}
