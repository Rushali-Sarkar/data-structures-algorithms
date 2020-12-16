/* Implement a function that takes two sorted arrays of variable length and finds the median of the two arrays.
 *
 * Input
 *
 * Two sorted arrays and their sizes
 *
 * Output
 *
 * The median of the two arrays
 *
 * Sample Input
 *
 * 1// size of first array
 *
 * 100
 *
 * 5 // size of second array
 *
 * 1
 * 5
 * 8
 * 10
 * 20
 *
 * Sample Output
 * 15
 */


#include<iostream>
#include<vector>

using namespace std;

double getMedian(int array1[], int array2[], int sizeOfArray1, int sizeOfArray2) {

    int n = (sizeOfArray1 + sizeOfArray2) / 2;
    int start = 1;
    int pointer1 = 0;
    int pointer2 = 0;
    int element = 0;
    
    vector<int> midElements;
    
    while (pointer1 < sizeOfArray1 && pointer2 < sizeOfArray2) {

        if (array1[pointer1] < array2[pointer2])
            element = array1[pointer1++];

        else
            element = array2[pointer2++];


        if (start == n || start == n + 1)
            midElements.push_back(element);

        start++;
    }

    while (pointer1 < sizeOfArray1) {

        element = array1[pointer1++];
        if (start == n || start == n + 1) 
            midElements.push_back(element);
        start++;
   
    }

    while (pointer2 < sizeOfArray2) {
        
        element = array2[pointer2++];
        if (start == n || start == n + 1)
            midElements.push_back(array2[pointer2]);
        start++;
    }

     
    double median = midElements[0];

    if ((sizeOfArray1 + sizeOfArray2) % 2 == 0)
        median = (median + midElements[1]) / 2;

    return median;
}


int main(int argc, char* argv[]) {

    int array1[] = {100};
    int sizeOfArray1 = 1;

    int array2[] = {1, 5, 8, 10, 20};
    int sizeOfArray2 = 5;

    cout << getMedian(array1, array2, sizeOfArray1, sizeOfArray2) << endl;

    return 0;
}
    
