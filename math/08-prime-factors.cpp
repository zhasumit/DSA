#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0)
      return false;
  return true;
}
vector<int> getPrimeFactors_brute(int n) {
  vector<int> primeFactors;
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) {
      if (isPrime(i))
        primeFactors.push_back(i);
      if (i != n / i && isPrime(n / i))
        primeFactors.push_back(n / i);
    }
  sort(primeFactors.begin(), primeFactors.end());
  return primeFactors;
}

vector<int> getPrimeFactors_reduction(int n) {
  vector<int> primeFactors;
  // 0(√n) for loop * logN for reduction(of multiples), so we donot get
  // composites
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0)
      primeFactors.push_back(i);
    // reduce (burn out all the multiples of current number i)
    while (n % i == 0)
      n = n / i;
  }
  // reached a prime number after all the reduction cannot go any further
  if (n != 1)
    primeFactors.emplace_back(n);
  sort(primeFactors.begin(), primeFactors.end());
  return primeFactors;
}

void printVector(vector<int> &vec) {
  for (auto it : vec)
    cout << it << " ";
  cout << endl;
}

int main() {
  int n = 100;
  vector<int> ans = getPrimeFactors_brute(n);
  printVector(ans);
  ans = getPrimeFactors_reduction(780);
  printVector(ans);
  return 0;
}
