#include<iostream>
#include<vector>

using namespace std;

void swap(int& num1, int& num2) {
    int temp = num1;
    num1 = num2; 
    num2 = temp;
    return;
}

vector<int> seperatenegativepositive(vector<int> arr) {

    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        
        if (arr[left] >= 0) {

            if (arr[right] < 0) 
                swap(arr[left], arr[right]);

            else
                right--;
        }

        else 
            left++;

        if (arr[right] < 0) {

            if (arr[left] >= 0) 
                swap(arr[left], arr[right]);

            else
                left++;
        }

        else
            right--;
    }

    return arr;
}

void show(vector<int> arr) {

    for (auto element: arr) 
        cout << element << " ";
    cout << endl;
    return;
}


int main(int argc, char* argv[]) {

   vector<int> arr1 = {-2, -7, 8, 9, 0, 10, 23, -6, -5, 3, 4};
   arr1 = seperatenegativepositive(arr1);
   show(arr1);
   vector<int> arr2 = {-2, -3, -4, -5, 6, 7, 8, 9};
   arr2 = seperatenegativepositive(arr2);
   show(arr2);
   vector<int> arr3 = {1, 2, 3, 4, 5, 6, 7, 8, -7, -6, -5, -4, -3, -2, -1};
   arr3 = seperatenegativepositive(arr3);
   show(arr3);

   return 0;
}


