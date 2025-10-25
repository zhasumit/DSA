#include <bits/stdc++.h>
using namespace std;

void bubbleSortRec(int *arr, int n) {
  if (n <= 0)
    return;

  bool swapped = false;
  // since the i loop is taken by recursion itself
  for (int j = 0; j < n - 1; j++)
    if (arr[j] > arr[j + 1]) {
      swap(arr[j], arr[j + 1]);
      swapped = true;
    }
  if (!swapped) // already sorted
    return;
  bubbleSortRec(arr, n - 1);
}

void printArray(int *arr, int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int main() {
  int arr[] = {3, 5, 1, 3, -1, 5, 2, -10};
  int n = sizeof(arr) / sizeof(int);

  bubbleSortRec(arr, n);
  printArray(arr, n);

  return 0;
}
