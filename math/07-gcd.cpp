#include <bits/stdc++.h>
using namespace std;

// method 1: 1 -> min(a,b)
int gcd_brute(int a, int b) {
  int gcd = 1;
  int n = min(a, b);

  for (int i = 1; i < n; i++)
    if (a % i == 0 and b % i == 0)
      gcd = i;
  return gcd;
}

// method 2: since want greatest min(a,b) -> 1
int gcd_better(int a, int b) {
  int n = min(a, b);
  for (int i = n; i >= 1; i--)
    if (a % i == 0 and b % i == 0)
      return i;
  return 1;
}

int gcd_euclidian(int a, int b) {
  while (b) {
    int temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}

int main() {
  cout << gcd_brute(20, 28) << endl;
  cout << gcd_brute(544, 119) << endl;
  cout << gcd_better(20, 28) << endl;
  cout << gcd_better(270, 192) << endl;
  cout << gcd_euclidian(48, 18) << endl;
  cout << gcd_euclidian(56, 98) << endl;
  return 0;
}
