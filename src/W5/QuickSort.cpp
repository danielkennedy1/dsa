#include <vector>
#include <iostream>

using namespace std;

void swap (int a, int b) {
  int t = a;
  a = b;
  b = t;
}


void quicksort(vector<int> arr, int left, int right) {
  if (right - left <= 1) return;
  int pivot = arr[left];
  cout << "Pivot is " << pivot << endl;
  
  int i = left;
  int j = right;

  while (i < j){
    cout << "i: " << i << "j: " << j << endl;
    while (arr[++i] < pivot) {
      cout << arr[i] << " at index " << i << " is less than the pivot" << endl;
    }
    while (arr[--j] > pivot) {
      cout << arr[j] << " at index " << j << " is greater than the pivot" << endl;
    }

    cout << "swapping " << arr[i] << " and " << arr[j] << endl;
    swap(arr[i], arr[j]);
  }

  swap(arr[left], arr[i]);

  //quicksort(arr, left, i-1);
  //quicksort(arr, i, right);
}

int main() {
    vector<int> vec = {12, 11, 13, 5, 6, 7};
    quicksort(vec, 0, vec.size());
    for (int i = 0; i < vec.size(); i++) cout << vec[i] << ", ";
}
