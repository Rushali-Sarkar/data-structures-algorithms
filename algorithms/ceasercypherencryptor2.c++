#include<iostream>
#include<string>

using namespace std;

string ALPHABETS = "abcdefghijklmnopqrstuvwxyz";

string ceasercypherencryptor(string expression, int steps) {

    string result = "";
    steps = steps % 26;

    for (auto character: expression) {
        
        int index = ALPHABETS.find(character);
        int shiftLetterTo = (index + steps) % 26;
        result = result + ALPHABETS[shiftLetterTo];
    }
  return result;
}

int main(int argc, char* argv[]) {

    cout << ceasercypherencryptor("xyz" , 2) << endl;
    cout << ceasercypherencryptor("abcdefghijklmnopqrstuvwxyz", 13) << endl;

    return 0;
}
