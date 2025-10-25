#include <bits/stdc++.h>
using namespace std;

int partition(int *arr, int low, int high) {
  int i = low - 1, j = high + 1;
  int pivot = arr[low];
  // Hoare's scheme (do while), since moves once at least
  while (true) {
    do
      i++;
    while (arr[i] < pivot); // find bigger on i
    do
      j--;
    while (arr[j] > pivot); // find smaller on j
    if (i >= j)
      return j; // returns the splitted index
    swap(arr[i], arr[j]);
  }
}

void quickSort(int *arr, int low, int high) {
  if (low < high) {
    int pivot = partition(arr, low, high);
    quickSort(arr, low, pivot);      // left side
    quickSort(arr, pivot + 1, high); // right side
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
  quickSort(arr, 0, n - 1);
  printArray(arr, n);

  return 0;
}
