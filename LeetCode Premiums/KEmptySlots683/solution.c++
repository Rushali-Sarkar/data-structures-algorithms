#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

bool isNoBloomsInBetween(unordered_set<int>& blooms_till_now, int& start, int& end) {
    for (int i = start + 1; i < end; ++i) {
        if (blooms_till_now.find(i) != blooms_till_now.end())
            return false;
    }
    return true;
}

int KEmptySlots(vector<int>& flowers, int k) {
    unordered_map<int, int> days_to_blooms;
    for (int i = 0; i < flowers.size(); ++i)
        days_to_blooms[flowers[i]] = i;
    int start_day = 1;
    unordered_set<int> current_blooms;
    while (start_day <= flowers.size()) {
        int current_bloom_index = days_to_blooms[start_day];
        int possible_previous_bloom_index = current_bloom_index - k - 1;
        int possible_next_bloom_index = current_bloom_index + k + 1;
        if (possible_previous_bloom_index >= 0 && 
            current_blooms.find(possible_previous_bloom_index) != current_blooms.end() && 
            isNoBloomsInBetween(current_blooms, possible_previous_bloom_index, current_bloom_index))
            return start_day;
        if (possible_next_bloom_index < flowers.size() &&
            current_blooms.find(possible_next_bloom_index) != current_blooms.end() &&
            isNoBloomsInBetween(current_blooms, current_bloom_index, possible_next_bloom_index))
            return start_day;
        ++start_day;
        current_blooms.insert(current_bloom_index);
    }

    return -1;
}

int main(int argc, char* argv[]) {
    vector<int> x;
    int k;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        x.push_back(k);
    }
    cin >> k;
    cout << KEmptySlots(x, k) << endl;;
}