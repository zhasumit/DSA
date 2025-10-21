#include <bits/stdc++.h>
using namespace std;
int getGCD(int a, int b) {
  while (b) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

int commonFactors(int a, int b) {
  int cnt = 0;
  int n = getGCD(a, b);
  for (int i = 1; i * i <= n; i++)
    if (n % i == 0) {
      cnt++;
      if (i != n / i)
        cnt++;
    }
  return cnt;
}

int main() {
  // int n;
  // cin >> n;
  int n = 36;
  // go till n and then if divisible print it
  for (int i = 1; i <= n; i++)
    if (n % i == 0)
      cout << i << " ";
  cout << endl;

  // for going till the multiplyable pairs match
  vector<int> ls;
  for (int i = 1; i * i <= n; i++)
    if (n % i == 0) {
      ls.push_back(i);
      if (i != n / i)
        ls.push_back(n / i);
    }

  sort(ls.begin(), ls.end());
  for (auto it : ls)
    cout << it << " ";
  cout << endl;
  return 0;
}
