#include <iostream>
#include <string>

using namespace std;

string removeKdigits(string num, int k) {

    if (num.size() == k)
        return "0";

    string result;
    int index = 0;
    while (k > 0 && index < num.size()) {

        if (result.size() == 0)
            result = result + num[index++];
            
        if (int(num[index]) < result.back()) {
            result.pop_back();
            k--;
            continue;
        }

        else if (index < num.size())
            result.push_back(num[index++]);

    }

    result = result + num.substr(index, num.size() - index);
    if (k != 0)
        result = result.substr(0, result.size() - k);
    
    if (result.size() == 0)
        return "0";

    for (int i = 0; i < result.size(); i++) {
        if (result[i] != '0') {
            result = result.substr(i, result.size());
            break;
        }
    }
    
    return result;
}

int main(int argc, char* argv[]) {
    string a = "1432219";
    int k = 3;
    cout << removeKdigits(a, k) << endl;

    string a2 = "10200";
    int k2 = 1;
    cout << removeKdigits(a2, k2) << endl;

    string a3 = "10";
    int k3 = 2;
    cout << removeKdigits(a3, k3) << endl;

    string a4 = "112";
    int k4 = 1;
    cout << removeKdigits(a4, k4) << endl;

    return 0;
}