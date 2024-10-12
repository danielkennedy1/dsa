#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> vec, int left, int mid, int right) {
  int leftSubarrayLength = mid - left + 1;
  int rightSubarrayLength = right - mid;

  vector<int> leftSubarray(leftSubarrayLength), rightSubarray(rightSubarrayLength);

  for (int i = 0; i < leftSubarrayLength; i++) {
    leftSubarray[i] = vec[left + i];
  }
  for (int i = 0; i < rightSubarrayLength; i++) {
    rightSubarray[i] = vec[mid + 1 + i];
  }
  int i = 0, j = 0, k = left;

  while (i < leftSubarrayLength && j < rightSubarrayLength) {
    if (leftSubarray[i] <= rightSubarray[j]) {
      vec[k] = leftSubarray[i];
      i++;
    } else {
      vec[k] = rightSubarray[j];
      j++;
    }
    k++;
  }

  while (i < leftSubarrayLength) {
    vec[k] = leftSubarray[i];
    i++;
    j++;
  }

  while (j < rightSubarrayLength) {
    vec[k] = rightSubarray[j];
    i++;
    j++;
  }

}

void mergeSort(vector<int> vec, int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;

    mergeSort(vec, left, mid);
    mergeSort(vec, mid + 1, right);

    merge(vec, left, mid, right);
  }
}

int main() {
    vector<int> vec = {12, 11, 13, 5, 6, 7};
    int n = vec.size();

    // Sorting vec using mergesort
    mergeSort(vec, 0, n - 1);

    for (auto i: vec)
        cout << i << " ";
    return 0;
}

