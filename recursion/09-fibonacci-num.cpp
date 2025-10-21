#include <bits/stdc++.h>
using namespace std;

void printFibonacciSeries(int n);
int getNthFibonacciNumber(int n);

int Fib(int n) {
  if (n <= 1)
    return n;
  return Fib(n - 1) + Fib(n - 2);
}

int main() {
  // getting for loop for getting the fib series
  printFibonacciSeries(10);
  cout << getNthFibonacciNumber(10) << endl;

  cout << Fib(10);

  return 0;
}

// getting series using for loop
void printFibonacciSeries(int n) {
  int a = 0, b = 1; // first two fibs
  for (int i = 0; i < n; i++) {
    cout << a << " ";
    int next = a + b;
    a = b;
    b = next;
  }
  cout << endl;
}

// getting series using for loop
int getNthFibonacciNumber(int n) {
  if (n == 0 || n == 1)
    return n;
  int a = 0, b = 1, ans; // first two fibs and ans
  for (int i = 2; i <= n; i++) {
    ans = a + b;
    a = b;
    b = ans;
  }
  return ans;
}
