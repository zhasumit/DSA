#include <bits/stdc++.h>
using namespace std;

void printMultiset(multiset<int> ms)
{
    while (!ms.empty())
    {
        cout << *ms.begin() << " ";
        ms.erase(ms.begin());
    }
    cout << endl;
}

int main()
{
    multiset<int> ms;
    ms.insert(1);
    ms.insert(2);
    ms.insert(3);
    ms.insert(4);
    ms.insert(1);
    ms.insert(4);
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    printMultiset(ms);

    cout << ms.count(1) << endl;
    cout << ms.count(4) << endl;

    // removes all the 4
    ms.erase(4);
    printMultiset(ms);

    // erase using iterator
    ms.erase(ms.find(1));
    cout << ms.count(1) << endl;
    printMultiset(ms);
    
    auto it1 = ms.find(1);
    auto it2 = it1;
    std::advance(it2, 2); // modifies it2 directly
    ms.erase(it1, it2);
    cout << ms.count(1) << endl;
    printMultiset(ms);

    return 0;
}