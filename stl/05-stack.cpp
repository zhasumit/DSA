#include <bits/stdc++.h>
using namespace std;

void printStack(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> st;
    cout << st.empty() << endl; // 1

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(3);
    st.emplace(5);
    printStack(st); // 5 3 3 2 1

    cout << st.top() << endl;  // 5
    cout << st.size() << endl; // 5

    st.pop();
    cout << st.size() << endl; // 4

    printStack(st); // 3 3 2 1

    stack<int> st1, st2;
    // for swapping
    st1.swap(st2);
    return 0;
}