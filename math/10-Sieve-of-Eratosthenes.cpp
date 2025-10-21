#include <bits/stdc++.h>
using namespace std;

// given a number n print all the primes till that number
// n = 7, so 2,3,5,7
// naively it could be done for (2->n) and check for all the prime

// for brute force check O(n√n), √n for isPrime, n for going till n
void printAllPrimes(int n);
bool isPrime(int n);

// seive of eratosthenes
// do prime check in order O(1)
vector<bool> sieve(int n) {
  // make an array of primes
  vector<bool> primes(n + 1, true);
  // make first two as non-prime
  primes[0] = primes[1] = false;

  // since after ixi the number exceeds n already so go till ixi
  for (int i = 2; i * i <= n; i++)
    if (primes[i]) // if only prime make all the multiples false
      for (int j = i * i; j <= n; j += i) // +i jump to make multiples false
        primes[j] = false; // multiples are made false (j is +i multiple)

  return primes; // whatever remained as true are primes
}

void printBooleanVector(vector<bool> a) {
  for (int i = 0; i < a.size(); i++)
    if (a[i])
      cout << i << " ";
  cout << endl;
}

int main() {
  printAllPrimes(50);
  vector<bool> primes = sieve(50);
  printBooleanVector(primes);
  return 0;
}

// simple check for individual number
bool isPrime(int n) {
  if (n <= 1)
    return false;
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0)
      return false;
  return true;
}

void printAllPrimes(int n) {
  for (int i = 2; i < n; i++)
    if (isPrime(i))
      cout << i << " ";
  cout << endl;
}
