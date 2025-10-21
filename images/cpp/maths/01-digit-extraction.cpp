#include <bits/stdc++.h>
using namespace std;

int countDigits(int n)
{
    int count = 0;
    while (n)
    {
        count++;
        n /= 10;
    }
    return count;
    return (int)(log10(n) + 1); // this is alternate method (using log)
}

void extractDigits(int n)
{
    while (n)
    {
        int rem = n % 10;
        n /= 10;
        cout << rem << endl;
    }
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    // number of times is count of digits O(LogN)

    extractDigits(n);
    cout << countDigits(n) << endl;
    return 0;
}