#include <bits/stdc++.h>
using namespace std;

int partition(int *arr, int low, int high) {
  int pivot = arr[low];
  int i = low - 1, j = high + 1;
  while (true) {
    do
      i++;
    while (arr[i] > pivot);
    do
      j--;
    while (arr[j] < pivot);
    if (i >= j)
      return j;
    swap(arr[i], arr[j]);
  }
}

void quickSortDec(int *arr, int low, int high) {
  if (low < high) {
    int pivot = partition(arr, low, high);
    quickSortDec(arr, low, pivot);
    quickSortDec(arr, pivot + 1, high);
  }
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
  quickSortDec(arr, 0, n - 1);
  printArray(arr, n);

  return 0;
}
