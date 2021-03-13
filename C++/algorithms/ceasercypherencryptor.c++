#include<iostream>
#include<string>
#include<vector>

using namespace std;

string ceasercypherencryptor(string expression, int steps) {

    vector<char> encryptedvalue;
    string finalencrypted;
    steps = steps % 26;

    for (auto character: expression) {
        
        int shiftLetterTo = int(character) + steps;
        
        if (shiftLetterTo > 122)
            shiftLetterTo = 96 + (shiftLetterTo % 122);

        encryptedvalue.push_back(char(shiftLetterTo));
    }

    for (auto character: encryptedvalue) 
        finalencrypted = finalencrypted + character;
    
    return finalencrypted;
}

int main(int argc, char* argv[]) {

    cout << ceasercypherencryptor("xyz", 2) << endl;
    cout << ceasercypherencryptor("abcdefghijklmnopqrstuvwxyz", 28) << endl;
    return 0;
}

