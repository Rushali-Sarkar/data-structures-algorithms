#include<iostream>
#include<string>

using namespace std;

bool is_palindrome(string expression) {

    int length = expression.length();
    string reversed =  "";
    for (char character: expression)
        reversed = character + reversed;

    return reversed == expression;
}

int main(int argc, char* argv[]) {

    string one = "malayalam";
    string two = "telegu";

    cout << is_palindrome(one) << endl;
    cout << is_palindrome(two) << endl;

    return 0;
}
