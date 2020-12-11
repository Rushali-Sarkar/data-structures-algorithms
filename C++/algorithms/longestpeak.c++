#include<iostream>
#include<vector>

using namespace std;

vector<int> findallpeaks(vector<int> arr) {
    
    vector<int> peaks;
    for (int i = 1; i < arr.size() - 1; i++) {

      if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
        peaks.push_back(i);

    }
  return peaks;
}

int longestpeak(vector<int> arr) {

    vector<int> peaks = findallpeaks(arr);
    int peak_length  = 1;
    int longest_peak = -1;

    for (auto peak: peaks) {

        int left = peak - 1;
        int left_compare = peak;
        int right_compare = peak;
        int right = peak + 1;

        while (left >= 0) {
            
            if (arr[left] < arr[left_compare]) {
                peak_length++;
                left--;
                left_compare--;
            }
            
            else
                break;
            }
        
        while (right < arr.size()) {

            if (arr[right] < arr[right_compare]) {
                peak_length++;
                right++;
                right_compare++;
            }

            else
                break;
        }

        if (peak_length > longest_peak)
            longest_peak = peak_length;

        peak_length = 1;
    }

    return longest_peak;
}         
                

int main(int argc, char* argv[]) {

    vector<int> arr = {1, 2, 3, 3, 4, 0, 10, 6, 5, -1, -3, 2, 3};
    vector<int> peaks = findallpeaks(arr);
    cout << longestpeak(arr) << endl;
    return 0;
}

