#include <bits/stdc++.h>
using namespace std;

void printDeque(deque<int> &dq)
{
    for (auto val : dq)
        cout << val << " ";
    cout << endl;
}

int main()
{
    deque<int> dq;

    dq.push_back(10);
    printDeque(dq); // 10

    dq.emplace_back(20);
    printDeque(dq); // 10 20

    dq.push_front(5);
    printDeque(dq); // 5 10 20

    dq.emplace_front(1);
    printDeque(dq); // 1 5 10 20

    dq.pop_back();
    dq.pop_front();
    printDeque(dq); // 5 10

    cout << dq.back() << endl;  // 10
    cout << dq.front() << endl; // 5

    return 0;
}