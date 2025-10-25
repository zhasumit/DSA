#include <bits/stdc++.h>
using namespace std;

// selection : select something (min/max)
// move the pointer and look in the next range for the min/max

void selectionSortAsc(int *arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++)
      if (arr[j] < arr[minIndex])
        minIndex = j;
    // swap the element at minIndex and current pointer
    if (minIndex != i) {
      int temp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = temp;
    }
  }
}

void selectionSortDes(int *arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    int maxIndex = i;
    for (int j = i + 1; j < n; j++)
      if (arr[maxIndex] < arr[j])
        maxIndex = j;
    // swap maxIndex with the current pointer for desending effect
    if (maxIndex != i) {
      int temp = arr[i];
      arr[i] = arr[maxIndex];
      arr[maxIndex] = temp;
    }
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
  selectionSortAsc(arr, n);
  printArray(arr, n);

  selectionSortDes(arr, n);
  printArray(arr, n);

  return 0;
}
