# STL

it is comprised of four parts 
- Containers
- Functions
- Iterators
- Algorithms



### Pairs 
- pairs is a part of utility library 
- holds a pair (as clear from the name), inside `{}`
- `pair<int, int>` or any other data-type can be made 
- holds two values, `first` and `second`
- values can be accessed using `.` operator, `.first` and `.second`

```cpp
pair<int, int> p = {1, 3};
cout << p.first << " " << p.second << endl;

p.first = 2;
p.second = 4;
cout << p.first << " " << p.second << endl;
```
```txt
1 3
2 4
```


- if you like your life difficult you can use `make_pair` instead of `{}`
- same function, creates a pair of some data-type

```cpp
pair<int, int> p1 = make_pair(1, 2);
cout << p1.first << " " << p1.second << endl;
```
```txt
1 2
```


- sometimes a pair of pair or nesting of different levels may be required 
- so define the pair of pairs and the pair will be holding some child pair values
- since nesting of pairs `.first` and `.second` are also nested 

```cpp
pair<int, pair<int, int>> p2 = {1, {2, 3}};
cout << p2.first << endl;
cout << p2.second.first << endl;
cout << p2.second.second << endl;
```
```txt
1
2
3
```


- array of pairs 
- to store the pairs in a consecutive location
- easy to access and useful at many utilities and 
- array is a set of data so it can be of pair data-type as well

```cpp
pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
cout << arr[0].first << " " << arr[0].second << endl;
cout << arr[1].first << " " << arr[1].second << endl;
cout << arr[2].first << " " << arr[2].second << endl;
```
```txt
1 2
3 4
5 6
```





<hr>




### Containers 
- Containers are data structures provided by STL to store collections of objects.
- They make it easy to manage groups of elements (in memory, order, access method, etc.).

1. **Sequence Containers**
    - Store data in **linear order**.
        - `vector` (dynamic array, random access, fast at end insertion)
        - `deque` (double-ended queue, fast insertion/removal at both ends)
        - `list` (doubly linked list, fast insertion/removal anywhere)
        - `forward_list` (singly linked list, more lightweight than list)
        - `array` (fixed-size, like a wrapper around C-style arrays)

2. **Associative Containers**
    - Store data in a **sorted (balanced BST) structure**.
    - All operations (`insert`, `find`, `erase`) are usually **O(log n)**.
        - `set` (unique, sorted values)
        - `multiset` (allows duplicate values, sorted)
        - `map` (key-value pairs, unique keys, sorted)
        - `multimap` (key-value pairs, duplicate keys allowed, sorted)

3. **Unordered Containers**
    - Store data using **hash tables** (not sorted, but very fast average case).
    - Most operations are **O(1)** on average.
        - `unordered_set`
        - `unordered_multiset`
        - `unordered_map`
        - `unordered_multimap`

4. **Container Adapters**
    - Not containers themselves, but **wrappers** built on top of other containers.
    - Restrict the interface to provide specific behaviors.
        - `stack` (LIFO, built on `deque` or `list` or `vector`)
        - `queue` (FIFO, built on `deque` or `list`)
        - `priority_queue` (max-heap/min-heap, built on `vector`)





## Vectors 

- vectors are the singly-linked-list implementation
#### Declarations
- previously we use to store values in array `int arr[] = {1, 2, 3, 4, 5}`
- which has some limitations, constant in size (cannot increase the size)
- declaration : `vector<int> vec;` creates an empty container 
- adding values to the end of vector (appending):  `push_back`, `emplace_back`
- `.emplace_back()` is faster than `.push_back()`, does not create temporary storage
- after adding the values to the vector the size increases by `2x` every time it gets bottleneck

```cpp
vector<int> vec;

vec.push_back(20);
vec.emplace_back(30);
```

- accessing the vector, can be done by `[index]` just like in array
- loops can be of normal size looping, referenced loop, range based loop 

```cpp
// simple for loop using indexing 
for (int i = 0; i < vec.size(); i++)
	cout << vec[i] << " ";
cout << endl;
```
```txt
20 30
``` 


- also accessed using `.at()` in which we give `index` just like in `[]`
- so `vec.at(0)` is same as saying `vec[0]`
- `vec.back()` gives the back of the vector, i.e. `vec[n-1]`
- `vec.front()` gives the first index, i.e. `vec[0]`

```cpp
vector<int> v = {1, 2, 3, 4, 5};
v.at(2) = -20;
printVector(v);

v.front() = -11;
printVector(v);

v.back() = -999;
printVector(v);
```
```txt
1 2 -20 4 5 
-11 2 -20 4 5 
-11 2 -20 4 -999 
```


- `v.size()` gives the total size of the vector 
- `v.pop_back()` removes last element 
- `Vfirst.swap(Vsecond)` swaps first and second vector 
- `v.clear()` clears all the elements of the vector 
- `v.empty()` -> `1` or True if empty, `0` or False if not empty 

```cpp
printVector(v);
cout << v.size() << endl;

v.pop_back(); // removes last element
cout << v.size() << endl;
printVector(v); // -11 2 -20 4 

v.clear();
printVector(v); // empty

vector<int> v1 = {1, 2, 3};
vector<int> v2 = {11, 22, 33, 44, 55};

v1.swap(v2);
printVector(v1);
printVector(v2);

cout << v1.empty() << endl;
```
```txt
-11 2 -20 4 -999
5
4
-11 2 -20 4 

11 22 33 44 55 
1 2 3 
0
```


#### traversal of vectors 
- reference loops are range based and the values are taken from vector 
- using `&` the values of the vector could be manipulated 
- other wise in the range based loops the changes are not done to real values 

```cpp
// taking the vector & so reference address is taken
// other wise the entire copy of the vector is given
// and the main original copy is not changed in vec, it should be &vec
void printVector(vector<int> &vec) {
    for (int val : vec)
        cout << val << " ";
    cout << endl;
}

// without reference the real values are not changed 
for (int val : vec)
	++val;
printVector(vec);

// with reference operator & the values are changed 
for (int &val : vec)
	++val;
printVector(vec);
```
```txt
20 30 
21 31
```


#### vectors of `pair<int, int>` data type 
- there is `pair<int, int>` which is utility
- we can make the vectors of that data-type as well 
- `push_back` and `emplace_back` has slight different in syntax
- `{1, 2}` is a pair that can be added using `push_back`
- but in `emplace_back`, `{1, 2}` does not work 
- so what works ? : 
	- direct adding after comma `(1, 2)` do not add `{}`
	- add using `make_pair(1, 2)`
	- using direct declaration `pair<int, int> (1, 2)`

```cpp
vector<pair<int, int>> vec1;

vec1.push_back({1, 3});

vec1.emplace_back(5, 7);
vec1.emplace_back(make_pair(13, 15));
vec1.emplace_back(pair<int, int>(9, 11));

for (pair<int, int> val : vec1)
	cout << val.first << " " << val.second << endl;
```
```txt
1 3
5 7
9 11
13 15
```


#### Declaring vectors of some fixed size 
- `vector<data-type> vectorName(size)` creates a vector of given `size`
- `vector<data-type> vectorName(size, someNumber)`, 
	- this creates a vector of given size
	- every index has the value of given `someNumber`
	- ex: `vector<int> (4, 20);` makes `{20, 20, 20, 20}`

```cpp
vector<int> vec2(10);
vector<int> vec3(5, 100);
vector<int> vec4(7, 35);

printVector(vec2);
printVector(vec3);
printVector(vec4);
```
```txt
0 0 0 0 0 0 0 0 0 0 
100 100 100 100 100 
35 35 35 35 35 35 35 
```


#### Copying one vector into another 
- `vector<int> vec5(vec);` 
	- copies `vec` to `vec5`

```cpp
vector<int> vec5(vec);
printVector(vec5);
```
```txt
21 31 
```


#### Iterators in vector
- `vector<data-type>::iterator it = vectorName.begin()`
	- starting iterator for the vector 
	- here index is not used this `it` is the iterator 
	- `it` is the pointer of the vector 
	- `.begin()` points directly to the memory 
	- in the memory we access using `*(ptrName)`
- using normal arithmetic like `i++`, `it` are also manipulated for traversals 

```cpp
vector<int> vec6 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
vector<int>::iterator it = vec6.begin();
it++;
cout << *(it) << endl;

it = it+2; 
cout << *(it) << endl;
```
```txt
2
4
```


- some other iterators are like 
- `vector<int>::iterator it = vec.end()`, 
	- points to nth location
	- not the `n-1` point, after `vec[n-1]` i.e. `vec[n]`
- `vector<int>::iterator it = vec.rend()`,
	- `.rend()` is reverse end so it points to one before `vec[0]`
	- so `.rend()` points to `vec[-1]` technically 
- `vector<int>::iterator it = vec.rbegin()`,
	- `.rbegin()` points to the last position i.e. `vec[n-1]`
	- also `it++` will decrease the index since works opposite 
	- it is a reverse iterator so `it++` moves backwards 


#### Traversal using iterators 

```cpp
for (vector<int>::iterator it = vec6.begin(); it != vec6.end(); it++)
	cout << *it << " ";
cout << endl;

for (vector<int>::reverse_iterator it = vec6.rbegin(); it != vec6.rend(); it++)
	cout << *it << " ";
cout << endl;
```
```txt
1 2 3 4 5 6 7 8 9 10 
10 9 8 7 6 5 4 3 2 1 
```


- but the iterators are too long to write so there comes `auto`
- `auto` automatically takes the values data-type for any data-type
- no defining of the data-type, automatically assigned data-type 

```cpp
for (auto it = vec6.begin(); it != vec6.end(); it++)
	cout << *it << " ";
cout << endl;

for (auto it = vec6.rbegin(); it != vec6.rend(); it++)
	cout << *it << " ";
cout << endl;
```
```txt
1 2 3 4 5 6 7 8 9 10 
10 9 8 7 6 5 4 3 2 1 
```


#### for each loop `:`
- `:` is the for each loop
- `;` is not used no `initial; condition; change` conditions in the loop 
- just use `for (data-type iterator : vectorName)`

```cpp
for (auto it : vec6)
	cout << it << " ";
cout << endl;
```
```txt
1 2 3 4 5 6 7 8 9 10 
```


#### Erasing elements

- `.erase()` does the erasing of elements 
- single erasing : `vecName.erase(index);`

```cpp
vector<int> vec7 = {10, 20, 30, 40, 50};
vec7.erase(vec7.begin() + 2);
printVector(vec7);

```
```txt
10 20 40 50 
```


- range erasing : `vecName.erase(start, end);`, erases `[start, end)`
- since `.end()` is `[n]`, 
- so `.end() - 2` is `[n-2]`, 
- so `[n-2]` is not erased i.e. `99`

```cpp
vector<int> vec8 = {11, 22, 33, 44, 55, 66, 77, 88, 99, 110};
vec8.erase(vec8.begin() + 2, vec8.end() - 2);
printVector(vec8);
```
```txt
11 22 99 110 
```


#### Inserting elements 

- inserting at some `index`
- `vecName.insert(vecName.iterator(), valueToBeInserted)`

```cpp
vector<int> vec9(3, 100);
vec9.insert(vec9.begin(), 333);
printVector(vec9);
```
```txt
333 100 100 100
```


- inserting multiple values in the vector at some `index`
- `vecName.insert(vecName.iterator(), #timesToInsert, valueToBeInserted)`

```cpp
vec9.insert(vec9.end() - 2, 5, -21);
printVector(vec9);
```
```txt
333 100 -21 -21 -21 -21 -21 100 100 
```


- inserting a vector into another vector 
- `Vmain` : vector in which to be inserted 
- `vec` : vector to be inserted  
- `Vmain.insert(Vmain.iterator(), vec.iterator(), vec.iterator());`

```cpp
vec9.insert(vec9.begin() + 4, vec7.begin(), vec7.end() - 2);
printVector(vec7);
printVector(vec9);
```
```txt
10 20 40 50 
333 100 -21 -21 10 20 -21 -21 -21 100 100 
```



> all the iterators and other portions are mostly similar now just getting a hang of what other containers look like in the execution




## List
- same as array and vector
- it is doubly-linked-list implementation 
- made using `list<data-type> listName;`
- same kind of operations like vectors and array 
- insertion in list is not costly 
	- `.push_front()`, 
	- `.emplace_front()`, 
	- `.push_back()`, 
	- `.emplace_back()`
- all the other functions are similar to vectors like `begin`, `end`, `rbegin`, `rend`, `clear` , `insert`, `size`, `swap`

```cpp
list<int> ls;

ls.push_back(10);
printList(ls); // 10

ls.emplace_back(20);
printList(ls); // 10 20

ls.push_front(5);
printList(ls); // 5 10 20

ls.emplace_front(1);
printList(ls); // 1 5 10 20
```
```txt
10 
10 20 
5 10 20 
1 5 10 20 
```




## Stack
- stack is LIFO data-structure 
- `LIFO` : Last in first out
- all the operations are `O(1)` operations, constant time 
- some important functions 
	- `.push()` : adds to the top of the stack
	- `.pop()` : removes from the top of the stack
	- `.empty()` : True if stack empty, False if not empty 
	- `.emplace()`: same as `.push()` adds to the top of stack
	- `.size()` : gives the size `#elements` in stack 
	- `.swap()` : swaps different stack 

```cpp
void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

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
```
```txt
1
5 3 3 2 1 
5
5
4
3 3 2 1 
```



## Queue
- queue is FIFO data-structure 
- `FIFO` : First in first out
- all the operations are `O(1)` operations, constant time
- `queue <int> q;`
- some important functions 
	- `.push()` : adds to the end of the queue
	- `.emplace()`: same as `.push()` adds to the end of the queue
	- `.back()` : last element of the queue can be accessed 
	- `.front()` : front element of the queue can be accessed 
	- `.pop()` : removes from the first element of queue
	- `.empty()` : True if stack empty, False if not empty 
	- `.size()` : gives the size `#elements` in stack 
	- `.swap()` : swaps different queue

```cpp
void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

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
```
```txt
1 2 3 
2 3 
2 3 4 
2
4
3
0
2 3 4 

```




## Deque
- same as array and vector, list 
- doubly ended queue 
- a queue in which elements can be inserted or deleted from any end 
- doubly-ended means both the ends are okay to work with 
-  made using `deque<data-type> dequeName;`
- same old operations like list  
	- `.push_front()`, 
	- `.emplace_front()`, 
	- `.push_back()`, 
	- `.emplace_back()`, 
	- `.pop_back()`,
	- `.pop_front()`,
	- `.front()`,
	- `.back()`
- all the other functions are similar to vectors like `begin`, `end`, `rbegin`, `rend`, `clear` , `insert`, `size`, `swap`

```cpp
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
```
```txt
10 
10 20 
5 10 20 
1 5 10 20 
5 10 
10
5
```




## Priority Queue
- keeps the most priority element on the top 
- has some few functions like other queues 
- lexicographical largest element is always on top
- it is implemented in tree data structure 
- it is knows as max heap
- push, pop : `O(LogN)` and top : `O(1)`

```cpp
void printPriorityQueue(priority_queue<int> pq) {
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

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
```
```txt
1
10
0
8 6 5 2 
4
4 0 -6 
8 6 5 2 
```



- min heap contains minimal element at top 
- for min heap a `data-type, greater<data-type>` is added in the pq 
```cpp
void printMinPriorityQueue(priority_queue<int, vector<int>, greater<int>> pq) {
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

// min heap
priority_queue<int, vector<int>, greater<int>> pq2;
pq2.push(5);
pq2.push(2);
pq2.push(8);
pq2.push(10);
pq2.push(6);
printMinPriorityQueue(pq2); // 2 5 6 8 10
```
```txt
2 5 6 8 10
```




## Set
- sorted storage 
- unique elements only 
- functionality of insert in vector can be used also 
- `begin`, `end`, `rbegin`, `rend`, `size`, `empty`, `swap` are same
- since unique `.count()` gives if element is present or not 
- this is also not a linear container a tree is maintained inside 

```cpp
// same like other container traversal while not empty pop/erase and print
void printSet(set<int> s)
{
    while (!s.empty())
    {
        cout << *s.begin() << " ";
        s.erase(s.begin());
    }
    cout << endl;
}
```

```cpp
 set<int> s;
s.insert(1);
s.insert(2);
s.insert(10);
s.insert(3);
s.insert(2);
s.insert(4);
s.insert(3);
printSet(s);
```
```txt
1 2 3 4 10 
3
1 3 4 
0
```

- finding the element returns the iterator for that point 
```cpp
auto it = s.find(3);
cout << *it << endl; // 3

it = s.find(100); // no element so returns s.end()
```
```txt
3
```


- removal can be done using `.erase(element)` or using `.erase(iterator)`
```cpp
it = s.find(2); // since returns the iterator after finding
s.erase(10); // removes element using value
s.erase(it); // removes using iterator

for (auto it = s.begin(); it != s.end(); it++)
	cout << *it << " ";
cout << endl;
```
```txt
1 3 4
```

- `.count(element)` returns the count of the element 
- gives `true` or `false` since it contains only the unique 
- we can also remove the range using iterators same range `[start, end)` is erased
- all the other iterators are almost similar to vector 

```cpp
cout << s.count(10) << endl; // 0 (returns True or False)
set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

auto it1 = s1.find(4);
auto it2 = s1.find(7);
s1.erase(it1, it2);
printSet(s1); // [start, end) is erased (1 2 3 7 8 9 10) remains
```
```txt
0
1 2 3 7 8 9 10
```

- everything happens in `0(LogN)`
- `.lower_bound(element)` looks for the element immediately <= that given element 
- so for lower bound `iterator_returned >= given_element`
- `.upper_bound(element)` looks for the element immediately > that given element 
- so for the upper bound `iterator_returned < given_element`
- if goes out of list gives `itr @ (n)`

```cpp
cout << *(s1.lower_bound(3)) << endl;
cout << *(s1.lower_bound(5)) << endl;
cout << *(s1.lower_bound(6)) << endl;

cout << *(s1.upper_bound(1)) << endl;
cout << *(s1.upper_bound(5)) << endl;
cout << *(s1.upper_bound(6)) << endl;
cout << *(s1.upper_bound(9)) << endl;
```
```txt
3
7
7

2
7
7
10
```




## unordered_set
- everything is similar to set 
- does not store in the sorted order 
- randomized order (but contains unique just like set) 
- `O(1)` time complexity in most cases, for the worst case it is `O(N)`
- `lower_bound()` and `.upper_bound()` are not there since no order 



## MultiSet
- only keeps sorted (not unique)
- stores duplicate numbers 
- since contains duplicate `.count()` gives number 

```cpp
void printMultiset(multiset<int> ms)
{
    while (!ms.empty())
    {
        cout << *ms.begin() << " ";
        ms.erase(ms.begin());
    }
    cout << endl;
}

multiset<int> ms;
ms.insert(1);
ms.insert(2);
ms.insert(3);
ms.insert(4);
ms.insert(1);
ms.insert(4);
ms.insert(1);
ms.insert(1);
ms.insert(1);
printMultiset(ms);

cout << ms.count(1) << endl;
cout << ms.count(4) << endl;
```
```txt
1 1 1 1 1 2 3 4 4 
5
2
```

- removal and eraser is also somewhat similar to set 
- `erase()` removes all the instance of the number 
```cpp
// removes all the 4
ms.erase(4);
printMultiset(ms);
```
```txt
1 1 1 1 1 2 3 
1 1 1 1 2 3 
```



- `erase(iterator)` removes the first element which is found by iterator 
```cpp
ms.erase(ms.find(1));
cout << ms.count(1) << endl;
printMultiset(ms);

auto it1 = ms.find(1);
auto it2 = it1;
std::advance(it2, 2); // modifies it2 directly
ms.erase(it1, it2);
cout << ms.count(1) << endl;
```
```txt
4
1 1 1 1 2 3 
2
1 1 2 3 
```





## Map
- map stores `key:value` pairs 
- `keys` are unique 
- `values` can be duplicate, `keys` are unique
- map stores unique keys in sorted order 
- all the other functions works in the exact same manner 

```cpp
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
```
```txt
1 2
5 -1
10 3
2
-1
0
```


- declaration of maps involving `pair` is same just the key or value has pair inside it 
- pair can be nested to any levels 

```cpp
// pair in maps
map<int, pair<int, int>> pairvalue_map;
pairvalue_map[3] = {1, 2};

map<pair<int, int>, int> pairkey_map;
pairkey_map[{2, 4}] = 10;
```

- finding keys inside the map 
- find gives the iterator for the key of the map
- `lower_bound()` and `upper_bound()` are the same as sets


```cpp
auto it = mp.find(10);
cout << (*it).first << endl;  // 10
cout << (*it).second << endl; // 3

it = mp.find(20);
cout << (*it).second << endl; // 0 since nothing there
```
```txt
10
3
0
```



## Multimap 
- same as map 
- just can store duplicate keys 


## Unordered map 
- same as map 
- just is not sorted 









# Algorithms 

- Algorithms are pre-defined operations (functions) 
- work on data structures (mainly through iterators).
- Examples: searching, sorting, counting, finding min/max, modifying elements.
- They are written in a generic way, so they can work with any container that supports iterators.
- Examples from `<algorithm>`:
	- `sort(begin, end)`
	- `find(begin, end, value)`
	- `reverse(begin, end)`
	- `count(begin, end, value)`



### Sorting 
- getting elements in ascending or descending order 

```cpp
vector<int> vec = {1, 5, 2, -1, 3, 2};
sort(vec.begin(), vec.end());
printvector(vec);

// greater<int>() is a comparator to sort in decending order
sort(vec.begin(), vec.end(), greater<int>());
printvector(vec);
```
```txt
-1 1 2 2 3 5 
5 3 2 2 1 -1 
```



### counting number of set bits in the number 

```cpp
// returning number of set bits in a number
int num = 7;
int cnt = __builtin_popcount(num);
cout << cnt << endl;

long long number = 1679482647203;
cnt = __builtin_popcountll(number);
cout << cnt << endl;
```
```txt
3
21
```



### permutations of the string 
```cpp
string s = "123";
do
{
	cout << s << endl;
} while (next_permutation(s.begin(), s.end()));
// returns false if no more permutations
```
```txt
123
132
213
231
312
321
```


### getting max element in the vector or array

```cpp
vector<int> vec = {1, 5, 2, -1, 3, 2};
int maxi = *max_element(vec.begin(), vec.end());
cout << maxi << endl;
```
```txt
5
```