#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> computeFrequency(string a, unordered_map<char, int> alphanums) {

    vector<int> frequencies(26, 0);
    for (auto each: a) 
        frequencies[alphanums[each]] += 1;

    return frequencies;
}

int computeMax(vector<int> frequency) {
    int maximum = frequency[0];
    for (auto each: frequency) {
        if (each > maximum)
            maximum = each;
    }

    return maximum;
}

int computeMin(vector<int> costs) {
    int minimum = costs[0];
    for (auto each: costs) {
        if (each < minimum)
            minimum = each;
    }

    return minimum;
}

int computeSum(vector<int> frequency, int start, int end) {

    int result = 0;
    for (int i = start; i <= end; i++)
        result = result + frequency[i];
    return result;
}

int minCharacters(string a, string b) {
    
    string alphas = "abcdefghijklmnopqrstuvwxyz";
    unordered_map<char, int> alphanums;
    int denoms = 0;
    for (auto each: alphas)
        alphanums[each] = denoms++;

    vector<int> frequency_a = computeFrequency(a, alphanums);
    vector<int> frequency_b = computeFrequency(b, alphanums);

    int max_a = computeMax(frequency_a);
    int max_b = computeMax(frequency_b);

    int len_a = a.size();
    int len_b = b.size();

    vector<int> operation_costs = {(len_a + len_b) - (max_a + max_b)};

    int start = 1;
    int end = 0;

    while (end <= 24 && start <= 25) {
        int sum = computeSum(frequency_a, 0, end) + computeSum(frequency_b, start, 25);
        operation_costs.push_back(sum);
        end += 1;
        start += 1;
    }

    start = 1;
    end = 0;

    while (end <= 24 && start <= 25) {
        int sum = computeSum(frequency_b, 0, end) + computeSum(frequency_a, start, 25);
        operation_costs.push_back(sum);
        end += 1;
        start += 1;
    }

    return computeMin(operation_costs);
}


int main(int argc, char* argv[]) {

    cout << minCharacters("aba", "caa") << endl;
    cout << minCharacters("dabadd", "cda") << endl;
    cout << minCharacters("abe", "ace") << endl;
    cout << minCharacters("otpaynexxlngyrdmand", "twtyifiiundfejxfktclktjnqrmycnqmxhxfitnlasyuwotjguerenjjnpkaajsnnraopdnambfccwthppimijghg") << endl;

    return 0;

}

