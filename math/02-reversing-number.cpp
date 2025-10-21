#include <bits/stdc++.h>
using namespace std;

int reverse(int n) {
  int reversed = 0;
  while (n) {
    int rem = n % 10;
    reversed = reversed * 10 + rem;
    n /= 10;
  }
  return reversed;
}

string reverse_padded(int n) {
  string reversed = "";
  while (n) {
    int rem = n % 10;
    reversed += to_string(rem);
    n /= 10;
  }
  return reversed;
}

int main() {
  int n;
  cout << "Enter n: ";
  cin >> n;
  cout << reverse(n) << endl;
  cout << reverse_padded(n) << endl;
  return 0;
}
