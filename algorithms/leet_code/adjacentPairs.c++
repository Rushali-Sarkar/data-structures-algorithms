#include<iostream>
#include<unordered_map>
#include<vector>
#include<unordered_set>

using namespace std;


void show(vector<int> arr) {

    for (auto each: arr) 
        cout << each << " ";
    cout << endl;
    return;
}

void compute(vector<int>& result, int head, unordered_map<int, vector<int>> graph, 
    unordered_set<int>& visited) {

        if (visited.find(head) != visited.end())
            return;
        visited.insert(head);
        result.push_back(head);
        for (auto each: graph[head])
            compute(result, each, graph, visited);

        return;

}

vector<int> restoreArray(vector<vector<int>> adjacentPairs) {

    unordered_map<int, vector<int>> graph;
    for (auto elements: adjacentPairs) {
        graph[elements[0]].push_back(elements[1]);
        graph[elements[1]].push_back(elements[0]);
    }


    int head;
    for (auto element: graph) {
        if (element.second.size() == 1) {
            head = element.first;
            break;
        }
    }

    vector<int> result;
    unordered_set<int> visited;
    compute(result, head, graph, visited);
    return result;
}

int main(int argc, char* argv[]) {
    
    vector<int> arr = restoreArray({{2, 1}, {3, 4}, {3, 2}});
    vector<int> arr2 = restoreArray({{4, -2}, {1, 4}, {-3, 1}});

    show(arr);
    show(arr2);

    return 0;
}