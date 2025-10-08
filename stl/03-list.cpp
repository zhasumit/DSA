#include <bits/stdc++.h>
using namespace std;

void printList(list<int> &ls)
{
    for (auto val : ls)
        cout << val << " ";
    cout << endl;
}

int main()
{
    list<int> ls;

    ls.push_back(10);
    printList(ls); // 10

    ls.emplace_back(20);
    printList(ls); // 10 20

    ls.push_front(5);
    printList(ls); // 5 10 20

    ls.emplace_front(1);
    printList(ls); // 1 5 10 20

    return 0;
}