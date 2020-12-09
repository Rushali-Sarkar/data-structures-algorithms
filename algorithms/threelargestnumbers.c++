#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

vector<int> threelargestnumbers(vector<int> numbers) {

    vector<int> threelargest = {numbers[0], numbers[1], numbers[2]};

    for (int i = 0; i < numbers.size(); i++) {

        if (numbers[i] > threelargest[0]) {
            threelargest[2] = threelargest[1];
            threelargest[1] = threelargest[0];
            threelargest[0] = numbers[i];
        }

        else if (numbers[i] > threelargest[1]) {
            threelargest[2] = threelargest[1];
            threelargest[1] = numbers[i];
        }

        else if (numbers[i] > threelargest[2])
            threelargest[2] = numbers[i];

    }

    return threelargest;

}

int main(int argc, char* argv[]) {

    vector<int> arr = {141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7};
    vector<int> threelargest = threelargestnumbers(arr);
    cout <<  threelargest[0] << endl << threelargest[1] << endl << threelargest[2] << endl;
    return 0;
}
