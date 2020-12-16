/* implement a function that sorts an array of 0's0​′​​s, 1's1​′​​s and 2's2​′​​s. This is called the Dutch National Problem. Since the number OO can be represented as the blue color, 11 as the white color, and 22 as the red color, we want the array to form the Dutch flag.



Try solving this problem inplace and in linear time without using any extra space!



Input 

An array of 0's0​′​​s, 1's1​′​​s and 2's2​′​​s



Output 

An array where the numbers 00, 11, and 22 are sorted.



Sample Input 

7



2

0

0

1

2

1

0



Sample Output



0 0 0 1 1 2 2
*/

#include<iostream>

using namespace std;

void swap(int& num1, int& num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
    return;
}

void DutchNationalFlag(int arr[], int size) {
    
    int low = 0;
    int mid = 0;
    int high = size - 1;
    
    while (mid < high) {
        
        if (arr[mid] == 0) {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        
        else if (arr[mid] == 2) {
            swap(arr[mid], arr[high]);
            high--;
        }
        
        else
            mid++;
    }
    
 for (int i = 0; i < size; i++)
    cout << arr[i] << " ";

 cout << endl;
 return;

}


int main(int argc, char* argv[]) {
    
    int size = 7;
    int arr[] = {2, 0, 0, 1, 2, 1, 0};
    DutchNationalFlag(arr, size);
    return 0;
    
}
