#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;


int minOperations(vector<string>& logs) {

    stack<string> path;
    
    for (auto each: logs) {

        if (each == "../") {
            if (!path.empty())
                path.pop();
        }

        else if (each != "./")
            path.push(each);
    }

    return path.size();
}