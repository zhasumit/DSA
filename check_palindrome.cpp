#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/valid-palindrome/

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
bool isPalindrome(string s)
{
    string filtered;
    // get only the alpha numeric string values (not special characters)
    // make the characters uniform (not uppercased)
    for (char ch : s)
        if (isalnum(ch))
            filtered += tolower(ch);

    // take two pointers for palindrome check and move towards center
    int left = 0;
    int right = filtered.size() - 1;
    while (left < right)
    {
        if (filtered[left] != filtered[right])
            return false;
        left++, right--;
    }
    return true;
}


int main()
{

    return 0;
}
