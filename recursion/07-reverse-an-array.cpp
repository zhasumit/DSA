#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[], int n, int i = 0) {
  if (i >= n / 2)
    return;
  swap(arr[i], arr[n - 1 - i]);
  reverse(arr, n, i + 1);
}

void printArray(int *a, int n) {
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << endl;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int n = sizeof(arr) / sizeof(int);
  cout << "Before: ";
  printArray(arr, n);

  // if nothing is given for i, so i = 0, reverse from start
  reverse(arr, n);

  cout << "After: ";
  printArray(arr, n);
  return 0;
}
