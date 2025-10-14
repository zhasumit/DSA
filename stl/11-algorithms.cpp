#include <bits/stdc++.h>
using namespace std;

void printvector(vector<int> vec)
{
    for (auto it : vec)
        cout << it << " ";
    cout << endl;
}

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    // if the second part is smaller return current to be the smaller
    if (p1.second < p2.second)
        return true;
    if (p1.second > p2.second)
        return false;
    // <, > happened so it is same
    if (p1.first > p2.first)
        return true;
    return false;
    // or simply return p1.first > p2.first
}

int main()
{
    vector<int> vec = {1, 5, 2, -1, 3, 2};
    sort(vec.begin(), vec.end());
    printvector(vec);

    // greater<int>() is a comparator to sort in decending order
    sort(vec.begin(), vec.end(), greater<int>());
    printvector(vec);

    pair<int, int> a[] = {{1, 2}, {2, 1}, {4, 1}};
    // sort as per the second element in ascending order
    // if second is same then sort as per the first element in descending
    int n = sizeof(a) / sizeof(a[0]);
    sort(a, a + n, comp);
    for (auto it : a)
        cout << it.first << " " << it.second << endl;

    // returning number of set bits in a number
    int num = 7;
    int cnt = __builtin_popcount(num);
    cout << cnt << endl;
    
    long long number = 1679482647203;
    cnt = __builtin_popcountll(number);
    cout << cnt << endl;

    string s = "123";
    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
    // returns false if no more permutations

    int maxi = *max_element(vec.begin(), vec.end());
    cout << maxi << endl;
    return 0;
}