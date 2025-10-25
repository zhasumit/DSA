#include <bits/stdc++.h>
using namespace std;

// push the maximum element at the end (bubbles rise)
// adjacent swapping is done (no final swapping)
// everytime the last element is sorted so go till n-1-i
void bubbleSort(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    bool swapped = false;
    for (int j = 0; j < n - 1 - i; j++)
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    if (!swapped)
      return;
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

  bubbleSort(arr, n);
  printArray(arr, n);

  return 0;
}
