#include<iostream>
#include<vector>

using namespace std;

int knapsack(vector<vector<int>> elements, int capacity) {

    vector<int> previous_row (capacity + 1, 0);
    int row_result = 0;

    for (int i = 1; i <= elements.size(); i++) {
        
        int value = elements[i - 1][0];
        int weight = elements[i - 1][1];
        vector<int> current_row (capacity + 1, 0);

        for (int j = 1; j <= capacity; j++) {
             
            if (weight > j)
                
                current_row[j] = previous_row[j];

            else
                current_row[j] = max(previous_row[j], value + previous_row[j -weight]);
        }

        row_result = current_row[capacity];
        previous_row = current_row;

    }

       return row_result;
}

int main(int argc, char* argv[]) {

    int capacity = 50;

    vector<int> bag1{60, 10};
    vector<int> bag2{100, 20};
    vector<int> bag3{120, 30};
   
    vector<vector<int>> elements;

    elements.push_back(bag1);
    elements.push_back(bag2);
    elements.push_back(bag3);
    
    cout << knapsack(elements, capacity) << endl;
    
    return 0;
}





            

