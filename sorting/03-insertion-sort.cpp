#include <bits/stdc++.h>
using namespace std;

// insert the element at the correct position (insertion)
// start the pointer with i = 0, and the increase the pointer i++
// check if current position i is on the correct position
// how to check ? if the a[i-1] < a[i], while that swap the i-1 and i

void insertionSort(int *arr, int n) {
  // starts with 1 since 0 already sorted
  for (int i = 1; i < n; i++)
    for (int j = i; j > 0; j--)
      if (arr[j] < arr[j - 1])
        swap(arr[j], arr[j - 1]);
      else
        break;
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
  insertionSort(arr, n);
  printArray(arr, n);

  return 0;
}
