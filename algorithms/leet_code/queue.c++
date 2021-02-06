 #include <bits/stdc++.h>

using namespace std;


void show(vector<vector<int>> arr) {

    for (auto each: arr)
        cout << "[" << each[0] << ", " << each[1] << "]";
    cout << endl;

    return;
}

void swap(vector<int>& first, vector<int>& second) {
        
    vector<int> temp = first;
    first = second;
    second = temp;
    return;

}
   
bool compare(vector<int>& first, vector<int>& second) {
        
    if (first[0] > second[0])
        return true;
        
    if (first[0] == second[0]) {
        if (first[1] < second[1])
            return true;
        return false;
    }
        
    return false;
}

void shiftAdd(vector<int> each, int index, vector<vector<int>>& result, int numElements) {
    for (int i = numElements; i > index; i--)
        result[i] = result[i - 1];
    result[index] = each;
    return;
}
        
vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    
    sort(people.begin(), people.end(), compare);

    vector<int> visited(people.size(), 0);
    vector<vector<int>> result(people.size(), vector<int> {0, 0});
    int numElements = 0;

    for (auto each: people) {
        int index = each[1];

        if (visited[index]) {
            shiftAdd(each, index, result, numElements);
            visited[numElements] = 1;
        }

        else {
            result[index] = each;
            visited[index] = 1;
        }

        numElements++;
    }

    return result;
}

int main(int argc, char* argv[]) {

    vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    people = reconstructQueue(people);
    show(people);
    return 0;
    
}

