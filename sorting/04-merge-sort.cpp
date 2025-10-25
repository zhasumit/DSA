#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int low, int mid, int high) {
  int n = high - low + 1; // since low minimal size array
  int temp[n];

  int i = low;     // pointer to left subarray
  int j = mid + 1; // pointer to right subarray
  int k = 0;       // pointer to temp subarray

  while (i <= mid and j <= high)
    if (arr[i] < arr[j])
      temp[k++] = arr[i++];
    else
      temp[k++] = arr[j++];

  // if something is left in i or j sections
  while (i <= mid)
    temp[k++] = arr[i++];
  while (j <= high)
    temp[k++] = arr[j++];

  // i goes from 0 to n-1, iterating over temp[].
  // low + i gives the correct position in arr for each element.
  // since low can start from after i somewhere
  for (int i = 0; i < n; i++)
    arr[low + i] = temp[i];
}

void mergeSort(int *arr, int low, int high) {
  if (low == high)
    return;
  int mid = (low + high) / 2;
  mergeSort(arr, low, mid);
  mergeSort(arr, mid + 1, high);
  merge(arr, low, mid, high);
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
  mergeSort(arr, 0, n - 1);
  printArray(arr, n);

  return 0;
}
