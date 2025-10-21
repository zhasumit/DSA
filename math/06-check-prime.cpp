#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
  if (n <= 1)
    return false;
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0)
      return false;
  return true;
}

int main() {
  cout << isPrime(27) << endl;
  cout << isPrime(21) << endl;
  cout << isPrime(13) << endl;
  cout << isPrime(3) << endl;
  cout << isPrime(5) << endl;
  cout << isPrime(71) << endl;
  return 0;
}
