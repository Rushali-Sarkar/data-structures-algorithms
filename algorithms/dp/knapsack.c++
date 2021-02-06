#include<iostream>
#include<vector>

using namespace std;

int knapsack(vector<vector<int>> elements, int capacity) {

    int rows = elements.size() + 1;
    int columns = capacity + 1;

    vector<vector<int>> knapsack_table(rows, vector<int>(columns, 0));

    for (int i = 1; i < rows; i++) {

        int value = elements[i - 1][0];
        int weight = elements[i - 1][1];

        for (int j = 1; j <= capacity; j++) {
             
            if (weight > j)
                knapsack_table[i][j] = knapsack_table[i - 1][j];

            else
                knapsack_table[i][j] = max(knapsack_table[i - 1][j], value + knapsack_table[i - 1][j - weight]);
        }

    }

       return knapsack_table[rows - 1][capacity];
}

int main(int argc, char* argv[]) {

    int capacity = 10;
    vector<int> bag1{1, 2};
    vector<int> bag2{4, 3};
    vector<int> bag3{5, 6};
    vector<int> bag4{6, 7};
    vector<vector<int>> elements;
    elements.push_back(bag1);
    elements.push_back(bag2);
    elements.push_back(bag3);
    elements.push_back(bag4);
    
    cout << knapsack(elements, capacity) << endl;
    
    return 0;
}





            

