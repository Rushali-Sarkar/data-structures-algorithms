#include <iostream>
#include <vector>
#include <utility>

using namespace std;


void print(vector<int>& arr) {
    for (int i = arr.size() - 1; i >= 0; --i)
        cout << arr[i];
    cout << endl;
    return;
}

pair<int, int> addBinaryDigits(int digit1, int digit2, int carry) {

    int sum = 0;
    if (digit1 == 0 && digit2 == 0) {
        sum = carry == 0 ? 0: 1;
        carry = 0;
    }
    else if (digit1 == 0 && digit2 == 1 || digit1 == 1 && digit2 == 0) {
        sum = carry == 1 ? 0: 1;
        carry = carry == 1? 1: 0;
    }
    else if(digit1 == 1 && digit2 == 1) {
        sum = carry == 0 ? 0: 1;
        carry = 1;
    }

    return pair<int, int> {sum, carry};
}

vector<int> binaryAdd(vector<int> number1, vector<int> number2) {

    pair<int, int> sum_carry = {0, 0};
    int index1 = number1.size() - 1;
    int index2 = number2.size() - 1;
    vector<int> result;

    while (index1 >= 0 && index2 >= 0) {
        sum_carry = addBinaryDigits(number1[index1], number2[index2], sum_carry.second);
        result.push_back(sum_carry.first);
        --index1;
        --index2;
    }

    while (index1 >= 0) {
        sum_carry = addBinaryDigits(number1[index1], 0, sum_carry.second);
        result.push_back(sum_carry.first);
        --index1;
    }

    while (index2 >= 0) {
        sum_carry = addBinaryDigits(0, number2[index2], sum_carry.second);
        result.push_back(sum_carry.first);
        --index2;
    }

    if (sum_carry.second != 0)
        result.push_back(sum_carry.second);

    return result;
}

int main(int argc, char* argv[]) {

    vector<int> number1 = {1, 1};
    vector<int> number2 = {1, 1, 0};
    vector<int> number3 = {1, 0, 1};

    vector<int> result1 = binaryAdd(number1, number1);
    vector<int> result2 = binaryAdd(number2, number3);
    vector<int> result3 = binaryAdd(number1, number3);
    vector<int> result4 = binaryAdd(number2, number1);

    cout << "11 + 11 = ";
    print(result1);
    cout << "110 + 101 = ";
    print(result2);
    cout << "11 + 101 = ";
    print(result3);
    cout << "110 + 11 = ";
    print(result4);
    
    return 0;
}
