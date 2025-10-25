#include <bits/stdc++.h>
using namespace std;

int randomizedPartition(int *arr, int low, int high) {
  // pick random between low -> high (random offset from low (high-low+1))
  int randomIndex = low + rand() % (high - low + 1);
  swap(arr[low], arr[randomIndex]);
  int pivot = arr[low]; // since hoarse algo is designed on low
  int i = low - 1, j = high + 1;

  while (true) {
    do
      i++;
    while (arr[i] < pivot); // move till element < pivot
    do
      j--;
    while (arr[j] > pivot); // move till element > pivot
    if (i >= j)
      return j;           // return splitted index
    swap(arr[i], arr[j]); // swap out of place elements
  }
}

void randomizedQuickSort(int *arr, int low, int high) {
  if (low < high) {
    int pivot = randomizedPartition(arr, low, high);
    randomizedQuickSort(arr, low, pivot);      // left side
    randomizedQuickSort(arr, pivot + 1, high); // right side
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
  randomizedQuickSort(arr, 0, n - 1);
  printArray(arr, n);

  return 0;
}
