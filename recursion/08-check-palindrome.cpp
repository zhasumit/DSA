#include <bits/stdc++.h>
using namespace std;

// for integer types
bool isPalindrome(int arr[], int n, int i = 0) {
  if (i >= n / 2)
    return true;
  if (arr[i] != arr[n - 1 - i])
    return false;
  return isPalindrome(arr, n, i + 1);
}

// for string
bool isPalindrome(string s, int i = 0) {
  if (i >= s.size() / 2)
    return true;
  if (s[i] != s[s.size() - i - 1])
    return false;
  return isPalindrome(s, i + 1);
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  cout << isPalindrome(arr, sizeof(arr) / sizeof(int)) << endl;
  int arr1[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
  cout << isPalindrome(arr1, sizeof(arr1) / sizeof(int)) << endl;

  // for the strings (since size(), i have not taken n)
  cout << isPalindrome("MADAM") << endl;
  cout << isPalindrome("docker") << endl;
  cout << isPalindrome("c") << endl;
  return 0;
}
