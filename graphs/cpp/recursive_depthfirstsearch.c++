#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

void depthFirstSearch (unordered_set<char>& visited, unordered_map<char, vector<char>>& graph, char& source_node) {

        cout << source_node << "\t";
        visited.insert (source_node);
        for (char each: graph[source_node]) {
                if (visited.find(each) == visited.end())
                        depthFirstSearch (visited, graph, each);
        }

        return;
}

int main (int arcg, char* argv[]) {

        char source_node = 'a';
        unordered_map <char, vector<char>> graph;
        graph['a'] = vector<char> {'b', 'c'};
        graph['b'] = vector<char> {'d'};
        graph['c'] = vector<char> {'e'};
        graph['d'] = vector<char> {'f'};
        graph['e'] = vector<char> {};
        graph['f'] = vector<char> {};
        unordered_set<char> visited;

        depthFirstSearch (visited, graph, source_node);
        cout << endl;
        return 0;
}
        
