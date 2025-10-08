#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &vec)
{
    for (int val : vec)
        cout << val << " ";
    cout << endl;
}

int main()
{
    // declarations
    vector<int> vec;

    vec.push_back(20);
    vec.emplace_back(30);

    // access
    vector<int> v = {1, 2, 3, 4, 5};
    v.at(2) = -20;
    printVector(v); // 1 2 -20 4 5

    v.front() = -11;
    printVector(v); // -11 2 -20 4 5

    v.back() = -999;
    printVector(v); // -11 2 -20 4 -999

    // some other accessing values
    printVector(v);           // -11 2 -20 4 -999
    cout << v.size() << endl; // 5

    v.pop_back();
    cout << v.size() << endl; // 4
    printVector(v);           // -11 2 -20 4

    v.clear();
    printVector(v); // empty

    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {11, 22, 33, 44, 55};

    v1.swap(v2);
    printVector(v1); // 11 22 33 44 55
    printVector(v2); // 1 2 3

    cout << v1.empty() << endl; // 0

    // traversals
    for (int i = 0; i < vec.size(); i++)
        cout
            << vec[i] << " ";
    cout << endl;
    // 20 30

    for (int val : vec)
        ++val;
    printVector(vec); // 20 30

    for (int &val : vec)
        ++val;
    printVector(vec); // 21 31

    // different data types vectors
    vector<pair<int, int>> vec1;
    vec1.push_back({1, 3});
    vec1.emplace_back(5, 7);
    vec1.emplace_back(pair<int, int>(9, 11));
    vec1.emplace_back(make_pair(13, 15));

    for (pair<int, int> val : vec1)
        cout << val.first << " " << val.second << endl;

    /*
    1 3
    5 7
    9 11
    13 15
    */

    // fixed size vectors
    vector<int> vec2(10);
    vector<int> vec3(5, 100);
    vector<int> vec4(7, 35);

    printVector(vec2); // 0 0 0 0 0 0 0 0 0 0
    printVector(vec3); // 100 100 100 100 100
    printVector(vec4); // 35 35 35 35 35 35 35

    // copying one vector to another
    vector<int> vec5(vec);
    printVector(vec5); // 21 31

    // iterators
    vector<int> vec6 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int>::iterator it = vec6.begin();
    it++;
    cout << *(it) << endl; // 2

    it = it + 2;
    cout << *(it) << endl; // 4

    // some other iterators
    vector<int>::iterator itEnd = vec6.end();
    vector<int>::reverse_iterator itRev = vec6.rbegin();
    vector<int>::reverse_iterator itRevEnd = vec6.rend();

    // Traversals using iterators
    for (vector<int>::iterator it = vec6.begin(); it != vec6.end(); it++)
        cout << *it << " ";
    cout << endl;
    // 1 2 3 4 5 6 7 8 9 10

    for (vector<int>::reverse_iterator it = vec6.rbegin(); it != vec6.rend(); it++)
        cout << *it << " ";
    cout << endl;
    // 10 9 8 7 6 5 4 3 2 1

    for (auto it = vec6.begin(); it != vec6.end(); it++)
        cout << *it << " ";
    cout << endl;
    // 1 2 3 4 5 6 7 8 9 10

    for (auto it = vec6.rbegin(); it != vec6.rend(); it++)
        cout << *it << " ";
    cout << endl;
    // 10 9 8 7 6 5 4 3 2 1

    // for each loop with auto
    for (auto it : vec6)
        cout << it << " ";
    cout << endl;
    // 1 2 3 4 5 6 7 8 9 10

    // erasing elements
    vector<int> vec7 = {10, 20, 30, 40, 50};
    vec7.erase(vec7.begin() + 2);
    printVector(vec7); // 10 20 40 50

    vector<int> vec8 = {11, 22, 33, 44, 55, 66, 77, 88, 99, 110};
    vec8.erase(vec8.begin() + 2, vec8.end() - 2);
    printVector(vec8); // 11 22 99 110

    // Insert functions
    vector<int> vec9(3, 100);
    vec9.insert(vec9.begin(), 333);
    printVector(vec9); // 333 100 100 100

    vec9.insert(vec9.end() - 2, 5, -21);
    printVector(vec9); // 333 100 -21 -21 -21 -21 -21 100 100

    // inserting one vector in another vector @ some index
    vec9.insert(vec9.begin() + 4, vec7.begin(), vec7.end() - 2);
    printVector(vec7); // 10 20 40 50
    printVector(vec9); // 333 100 -21 -21 10 20 -21 -21 -21 100 100
    return 0;
}