 #include<iostream>

using namespace std;

int nthfibonacci(int n) {

    int arr[2];
    arr[0] = 0;
    arr[1] = 1;
    

    for (int i = 1; i < n; i++) {

        int sum = arr[0] + arr[1];
        arr[0] = arr[1];
        arr[1] = sum;
    }

    return n > 1  ? arr[0] : 0;
}

int main(int argc, char* argv[]) {

    for (int i = 1; i <= 30; i++) 
        cout << nthfibonacci(i) << " ";
    cout << endl;
    return 0;
}

/* The time complexity of this algorithm is O(n) since at every calculation only values are indexed and calculated
 * The space complexity of this algorithm is O(1) since there are only three numbers stored at a given point of time.
 */
