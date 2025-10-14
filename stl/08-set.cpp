#include <bits/stdc++.h>
using namespace std;

void printSet(set<int> s)
{
    while (!s.empty())
    {
        cout << *s.begin() << " ";
        s.erase(s.begin());
    }
    cout << endl;
}

int main()
{
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(10);
    s.insert(3);
    s.insert(2);
    s.insert(4);
    s.insert(3);
    printSet(s);

    auto it = s.find(3);
    cout << *it << endl; // 3

    it = s.find(100); // no element so returns s.end()

    it = s.find(2); // since returns the iterator after finding
    s.erase(10);    // removes element using value
    s.erase(it);    // removes using iterator

    // 1 3 4
    for (auto it = s.begin(); it != s.end(); it++)
        cout << *it << " ";
    cout << endl;

    cout << s.count(10) << endl; // 0 (returns True or False)

    set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto it1 = s1.find(4);
    auto it2 = s1.find(7);
    s1.erase(it1, it2);
    printSet(s1); // [start, end) is erased (1 2 3 7 8 9 10) remains

    cout << *(s1.lower_bound(3)) << endl;
    cout << *(s1.lower_bound(5)) << endl;
    cout << *(s1.lower_bound(6)) << endl;

    cout << *(s1.upper_bound(1)) << endl;
    cout << *(s1.upper_bound(5)) << endl;
    cout << *(s1.upper_bound(6)) << endl;
    cout << *(s1.upper_bound(9)) << endl;

    unordered_set<int> us;
    return 0;
}