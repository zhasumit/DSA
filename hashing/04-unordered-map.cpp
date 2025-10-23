#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// using unordered_map we donot declare a constant size hash by default
// hash size increases as the entries increase in the hash
// in map it stores everything in the sorted order O(LogN)
// for unorderd_map it is O(1), constant time @worst it is O(N)
// worst happens once in blue moon due to collision
// in unordered_map pair<int,int> cannot be key, but in map it can be

map<int, int> countFreqMap(vector<int> arr) {
  map<int, int> mp;
  for (auto el : arr)
    mp[el]++;
  cout << "Element\tFrequency\n";
  cout << "------------------\n";
  for (auto el : mp)
    cout << el.first << "\t" << el.second << endl;
  return mp;
}

unordered_map<int, int> countFreq(vector<int> arr) {
  unordered_map<int, int> mp;
  for (auto el : arr)
    mp[el]++;
  cout << "\nElement\tFrequency\n";
  cout << "------------------\n";
  for (auto el : mp)
    cout << el.first << "\t" << el.second << endl;
  return mp;
}

int main() {
  vector<int> vec = {1, 3, 5, 3, 5, 3, 53, 4,  6, 7,  10, 5, 6, 7, 2,
                     6, 7, 5, 5, 3, 2, 3,  24, 2, 53, 34, 6, 7, 5};
  countFreqMap(vec);
  countFreq(vec);
  return 0;
}
