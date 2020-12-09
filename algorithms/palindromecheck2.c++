#include<iostream>
#include<string>

using namespace std;

bool is_palindrome(string expression) {

    int length = expression.length();

    if (length == 1 || length == 0)
        return true;

    if (expression[0] == expression[length - 1] && is_palindrome(expression.substr(1, length - 2)))
        return true;
    
    return false;
}

int main(int argc, char* argv[]) {

    string one = "malayyalam";
    string two = "telegu";

    cout << is_palindrome(one) << endl;
    cout << is_palindrome(two) << endl;

    return 0;
}
