#include<iostream>
#include<vector>
#include<cmath>

using namespace std;


void show(vector<int> array) {

    for (auto element: array) 
        cout << element << '\t';

    cout << endl;

}

vector<int> divisors(int num) {
    vector<int> result;
    int square_root = sqrt(num);
                    
    for (int i = 1; i <= square_root; i++) {
        if (num % i == 0) {
            result.push_back(i);

            if (num / i != i) 
                result.push_back(num / i);
        }
                                            
    }
                            
    return result;
}

int main(int argc, char* argv[]) {

    vector<int> four = divisors(4);
    show(four);

    vector<int> twentysix = divisors(26);
    show(twentysix);


    vector<int> to = divisors(21);
    show(to);

    return 0;
}
    
