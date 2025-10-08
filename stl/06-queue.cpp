#include <bits/stdc++.h>
using namespace std;

void printQueue(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    printQueue(q); // 1 2 3

    q.pop();
    printQueue(q); // 2 3

    q.emplace(4);
    printQueue(q); // 2 3 4

    cout << q.front() << endl; // 2
    cout << q.back() << endl;  // 4
    cout << q.size() << endl;  // 3

    cout << q.empty() << endl; // 0

    queue<int> q1;
    // for swapping
    q1.swap(q);
    printQueue(q1); // 2 3 4
    printQueue(q);  // empty
    return 0;
}