#include <bits/stdc++.h>
using namespace std;

int main()
{
    // adding values in pair
    pair<int, int> p = {1, 3};

    // accessing values from pair
    cout << p.first << " " << p.second << endl;

    // values can be changed as well
    p.first = 2;
    p.second = 4;
    cout << p.first << " " << p.second << endl;

    // make_pair
    // if {} was way easy for you, use make_pair to make the pair
    pair<int, int> p1 = make_pair(1, 2);
    cout << p1.first << " " << p1.second << endl;

    // we can nest pairs in different levels
    // This nesting could be done to any number of levels
    pair<int, pair<int, int>> p2 = {1, {2, 3}};
    cout << p2.first << endl;
    cout << p2.second.first << endl;
    cout << p2.second.second << endl;

    // array of pair
    // array is a set of data so it can be of pair data-type as well
    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
    cout << arr[0].first << " " << arr[0].second << endl;
    cout << arr[1].first << " " << arr[1].second << endl;
    cout << arr[2].first << " " << arr[2].second << endl;

    return 0;
}