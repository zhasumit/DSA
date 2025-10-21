#include <bits/stdc++.h>
using namespace std;

// O(log2n) since division by 2
double power(int a, int b) {
  double ans = 1;
  double base = a;
  int exp = abs(b);

  while (exp > 0) {
    if (exp % 2 == 1) { // balance the power and make it even
      ans *= base;
      exp--;
    } else { // make the power reduction by half everytime
      base *= base;
      exp /= 2;
    }
  }
  return b < 0 ? 1.0 / ans : ans;
}

int main() {
  cout << power(2, 13) << endl;
  return 0;
}
