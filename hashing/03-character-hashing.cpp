#include <bits/stdc++.h>
#include <cctype>
using namespace std;

// a has ASCII of 97 and z has 122
// int x = 'a'; stores 97 as value ASCII

// for freq of lower characters
array<int, 26> countCharFrequency(string str) {
  array<int, 26> hash = {0};
  for (char ch : str)
    if (isalpha(ch))
      hash[tolower(ch) - 'a']++;
  return hash;
}

// hash inside needs an integer (auto cast to integer)
// for all the characters
array<int, 256> countCharacterFrequency(string str) {
  array<int, 256> hash = {0};
  for (char ch : str)
    hash[ch]++;
  return hash;
}

int main() {
  string str = "MISSISSIPI";
  array<int, 26> hash = countCharFrequency(str);

  // for only the small characters
  cout << "Char\tFreq\n";
  cout << "---------------\n";
  for (int i = 0; i < 26; i++) {
    char ch = 'a' + i;
    if (hash[i])
      cout << ch << "\t" << hash[i] << "\n";
  }

  // for all the characters
  str = "Hello, World! @2025 #C++_Rocks$ %Test&*()";
  array<int, 256> hashall = countCharacterFrequency(str);
  cout << "Char\tFreq\n";
  cout << "---------------\n";
  for (int i = 0; i < 256; i++) {
    char ch = ' ' + i;
    if (hashall[i])
      cout << char(i) << "\t" << hashall[i] << "\n";
  }

  return 0;
}
