# Hashing

Hashing is a technique to **map data of arbitrary size to a fixed-size value**, often called a **hash code** or **hash value**.  
Think of it like an index in a giant table, so you can **quickly store and retrieve data**.

- Example: You have a name `"Sumit"`. Hashing converts it to a number like `1234`.    
- That number is used as an index to store `"Sumit"` in a table (like an array or map).


### Manual code counter 

The goal is to **count how many times each number appears** and store it in `freq[]`.
- `visited[]` is used to **avoid counting the same element multiple times**.
- You iterate over `arr[i]`:
    - Count occurrences of `arr[i]` in the entire array.
    - Assign that count to all positions where `arr[i]` appears.


> For every number, quickly know **how many times it appeared** in the array.

Right now, your code does **nested loops** → `O(n²)` complexity.

Hashing is a better way to do this in **O(n)**:
- Use a **hash table** (`unordered_map` in C++) to store **each number as a key** and its **frequency as a value**.
- Instead of scanning the array again and again, just **look up the count in the hash table**.


```cpp
#include <iostream>
using namespace std;

void countArrayFrequency(int arr[], int n, int freq[]) {
  bool visited[n]; // to mark visited elements
  for (int i = 0; i < n; i++)
    visited[i] = false;

  for (int i = 0; i < n; i++) {
    if (visited[i])
      continue; // skip if already counted

    int count = 0;
    // count occurrences of arr[i]
    for (int j = 0; j < n; j++) {
      if (arr[j] == arr[i]) {
        count++;
      }
    }

    // assign the same count to all matching elements
    for (int j = 0; j < n; j++) {
      if (arr[j] == arr[i]) {
        freq[j] = count;
        visited[j] = true;
      }
    }
  }
}

int main() {
  int arr[] = {42, 7, 7, 15, 42, 42, 3, 15, 7};
  int n = sizeof(arr) / sizeof(arr[0]);
  int freq[n];

  countArrayFrequency(arr, n, freq);

  cout << "Index\tValue\tFreq\n";
  cout << "--------------------\n";
  for (int i = 0; i < n; i++)
    cout << i << "\t" << arr[i] << "\t" << freq[i] << "\n";

  return 0;
}
```





--- 




###  Using a hash array with index as number 

- if we use array as hash 
- take the `index` as the number itself and `arr[i]` as the frequency 
- Think of `hash[]` as a **table that stores counts**, where **the index itself is the key**:

```cpp
#include <bits/stdc++.h>
using namespace std;

// donot do this just for demo (can go till 4GB size)
// outside (globally) it can go till 10^9
// int hash[10000000] = {0};

// so max we can go till is 10^6 or 10^7 mostly
void countFreq(int *arr, int n, int *hash) {
  for (int i = 0; i < n; i++)
    hash[arr[i]] += 1;
}

int main() {
  int arr[] = {1, 3, 5, 3, 5, 3, 53, 4,  6, 7,  10, 5, 6, 7, 2,
               6, 7, 5, 5, 3, 2, 3,  24, 2, 53, 34, 6, 7, 5};
  int hash[100] = {0}; // inside it can go till 10^6
  countFreq(arr, sizeof(arr) / sizeof(int), hash);
  cout << "Number\tFreq\n";
  cout << "-------------\n";
  for (int i = 0; i < 100; i++)
    if (hash[i])
      cout << i << "\t" << hash[i] << "\n";
  return 0;
}
```
```txt
Index	Value	Freq
--------------------
0		42		3
1		7		3
2		7		3
3		15		2
4		42		3
5		42		3
6		3		1
7		15		2
8		7		3
```

|Index (key)|Value (count)|
|---|---|
|1|1|
|2|3|
|3|5|
|5|5|
|53|2|

- You **directly access the frequency** of a number by using the number as the index. 
- No loops needed to find the frequency like in your first O(n²) code.

This is **very fast (O(n))** because array access is O(1).


#### **Limitation**

This approach **only works if the numbers are small and non-negative**, because:
1. You’re using the number itself as the index.
2. Large numbers like `10^9` would require a massive array.
3. Negative numbers don’t work directly — you’d need to shift them.

For large numbers or arbitrary integers, you **use `unordered_map`**, which is basically a **dynamic hash table**.




--- 



## Character Hashing using limited array size 
- since lower characters are `26` in size
- and overall it is `256` in size for all the `ASCII` numbers
- **Hash table:** `array<int, 26>` or `array<int, 256>` is your hash table.
- **Key:** Character’s **ASCII value** (or `ch - 'a'` for lowercase letters).
- **Value:** Count of occurrences (`hash[index]`).
- **Lookup:** `O(1)` — you can instantly get the count of any character.

##### For the lower character set 
- `'a'` has ASCII 97, `'z'` has 122.
- `tolower(ch) - 'a'` → maps `'a'..'z'` to `0..25`.
- `hash[index]++` → increments count for that character.
- Example: `"MISSISSIPI"` → counts how many times `'m'`, `'i'`, `'s'`, `'p'` occur.
So here, your **hash table has size 26** (for lowercase letters only), and **index = character - 'a'**.

##### For overall ASCII set 
- - Here, your **hash table has size 256**, for all ASCII characters.
- `hash[ch]++` → increments count of the character at ASCII value `ch`.
- Example: `"Hello, World! @2025 #C++_Rocks$ %Test&*()"`
    - `'H'` → ASCII 72 → `hash[72]++`
    - `' '` → ASCII 32 → `hash[32]++`
- This way, you can count **any character**, including digits, symbols, uppercase, etc.


```cpp
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

```
```txt
Char	Freq
---------------
i		4
m		1
p		1
s		4

Char	Freq
---------------
 		4
!		1
#		1
$		1
%		1
&		1
(		1
)		1
*		1
+		2
,		1
0		1
2		2
5		1
@		1
C		1
H		1
R		1
T		1
W		1
_		1
c		1
d		1
e		2
k		1
l		3
o		3
r		1
s		2
t		1
```



##### **Relation to Hashing**
1. **Hash table:** `array<int, 26>` or `array<int, 256>` is your hash table.
2. **Key:** Character’s **ASCII value** (or `ch - 'a'` for lowercase letters).
3. **Value:** Count of occurrences (`hash[index]`).
4. **Lookup:** `O(1)` — you can instantly get the count of any character.

##### **Why this is efficient**
- Instead of nested loops scanning the string repeatedly, **each character is mapped directly to an index in `hash`** → `O(n)` time.
- Very similar to **array hashing for integers**:
    - For integers: `hash[number]++`
    - For characters: `hash[ASCII(character)]++`




--- 



## Using `map` and `unordered_map`

##### `map` hashing
- **`map`** is a **balanced BST internally** (usually Red-Black Tree).
- **Inserting/accessing elements** takes **O(log n)** time.
- **Keeps keys sorted** automatically.
- Example output for `vec` (sorted by keys):
- `hash` size increases as the entries increase in the hash


##### `Unordered_map` hashing
- **`unordered_map`** is a **hash table**.
- **Inserting/accessing elements** is **O(1) average**.
- **Does NOT maintain any order**, elements can appear in arbitrary order.
- Handles large datasets efficiently.
- `O(N)` happens rarely, worst happens once in blue moon due to collision

> Worst-case is **O(n)** if too many collisions happen, but it’s rare in practice.

```cpp
#include <bits/stdc++.h>
using namespace std;

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

```
```txt
Element	Frequency
------------------
1		1
2		3
3		5
4		1
5		6
6		4
7		4
10		1
24		1
34		1
53		2

Element	Frequency
------------------
34		1
24		1
2		3
10		1
7		4
6		4
4		1
5		6
3		5
53		2
1		1
```


##### **Key differences between `map` and `unordered_map`**

| Feature                | `map`                    | `unordered_map`           |
| ---------------------- | ------------------------ | ------------------------- |
| Internal structure     | Balanced BST (Red-Black) | Hash table                |
| Average lookup time    | `O(log n)`               | `O(1)`                    |
| Worst-case lookup time | `O(log n)`               | `O(n)` (rare, collisions) |
| Key order              | Sorted                   | Arbitrary                 |
| Can key be pair?       | Yes                      | No                        |
| Memory                 | Less overhead            | Slightly higher           |


##### **5. How frequency counting works here**

For both `map` and `unordered_map`:
`for (auto el : arr)     mp[el]++;`
- `mp[el]` **automatically creates a new key** with value 0 if `el` doesn’t exist yet.
- Then `++` increments the frequency.
- This **replaces manual arrays or visited arrays** in earlier examples.

**In short**:
- `map` → sorted keys, O(log n) operations.
- `unordered_map` → hash table, O(1) operations on average.
- Both can replace manual frequency counting with **clean, scalable code**.




---



##### Why does collision happen in `unordered_map`

Collision in an `unordered_map` happens because it is implemented as a **hash table**. A hash table maps keys to indices (buckets) in an underlying array using a **hash function**. If two different keys produce the same hash value (or map to the same bucket), a **collision** occurs.

Suppose we have the hash function:
`hash(key) = key % 5`

We want to insert keys:
`2, 7, 12, 17, 22, 3, 8`

---
##### **Step 1: Calculate bucket indices**

| Key | Hash(key)  | Bucket |
| --- | ---------- | ------ |
| 2   | 2 % 5 = 2  | 2      |
| 7   | 7 % 5 = 2  | 2      |
| 12  | 12 % 5 = 2 | 2      |
| 17  | 17 % 5 = 2 | 2      |
| 22  | 22 % 5 = 2 | 2      |
| 3   | 3 % 5 = 3  | 3      |
| 8   | 8 % 5 = 3  | 3      |

---

##### **Step 2: Visualize the hash table**
```scss
Buckets:
0 : 
1 : 
2 : 2 -> 7 -> 12 -> 17 -> 22
3 : 3 -> 8
4 : 
```
- Bucket **2** has 5 keys → heavy collision
- Bucket **3** has 2 keys → minor collision
- Other buckets are empty


