#include <bits/stdc++.h>
using namespace std;

void recursiveInsertionSort(int *arr, int i, int n) {
  if (i == n)
    return;

  // removed the upper loop for i = 0 -> n (rec call)
  for (int j = i; j > 0; j--)
    if (arr[j] < arr[j - 1])
      swap(arr[j], arr[j - 1]);
    else
      break;
  recursiveInsertionSort(arr, i + 1, n);
}

void printArray(int *arr, int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int main() {
  int arr[] = {3, 5, 1, 3, -1, 5, 2, -10};
  int n = sizeof(arr) / sizeof(int);

  printArray(arr, n);
  recursiveInsertionSort(arr, 0, n);
  printArray(arr, n);

  return 0;
}
