#include <bits/stdc++.h>
using namespace std;

// donot do this just for demo (can go till 4GB size)
// outside (globally) it can go till 10^9
// int hash[10000000] = {0};

// so max we can go till is 10^6 or 10^7 mostly
void countFreq(int *arr, int n, int *hash) {
  for (int i = 0; i < n; i++)
    hash[arr[i]] += 1;
}

int main() {
  int arr[] = {1, 3, 5, 3, 5, 3, 53, 4,  6, 7,  10, 5, 6, 7, 2,
               6, 7, 5, 5, 3, 2, 3,  24, 2, 53, 34, 6, 7, 5};
  int hash[100] = {0}; // inside it can go till 10^6
  countFreq(arr, sizeof(arr) / sizeof(int), hash);
  cout << "Number\tFreq\n";
  cout << "-------------\n";
  for (int i = 0; i < 100; i++)
    if (hash[i])
      cout << i << "\t" << hash[i] << "\n";
  return 0;
}
