## Recursion

- function calling itself is called recursion 
- it only calls till a **special condition** is met 
- without the base condition there is no stopping of the function calls 
- infinite calling leads to stack overflow 
- stack overflow is the full memory of stack 
- so the stack is the memory used normally by the programs

```cpp
void f() {
    f(); // infinite recursion
}
```

```txt
[Start f()] → [No base condition] → [Call f() again] → [Call f() again...] → [Stack grows...] → [💥 Stack Overflow]
```

```scss
        ┌────────────────────────┐
        │     Start function f() │
        └─────────────┬──────────┘
                      │
                      ▼
        ┌────────────────────────┐
        │   (No base condition)  │
        │ or base never reached  │
        └─────────────┬──────────┘
                      │
                      ▼
        ┌────────────────────────┐
        │   Call f() again       │
        │   (recursive call)     │
        └─────────────┬──────────┘
                      │
                      ▼
        ┌────────────────────────┐
        │   Call f() again       │
        │   (recursive call)     │
        └─────────────┬──────────┘
                      │
                      ▼
        ┌────────────────────────┐
        │   Call f() again       │
        │   (and again...)       │
        └─────────────┬──────────┘
                      │
                      ▼
                ┌───────────────┐
                │ Stack grows…  │
                │ No termination│
                └───────────────┘
                      │
                      ▼
           ┌────────────────────────┐
           │  Stack Overflow Error  │
           │  Program crashes       │
           └────────────────────────┘
```


- with the base condition in check 
- base condition prevents infinite calls and stack overflow 
```scss
        ┌────────────────────────┐
        │   Start function f(x)  │
        └─────────────┬──────────┘
                      │
                      ▼
        ┌────────────────────────┐
        │ Check base condition   │
        └─────────────┬──────────┘
                      │
          ┌───────────┴───────────┐
          │                       │
       Yes▼                       ▼No
 ┌─────────────┐         ┌─────────────────────┐
 │ Return value│         │ Do some processing  │
 │ (end branch)│         │ and call f(new_x)   │
 └─────────────┘         └──────────┬──────────┘
                                    │
                                    ▼
                      ┌────────────────────────┐
                      │ Recursive call executes│
                      │ (same flow repeats)    │
                      └──────────┬─────────────┘
                                 │
                                 ▼
                   ┌──────────────────────────┐
                   │ Return to previous call  │
                   │ with computed result     │
                   └──────────────────────────┘
```


- Recursion tree is the execution and call map of the recursion for different states 
- function calls are mapped in the recursion tree 


##### tree for infinite recursive calls 
```scss
f()
 └── f()
      └── f()
           └── f()
                └── f()
                     └── f()
                          └── f()
                               └── f()
                                    └── f()
                                         └── ...
                                            (continues infinitely)
```

##### tree for infinite recursive calls 

```cpp
void f(int n) {
    if (base_condition(n))
        return;          // base case
    f(smaller(n));       // recursive call
}
```

```scss
f(n)
 ├── check base_condition(n)? → No
 │
 └── f(smaller(n))
       ├── check base_condition(smaller(n))? → No
       │
       └── f(smaller(smaller(n)))
             ├── check base_condition(...)? → No
             │
             └── f(...even smaller...)
                   ├── ...
                   └── f(...until base case)
                         ├── check base_condition(...) → Yes
                         └── return
```



--- 


Ex: print a number using recursion 
- global variable used (should not be used normally)
- just for the demonstration of function calling itself 

```cpp
#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
void print(){
    if (cnt == 3) return;
    cout<<cnt<<endl;
    cnt++;
    print();
}
int main() {
    print();
	return 0;
}
```
```txt
0
1
2
```

```scss
print() [cnt=0]
 ├─ cnt != 3 → print 0
 └─ cnt++ → cnt=1 → print()
      ├─ cnt != 3 → print 1
      └─ cnt++ → cnt=2 → print()
           ├─ cnt != 3 → print 2
           └─ cnt++ → cnt=3 → print()
                ├─ cnt == 3 → return
```


--- 



# Problems on recursion 

## Print name n times 

- for two variables
- one for check one for final count

```cpp
void printname(int i, int n) {
  if (i == n)
    return;
  cout << "sumit\n";
  printname(++i, n);
}
```
```txt
sumit
sumit
sumit
sumit
```

```scss
printname(i=0, n=4)
 ├─ prints "sumit"
 └─ printname(i=1, n=4)
      ├─ prints "sumit"
      └─ printname(i=2, n=4)
           ├─ prints "sumit"
           └─ printname(i=3, n=4)
                ├─ prints "sumit"
                └─ printname(i=4, n=4)  ← base case → return
```


- for single variable 

```cpp
void printname(int n) {
  if (n == 0)
    return;
  cout << "sumit\n";
  printname(--n);
}
```
```txt
sumit
sumit
sumit
sumit
```

```scss
printname(4)
 └── printname(3)
      └── printname(2)
           └── printname(1)
                └── printname(0)  ← base case → return
```


--- 


## Print linearly from 1 to n
- like `1, 2, 3, ... 100`
- start with a i and then go till n (final variable)
- we can call the recursion in two ways
- `print then call` , `call then print`
- both implementations are shown
- this is called top bottom approach

```cpp
void print1toN(int i, int n) {
  if (i == n + 1) {
    cout << "------\n";
    return;
  }
  cout << i << endl;
  print1toN(++i, n);
}
```
```txt
1
2
3
4
5
------
```

```scss
print1toN(i=1, n=5)  → prints 1
 └─ print1toN(i=2, n=5) → prints 2
      └─ print1toN(i=3, n=5) → prints 3
           └─ print1toN(i=4, n=5) → prints 4
                └─ print1toN(i=5, n=5) → prints 5
                     └─ print1toN(i=6, n=5) → base case → prints "------"
```


- using single variable 
- call then print (reverse stack printing)
- the current stack holds the memory of the variable 
- stack gets heavy and while return the variable value is printed
- this is also called bottom up approach

```cpp
void print1toN(int n) {
  if (n == 0) {
    cout << "------\n";
    return;
  }
  print1toN(n - 1);
  cout << n << endl;
}
```
```txt
------
1
2
3
4
5
```


```scss
print1toN(5)
 └─ print1toN(4)
      └─ print1toN(3)
           └─ print1toN(2)
                └─ print1toN(1)
                     └─ print1toN(0) → base case → prints "------"
                     ↑ returns → prints 1
                ↑ returns → prints 2
           ↑ returns → prints 3
      ↑ returns → prints 4
 ↑ returns → prints 5
```


--- 


- now on i am taking one variable approach 
- since i am not to keep another variable for keeping check of the final variable 

## Print n to 1

- check the base condition 
- print the number 
- (since it is not reduce it will print bigger and bigger numbers first)

```cpp
void printNto1(int n) {
  if (n == 0)
    return;
  cout << n << endl;
  printNto1(n - 1);
}
```
```txt
5
4
3
2
1
```

```scss
printNto1(5) → prints 5
 └─ printNto1(4) → prints 4
      └─ printNto1(3) → prints 3
           └─ printNto1(2) → prints 2
                └─ printNto1(1) → prints 1
                     └─ printNto1(0) → base case → return
```


--- 

# Parameterized and functional recursion 


## Sum of n natural numbers 
- finding sum of n natural numbers 
- while returning it returns the sum after adding to the number itself
- bottom up approach

```cpp
int sum(int n) {
  if (n == 0)
    return 0;
  return n + sum(n - 1);
}
```
```txt
10
```


```scss
sum(4)
 └─ sum(3)
      └─ sum(2)
           └─ sum(1)
                └─ sum(0) → returns 0
                     ↑
                returns 1 + 0 = 1
                     ↑
           returns 2 + 1 = 3
                ↑
      returns 3 + 3 = 6
           ↑
 sum(4) returns 4 + 6 = 10
```



---



## Factorial of some number 

- factorial is multiplication of n till it reduces to 1 or 0
- factorial of 0 is 1 (base case)

```cpp
int factorial(int n) {
  if (n == 0)
    return 1;
  return n * factorial(n - 1);
}
```
```txt
120
```

```scss
factorial(5)
 └─ factorial(4)
      └─ factorial(3)
           └─ factorial(2)
                └─ factorial(1)
                     └─ factorial(0) → returns 1
                          ↑
                     returns 1 * 1 = 1
                          ↑
                returns 2 * 1 = 2
                     ↑
           returns 3 * 2 = 6
                ↑
      returns 4 * 6 = 24
           ↑
factorial(5) returns 5 * 24 = 120
```


--- 



## reverse an array 
- if done till the half of the array we can swap the pointers
- so we need two pointers in theory `i, n`
- `i` is initial pointer, `n` is the size or the ending pointer 
- `n-1` gives last element, `n-1-i`, reduces the initial so exact mirror position 
- so we swap the `[n-1-i]` and `[i]` positions
- for the base condition if the initial pointer `i` passes half of array then we return, since all swapped

```cpp
void reverse(int arr[], int n, int i = 0) {
  if (i >= n / 2)
    return;
  swap(arr[i], arr[n - 1 - i]);
  reverse(arr, n, i + 1);
}
```
```txt
Before: 1 2 3 4 5 6 7 8 9
After: 9 8 7 6 5 4 3 2 1
```




--- 


## Check palindrome

- `i` is initial pointer, `n` is the size or the ending pointer, as in reverse 
- comparing the mirror positions we can judge if it would be palindrome any further
- if at any point `arr[n] != arr[n-1-i]` we return `false`, since mirror positions fail to be same

##### for integers
```cpp
bool isPalindrome(int arr[], int n, int i = 0) {
  if (i >= n / 2)
    return true;
  if (arr[i] != arr[n - 1 - i])
    return false;
  return isPalindrome(arr, n, i + 1);
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  cout << isPalindrome(arr, sizeof(arr) / sizeof(int)) << endl;
 
  int arr1[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
  cout << isPalindrome(arr1, sizeof(arr1) / sizeof(int)) << endl;
  return 0;
}
```
```txt
0
1
```


##### for strings 
```cpp
bool isPalindrome(string s, int i = 0) {
  if (i >= s.size() / 2)
    return true;
  if (s[i] != s[s.size() - i - 1])
    return false;
  return isPalindrome(s, i + 1);
}

int main() {
  cout << isPalindrome("MADAM") << endl;
  cout << isPalindrome("docker") << endl;
  cout << isPalindrome("c") << endl;
  return 0;
}
```
```txt
1
0
1
```


---


# Multiple Recursion calls 

## Fibonacci number

> A Fibonacci number is part of a sequence of numbers in which each number is the sum of the two preceding ones, starting from 0 and 1.

`0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...`

- is is sum of previous two numbers, first two Fibonacci number are `0`, `1`
```scss
F(n) = F(n - 1) + F(n - 2)
```


```cpp
int Fib(int n) {
  if (n <= 1)
    return n;
  return Fib(n - 1) + Fib(n - 2);
}
Fib(5);
```
```txt
55
```

```scss
Fib(10)
├── Fib(9)
│   ├── Fib(8)
│   │   ├── Fib(7)
│   │   │   ├── Fib(6)
│   │   │   │   ├── Fib(5)
│   │   │   │   │   ├── Fib(4)
│   │   │   │   │   │   ├── Fib(3)
│   │   │   │   │   │   │   ├── Fib(2)
│   │   │   │   │   │   │   │   ├── Fib(1) = 1
│   │   │   │   │   │   │   │   └── Fib(0) = 0
│   │   │   │   │   │   │   └── Fib(2) = 1 + 0 = 1
│   │   │   │   │   │   └── Fib(1) = 1
│   │   │   │   │   │   └── Fib(3) = 1 + 1 = 2
│   │   │   │   │   └── Fib(2) = 1
│   │   │   │   └── Fib(4) = 2 + 1 = 3
│   │   │   └── Fib(3) = 2
│   │   │   └── Fib(5) = 3 + 2 = 5
│   │   └── Fib(4) = 3
│   │   └── Fib(6) = 5 + 3 = 8
│   └── Fib(5) = 5
│   └── Fib(7) = 8 + 5 = 13
└── Fib(8) = 13
└── Fib(10) = 21 + 34 = 55 ✅
```


--- 

