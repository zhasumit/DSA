#include <bits/stdc++.h>
using namespace std;
int digitsCount(int n)
{
    int cnt = 0;
    while (n)
    {
        int rem = n % 10;
        n /= 10;
        cnt++;
    }
    return cnt;
}

bool armstrongNumber(int n)
{
    int p = digitsCount(n);
    int total = 0;
    int temp = n;
    while (temp)
    {
        int rem = temp % 10;
        temp /= 10;
        total += pow(rem, p);
    }
    return total == n;
}

int main()
{
    cout << armstrongNumber(153) << endl;
    cout << armstrongNumber(372) << endl;
    cout << armstrongNumber(100) << endl;
    return 0;
}