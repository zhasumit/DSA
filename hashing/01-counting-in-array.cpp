#include <iostream>
using namespace std;

void countArrayFrequency(int arr[], int n, int freq[]) {
  bool visited[n]; // to mark visited elements
  for (int i = 0; i < n; i++)
    visited[i] = false;

  for (int i = 0; i < n; i++) {
    if (visited[i])
      continue; // skip if already counted

    int count = 0;
    // count occurrences of arr[i]
    for (int j = 0; j < n; j++) {
      if (arr[j] == arr[i]) {
        count++;
      }
    }

    // assign the same count to all matching elements
    for (int j = 0; j < n; j++) {
      if (arr[j] == arr[i]) {
        freq[j] = count;
        visited[j] = true;
      }
    }
  }
}

int main() {
  int arr[] = {42, 7, 7, 15, 42, 42, 3, 15, 7};
  int n = sizeof(arr) / sizeof(arr[0]);
  int freq[n];

  countArrayFrequency(arr, n, freq);

  cout << "Index\tValue\tFreq\n";
  cout << "--------------------\n";
  for (int i = 0; i < n; i++)
    cout << i << "\t" << arr[i] << "\t" << freq[i] << "\n";

  return 0;
}
