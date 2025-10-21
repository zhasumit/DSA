#include <bits/stdc++.h>
using namespace std;

void print1toN(int i, int n) {
  if (i == n + 1) {
    cout << "------\n";
    return;
  }
  cout << i << endl;
  print1toN(++i, n);
}

void print1toN(int n) {
  if (n == 0) {
    cout << "------\n";
    return;
  }
  print1toN(n - 1);
  cout << n << endl;
}

int main() {
  int n = 20;
  print1toN(1, 10);
  print1toN(5);
  return 0;
}
