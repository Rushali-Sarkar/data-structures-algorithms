#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;


bool isRansomNotePossible(string note, string magazine) {

    unordered_map<char, int> trackingFrequency;

    for (auto each: magazine) {

        if (trackingFrequency.find(each) == trackingFrequency.end())
            trackingFrequency[each] = 1;

        else
            trackingFrequency[each] += 1;

    }

    for (auto each: note) {

        if (trackingFrequency.find(each) == trackingFrequency.end())
            return false;

        if (trackingFrequency[each] == 0)
            return false;

        else
            trackingFrequency[each] -= 1;
    }

    return true;
}

int main(int argc, char* argv[]) {

    cout << isRansomNotePossible("abcc", "aabbcc") << endl;
    cout << isRansomNotePossible("a", "b") << endl;
    cout << isRansomNotePossible("aa", "ab") << endl;
    cout << isRansomNotePossible("aa", "aab") << endl;

    return 0;
}
