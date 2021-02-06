#include<iostream>
#include<vector>
#include<any>

using namespace std;

int productSum(vector<any> arr, int multiply = 1) {

    int sum = 0;
    for (auto element: arr) {

        if (element.type() == typeid(vector<any>))
            sum = sum + productSum(element, multiply + 1);

        else
            sum = sum + any_cast<int>element;
    }

    return sum * multiply;
}

int main(int argc, char* argv[]) {

    vector<any> arr = {5, 2, {7, -1}, 3, {6, {-13, 8}, 4}};
    cout << productSum(arr) << endl;
    return 0;
}
