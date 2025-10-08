#include <bits/stdc++.h>
using namespace std;

void printPriorityQueue(priority_queue<int> pq)
{
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

void printMinPriorityQueue(priority_queue<int, vector<int>, greater<int>> pq)
{
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

int main()
{
    priority_queue<int> pq;
    cout << pq.empty() << endl; // 1

    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.push(10);
    pq.push(6);

    cout << pq.top() << endl;   // 10
    cout << pq.empty() << endl; // 0

    pq.pop();
    printPriorityQueue(pq); // 8 6 5 2

    cout << pq.size() << endl; // 4

    priority_queue<int> pq1;
    pq1.push(-6);
    pq1.push(0);
    pq1.push(4);
    pq.swap(pq1);
    printPriorityQueue(pq);  // 4 0 -6
    printPriorityQueue(pq1); // 8 6 5 2

    // min heap
    priority_queue<int, vector<int>, greater<int>> pq2;
    pq2.push(5);
    pq2.push(2);
    pq2.push(8);
    pq2.push(10);
    pq2.push(6);
    printMinPriorityQueue(pq2); // 2 5 6 8 10
    return 0;
}