#include <bits/stdc++.h>
using namespace std;

void recursiveSelectionSort(int *arr, int i, int n) {
  if (i == n)
    return;
  int minIndex = i;
  // just removed upper loop and made recursive call
  for (int j = i; j < n; j++)
    if (arr[minIndex] > arr[j])
      minIndex = j;
  swap(arr[minIndex], arr[i]);
  recursiveSelectionSort(arr, i + 1, n);
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
  recursiveSelectionSort(arr, 0, n);
  printArray(arr, n);

  return 0;
}
