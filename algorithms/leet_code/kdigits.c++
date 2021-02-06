#include<iostream>
#include<string>

using namespace std;

string removeKdigits(string num, int k) {

    if (num.size() == k)
        return "0";

    for (int i = 1; i <= k; i++) {
        string result = "";
        for (int i = 1; i < num.size(); i++) {
            if (int(num[i - 1]) < int(num[i])) 
                result = result + num[i - 1];
            else {
                result = result + num.substr(i, num.size() - i);
                break;
            }
        }
        num = result;
    }
    return to_string(stoi(num));
}

int main(int argc, char* argv[]) {

    string a = "1432219";
    int k = 3;
    cout << removeKdigits(a, k) << endl;

    string b = "10200";
    int l = 1;
    cout << removeKdigits(b, l) << endl;

    string c = "10";
    int m = 2;
    cout << removeKdigits(c, m) << endl;

    return 0;

}
