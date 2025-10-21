#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(int n)
{
    int reversed = 0;
    int temp = n;
    while (temp)
    {
        int rem = temp % 10;
        temp /= 10;
        reversed = reversed * 10 + rem;
    }
    return (reversed == n);
}

int main()
{
    cout << checkPalindrome(123) << endl;
    cout << checkPalindrome(121) << endl;
    cout << checkPalindrome(1245421) << endl;
    cout << checkPalindrome(11) << endl;
    cout << checkPalindrome(10) << endl;
    cout << checkPalindrome(5) << endl;
    return 0;
}