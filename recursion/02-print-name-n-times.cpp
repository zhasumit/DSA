#include <bits/stdc++.h>
using namespace std;

void printname(int i, int n) {
  if (i == n)
    return;
  cout << "sumit\n";
  printname(++i, n);
}

void printname(int n) {
  if (n == 0)
    return;
  cout << "sumit\n";
  printname(--n);
}

int main() {
  printname(0, 5);
  cout << "-------------\n";
  printname(5);
  return 0;
}
