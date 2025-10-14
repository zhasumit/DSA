#include <bits/stdc++.h>
using namespace std;

void printMap(map<int, int> mp)
{
    for (auto it : mp)
        cout << it.first << " " << it.second << endl;
}

int main()
{
    // declaration and addition of values in the map
    map<int, int> mp;
    mp[1] = 2;
    mp.insert({10, 3});
    mp.emplace(5, -1);
    printMap(mp);

    // getting the values of the map
    cout << mp[1] << endl; // 2
    cout << mp[5] << endl; // 1
    cout << mp[4] << endl; // 0 since null (not present)

    // pair in maps
    map<int, pair<int, int>> pairvalue_map;
    pairvalue_map[3] = {1, 2};

    map<pair<int, int>, int> pairkey_map;
    pairkey_map[{2, 4}] = 10;

    // find gives the iterator for the key of the map
    auto it = mp.find(10);
    cout << (*it).first << endl;  // 10
    cout << (*it).second << endl; // 3

    // if nothing points points after the map mp.end()
    it = mp.find(20);
    cout << (*it).second << endl; // 0 since nothing there

    // lower_bound() and upper_bound() are the same as sets
    return 0;
}