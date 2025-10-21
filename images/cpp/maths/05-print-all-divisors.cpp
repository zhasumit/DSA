#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    // go till n and then if divisible print it 
    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            cout << i << " ";
    cout << endl;
    return 0;
}