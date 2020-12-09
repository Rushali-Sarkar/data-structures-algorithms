#include<iostream>
#include<vector>

using namespace std;


void swap (int& num1, int& num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
    return;
}

vector<int> sort012(vector<int> arr) {

   int low = 0;
   int high = arr.size() - 1;
   int mid = (low + high) / 2;

   while (mid > low && mid < high) {

       
       if (arr[mid] == 1) {
           mid++;
       }

       if (arr[mid] == 2) {
           swap(arr[mid], arr[high]);
           high--;
       }

       if (arr[mid] == 0) {
           swap(arr[mid], arr[high]);
           low++;
       }

       if (arr[low] == 0) 
           low++;

       if (arr[high] == 2)
           high--;
   }

   return arr;
}

void show (vector<int> arr) {

    for (int i = 0; i < arr.size(); i++) 
        cout << arr[i] << " ";
    cout << endl;
    return;
}

int main(int argc, char* argv[]) {

    vector<int> arr1 = {2, 0, 0, 1, 2, 1, 0};
    vector<int> arr2 = {2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0};

    arr1 = sort012(arr1);
    show(arr1);

    arr2 = sort012(arr2);
    show(arr2);

    return 0;
}





