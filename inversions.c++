#include <iostream>
#include <vector>

using namespace std;


int merge(vector<int>& arr, int left_count, int right_count, int start, int middle, int end) {

  int inversion_count = 0;
  int right_smaller = 0;

  vector<int> left_arr;
  vector<int> right_arr;

  for (int i = start; i <= middle; ++i)
    left_arr.push_back(arr[i]);
  for (int i = middle + 1; i <= end; ++i)
    right_arr.push_back(arr[i]);


  int pointer1 = 0;
  int pointer2 = 0;
  int pointer3 = start;
  int end1 = middle - start;
  int end2 = end - middle - 1;

  while (pointer1 <= end1 && pointer2 <= end2) {

    int number1 = left_arr[pointer1];
    int number2 = right_arr[pointer2];

    if (number1 == number2) {
      arr[pointer3] = number1;
      ++pointer3;
      ++pointer1;
      arr[pointer3] = number2;
      ++pointer3;
      ++pointer2;
    }

    else if (number1 < number2) {
      inversion_count += right_smaller;
      arr[pointer3] = number1;
      ++pointer3;
      ++pointer1;
    }

    else if (number2 < number1) {
      ++right_smaller;
      arr[pointer3] = number2;
      ++pointer3;
      ++pointer2;
    }

  }

  while (pointer1 <= end1) {
    int number1 = left_arr[pointer1];
    inversion_count += right_smaller;
    arr[pointer3] = number1;
    ++pointer3;
    ++pointer1;
  }

  while (pointer2 <= end2) {
    int number2 = right_arr[pointer2];
    arr[pointer3] = number2;
    ++pointer3;
    ++pointer2;
  }

  return left_count + inversion_count + right_count;
}


int mergeSort(vector<int>& arr, int start, int end) {

  if (start >= end) 
    return 0;
  
  int middle_index = (start + end) / 2;
  int left_count = mergeSort(arr, start, middle_index);
  int right_count = mergeSort(arr, middle_index + 1, end);
  return merge(arr, left_count, right_count, start, middle_index, end);
  
}


void print(vector<int>& arr) {
  for (int each: arr)
    cout << each << '\t';
  cout << endl;
  return;
}

int main(int argc, char* argv[]) {

  vector<int> arr1 = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  vector<int> arr2 = {2, 5, 7, 1, 6, 3, 0};

  print(arr1);
  cout << mergeSort(arr1, 0, arr1.size() - 1) << endl;
  print(arr1);
  print(arr2);
  cout << mergeSort(arr2, 0, arr2.size() - 1) << endl;
  print(arr2);

  return 0;
}






