#include <iostream>
#include <vector>

using namespace std;

int main() {
    int M = 7;
    vector<int> arr = {5, 2, 2, 1};
    vector<int> buckets(M);

    for (int i = 0; i < arr.size(); i++)
        buckets[arr[i]]++;

    arr.clear();

    for (int i = 0; i < buckets.size(); i++) {
        for (int j = 0; j < buckets[i]; j++)
            arr.push_back(i);
    }

    for (int num : arr)
        cout << num << ", ";

    return 0;
}
