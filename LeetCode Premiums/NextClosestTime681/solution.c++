#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isDigitPresentInList(char digit, vector<char> digits) {
    for (char each_digit: digits)
        if (each_digit == digit)
            return true;
    return false;
}

bool isValidTime(string time, vector<char>& time_digits) {
    for (char time_digit: time) {
        if (!isDigitPresentInList(time_digit, time_digits))
            return false;
    }
    return true;
}

string convertTimeToString(int hours, int minutes) {
    string new_hours = "";
    string new_minutes = "";
    if (hours <= 9)
        new_hours = "0";
    new_hours += to_string(hours);
    if (minutes <= 9)
        new_minutes += "0";
    new_minutes += to_string(minutes);
    return new_hours + ":" + new_minutes;
}


vector<int> getNextMinute (int hours, int minutes) {
    if (minutes == 59) {
        if (hours == 23) 
            hours = 0;
        else
            ++hours;
        minutes = 0;
    }

    else
        ++minutes;
    
    return vector<int> {hours, minutes};
}

string nextClosestTime(string time) {
    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3, 2));
    vector<char> time_digits;
    for (char each: time)
        time_digits.push_back(each);
    vector<int> next_minute = getNextMinute(hours, minutes);
    while (!isValidTime(convertTimeToString(next_minute[0], next_minute[1]), time_digits)) {
        next_minute = getNextMinute(next_minute[0], next_minute[1]);
    }

    return convertTimeToString(next_minute[0], next_minute[1]);
}

int main(int argc, char* argv[]) {
    string time;
    cin >> time;
    cout << nextClosestTime(time) << endl;
    return 0;
}