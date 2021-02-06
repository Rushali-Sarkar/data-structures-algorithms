#include<iostream>
#include<vector>

using namespace std;

void show(vector<int> arr) {
    for (auto each: arr)
        cout << each << " ";
    cout << endl;
    return;
}

vector<int> getRow(int rowIndex) {
        
        if (rowIndex == 0)
            return vector<int> {1};
        if (rowIndex == 1)
            return vector<int> {1, 1};
        
        vector<int> first = {1};
        vector<int> second = {1, 1};
        
        int count = 2;
        while (count <= rowIndex) {
            
            first = second;
            second = {1};
            for (int i = 1; i < first.size(); i++) {
                int next = first[i - 1] + first[i];
                second.push_back(next);
            }
            second.push_back(1);
            count++;
        }
        
        return second;
    }

    int main(int argc, char* argv[]) {
        
        for (int i = 0; i <= 33; i++)
            show(getRow(i)); 
    
        return 0;
    }

