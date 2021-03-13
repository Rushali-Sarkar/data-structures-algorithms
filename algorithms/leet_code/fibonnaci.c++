// 0 1 1 2 3 5 8 13 (nth term in the series)
// 1 2 3 4 5 6 7 8
#include <iostream>

using namespace std;

int nth(int n) {

    if (n == 1)
        return 0;  
    if (n == 2)
        return 1;
    return nth(n - 1) + nth(n - 2);
}