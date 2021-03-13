#include<iostream>
#include<string>

using namespace std;

bool is_palindrome (string expression) {

    int left  = 0;
    int right = expression.length() - 1;

    while (left < right) {

       if (expression[left] != expression[right])
           return false;

       left++;
       right--;
    }

    return true;
}

int countofLettersToCut(string expression) {

    
    for (int i = 0; i < expression.length(); i++) { 
        char first_letter = expression[i];       
        for (int j = expression.length() - 1; j > i; j--) {
            char possible_match = expression[j];       
            if (first_letter == possible_match && is_palindrome(expression.substr(i, (j - i + 1))))
               return (expression.length() - (j - i + 1));


        }
    }

   return -1;
}

int main(int argc, char* argv[]) {

    string str = "google";
    string str2 = "rugoogle";
    
    cout << countofLettersToCut(str) << endl;
    cout << countofLettersToCut(str2) << endl;

    return 0;
}








    
