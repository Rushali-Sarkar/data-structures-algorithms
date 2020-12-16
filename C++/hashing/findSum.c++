/* Problem Statement 

Implement a function findSum(int arr[], int value, int size) 
which takes an array arr, a number value and size of the array as input and 
returns an array of two numbers that add up to value. 
In case there is more than one pair in the array containing numbers that 
add up to value, you are required to return only one such pair. 
If no such pair found then simply return the array.

Input 

An array, value, and size of the array

Output 

An array with two integers that add up to value

Sample Input 
Input = 8

1

21

3

14

5

60

7

6

81



Sample Output = Number 1 = 60                                                                   

Number 2 = 21                                                                   


Sum = 81


For example, in this illustration, we are given 81 as t
he number value and when we traverse the whole array we find that 21 and 60 
are the integers that add up to 81.
*/

#include <iostream>
#include "unordered_set"

using namespace std;


int * findSum(int arr[], int sum, int size) { 
    
    int* result = new int[2];
    
    
    unordered_set<int> sum_elements;
    for (int i = 0; i < size; i++) {
        
        int first_number = arr[i];
        int second_number = sum - first_number;
        if (sum_elements.find(second_number) != sum_elements.end()) {
            result[0] = first_number;
            result[1] = second_number;
            return result;
        }
        
        else
            sum_elements.insert(first_number);
        
    }
    return result;
}

int main(int argc, char* argv[]){
    
    int* result = new int[2];
    int size = 8;
    int sum = 81;
    int arr[] = {1, 21, 3, 14, 5, 60, 7, 6};
  
    result = findSum(arr, sum, size);
    cout << "Number 1 = " << result[0] << endl;
    cout << "Number 2 = " << result[1] << endl;
    cout << "Sum = "      << sum       << endl;
    
    return 0;
}
