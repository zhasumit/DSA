## Basics of cpp for starting DSA 
### DSA (data structure & algorithm) 

**Programming Language** 
Language is a way of communication between machine and human
Language has a set of rules, there is grammar in language called semantics and way of writing and keywords with which a language is written which is called syntax

The machine understands only `0s` `1s`, so for machine to understand what we write in keywords it converts those keywords and sentences and all the english or some other human understandable format into a machine readable format 
This translation of languages is done by compiler and interpreters 

Compilers are the translators that convert the entire program into the machine readable format **in one go** (in one sweep), whereas for interpreters they convert the High level languages written by us to Machine readable language **line by line**

*c++ is a compiled language*, means it has a compiler that will translate it, so for writing programs in c++, install the compiler for c++ on you machine. **g++** is the compiler needed for compilation of c++ code, and the extension of the file will be `somefilename.cpp`.




<hr>



### skeleton of c++ code 

Library 
- *set of program files that are required by the program*
- *why?* : for operations like Input, output, Math, Terminal, Hardware, etc
- *why don't we write it?* : it is complex code, focus on the necessaries first
- *How to include those?* : using `#include` keyword, and `<>` contains the headers
- *what are headers?* : headers are those libraries that deal with complexities 

skeleton of the code remains almost similar 
just few minor tweaks (like include only the libraries that are being used)
some common headers include `<iostream>` `<math.h>` `<string>`


`main()` is function 
- function is a set of block of code that are executed when called 
- `()` indicates that something is function 
- we call the function by writing it's name 
- but `main()` is called after compilation of the program file 
- it is the main function as the name suggests 
- it is the function that calls other functions 
- all functions in cpp have *return type*
	- *return type* : what kind of value do you expect the function to return
	- like integer, string, decimal, character (will take on later)
	- normally `main()` comes with `int` return type
	- `int` means integer, 
	- so at the end of `main()` we write `return 0`
	- `return 0`: `0` first of all is integer so that's clear since `int` return type 
	- secondly `return 0` means every thing went as expected 
	- `return 1` or some other number `return -100`, means not correct
	- so `return 0`, means every thing went well 


**namespace**
namespace is like making group 
a group that contains a set of variables, functions, classes, objects, etc 
under a name (group name), to avoid conflict
use the keyword `namespace` to start using the namespace 

something like 

```cpp
namespace johnMathCalculations {
    int add(int a, int b) {
        return a + b;
    }
}
```

so a bunch of functions are written in namespace std;
**std** is the standard namespace (group) that contains some functions 
functions like `cin` and `cout` used to take input (using `cin`) and output(using `cout`)

#### combined header 
save the hassle of writing multiple headers and include just a combined header
now there is a header that contains the group of all headers needed for execution of programs in cpp and for the technical data structures that are going to be used in solving the data structures. `<bits/stdc++.h>`

combining all the above knowledge this is the skeleton that is to be used in almost all the programs for execution 

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    return 0;
}
```


`using namespace std;`
- makes using std namespace easier 
- how? : without using namespace std we write much more 
- group / namespace is accessed using 
	- `namespace_name::function_name`
	- `std::cin` or `std::cout`
	- but if we write `using namespace std;`
	- then we only write `cout` and `cin`





<hr>




### `I/O` in c++

#### Output
Printing something on the terminal 
- `cout` along with `<<` operator
- `cout << "This will be printed on terminal";`
- `;` denotes end of line `EOL` in `cpp`
- `<<` can be chained (written one after another)
-  `cout << ... << ... ;`
- `cout <<"Hi, " << "How are you?, "<< "Nice to meet you!";`


#### escape sequence 
- these are the special characters that are used in string 
- string is something written between `""`
- string is a series of characters
- escape sequences have different meanings 
- eg: `\n` means new line (enter key) on keyboard
	- so `\n` literally prints or shifts text to next line 

eg : `cout << "Hi \nHow are you?"`

output: 
```txt
Hi
How are you?
``` 

some escape sequences are like 

| Escape sequence | Description                                   |
| --------------- | --------------------------------------------- |
| `\\`            | Backslash                                     |
| `\'`            | Single quote                                  |
| `\"`            | Double quote                                  |
| `\?`            | Question mark                                 |
| `\a`            | Audible alert (bell)                          |
| `\b`            | Backspace                                     |
| `\f`            | Form feed (page break)                        |
| `\n`            | Newline (line feed)                           |
| `\r`            | Carriage return                               |
| `\t`            | Horizontal tab                                |
| `\v`            | Vertical tab                                  |
| `\0`            | null character                                |
| `\xhh`          | Represents the character with hex value hh    |
| `\nnn`          | Represents the character with octal value nnn |
| `\uhhhh`        | Unicode character (16-bit)                    |
| `\Uhhhhhhhh`    | Unicode character (32-bit)                    |


Newline in string printing
- `endl` is from `std` namespace 
- but `\n` is faster 
- so in competitive environments use `std::endl`
- write `using namespace std;` for not writing `std::` part
- `cout << "Hi" << endl << "How are you?";`

Output:
```txt
Hi
How are you?
```



#### Input
getting some input from the terminal 
- `cin` along with `>>` operator
- `cin << someVariable`
- `>>` can be chained like `cin >> ... >> ... ;`


How to store something (will take in detail later)
- variables are used to store some data 
- data can be of different types like integer, character, decimal, etc
- lets take integer for now to understanding `cin`
- `int` is written before writing a variable to denote the data-type 
- this denotes that the value will be integer only 
- eg : `int length;` `int breadth;`
	- denotes that `length` and `breadth` variables will be of integer type

back to taking input now 

```cpp
// declaration of variables (zero by default)
int length;  // 0
int breadth; // 0

// output(prompt on terminal) and input from user
cout << "Enter the length: ";
cin >> length;

cout << "Enter the breadth: ";
cin >> breadth;

// printing values of the variables
cout << "Length: " << length << endl;
cout << "Breadth: " << breadth << endl;
```


In chaining the sequence of input matters 
`cin >> length >> breadth;` will take length first and breadth after that 
`cin >> breadth >> length;` will take breadth first and length after that 




<hr>



### Comments in CPP
`//` is used for comment in cpp
`/**/` is for multiple line comments




<hr>



### Data-types

- variables are the block to store some data 
- they can be of different types 
- main ones are `int`,  `char`, `long`, `float`, `double`, etc
- after the data type we write the name of the variable
- `int x = 10;`, 
	- `int` is datatype, 
	- `x` is name of the variable, 
	- `=` assignment, 
	- `10` is the value to be inserted
- `long` has a wider range than `int`, 
- `long long` has bigger range than `long`

#### naming a variable
- DO's
	- starts with a character `a-z` or `A-Z`
	- `_` underline allowed in starting
- Dont's
	- no numbers in in the starting `0-9`
	- no special symbols in the starting
- Here is the range of values that can be stored in the data-types

#### Basic data-types that can be solving almost all the problems 

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x = 10;             // normal integers              (10^-9 <= x <= 10^9)
    long y = 20;            // somewhat bigger than int     (10^-12 <= x <= 10^12)
    long long xy = 1500000; // too long integer             (10^-15 <= x <= 10^15)

    // for decimal numbers
    float z = 3.14;     // simple one
    double d = 4.35645; // larger decimals

    // for single characters
    char ch = 'c';
    string str = "hello world";

    // for getting the values in string we can use getline
    // getline gets the line till the `\n` or endline character
    // cin takes the things till a whitespace
    string s1, s2;
    cin >> s1 >> s2;
    cout << s1 << s2;

    // gets the entire line with the whitespaces till the endline is found
    string s3;
    getline(cin, s3);

    return 0;
}
```


#### Detailed list of data-types and the ranges

| Data Type            | Size (Bytes) | Range                                                   | Rough Range for Humans                                            |
| -------------------- | ------------ | ------------------------------------------------------- | ----------------------------------------------------------------- |
| `char`               | 1            | -128 to 127                                             | ~-100 to 100 (small integers/ASCII)                               |
| `unsigned char`      | 1            | 0 to 255                                                | 0 to ~250 (small positive integers)                               |
| `short`              | 2            | -32,768 to 32,767                                       | ~-32,000 to 32,000 (age, small counts)                            |
| `unsigned short`     | 2            | 0 to 65,535                                             | 0 to ~65,000 (large counts like stadium size)                     |
| `int`                | 4            | -2,147,483,648 to 2,147,483,647                         | ~-2 billion to 2 billion (population counts) <br><br>10^9 - 10^-9 |
| `unsigned int`       | 4            | 0 to 4,294,967,295                                      | 0 to ~4 billion (large counts)                                    |
| `long`               | 4 or 8       | -2,147,483,648 to 2,147,483,647 (4 bytes)               | Matches int or long long (system dependent)<br><br>10^12 - 10^-12 |
| `unsigned long`      | 4 or 8       | 0 to 4,294,967,295 (4 bytes)                            | Matches unsigned int or unsigned long long                        |
| `long long`          | 8            | -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 | ~-9 quintillion to 9 quintillion<br><br>10^12 - 10^-12            |
| `unsigned long long` | 8            | 0 to 18,446,744,073,709,551,615                         | 0 to ~18 quintillion                                              |
| `float`              | 4            | 1.17549e-38 to 3.40282e+38                              | 6-7 decimal digits precision (e.g. 0.000001, 1234.56)             |
| `double`             | 8            | 2.22507e-308 to 1.79769e+308                            | 15-16 decimal digits precision (scientific values)                |
| `long double`        | 8, 12, or 16 | 3.4e-4932 to 1.1e+4932 (implementation-defined)         | Extended precision for specialized calculations                   |
| `bool`               | 1            | 0 (false) or 1 (true)                                   | True or false                                                     |
| `wchar_t`            | 2 or 4       | 1 wide character                                        | Unicode characters                                                |


#### Modifiers
C++ **type modifiers** are keywords that alter the behavior, size, or range of built-in data types. Here is a Markdown table summarizing the main modifiers.

| Modifier   | Effect                                                 | Usage Example                   | Applicable Data Types |
| ---------- | ------------------------------------------------------ | ------------------------------- | --------------------- |
| `signed`   | Allows both positive & negative values                 | `signed int x;`                 | int, char             |
| `unsigned` | Only non-negative values (doubles the positive range)  | `unsigned int x;`               | int, char             |
| `short`    | Reduces the size (and range) of integer types          | `short int x;`                  | int                   |
| `long`     | Increases the size (and range) of integer/double types | `long int x;`, `long double y;` | int, double           |


<hr>


### Conditional statements (if-else)
- `true` -> `if` part is executed 
- `false` -> `else` part is executed
- `if` can be put independently 
- `else` is always paired with the `if` statements 
- `else if` are the subbranches that can be extended in both `if` and `else`
- `else if` can be put in both `if` and `else`, `else` is the last resort 
- `else if` are the middle grounds between `if` and `else`

```cpp
int age = 20;
cin >> age;
if (age >= 18)
	cout << "Can vote";
else
	cout << "Can't vote";
```
```txt
Can vote
```

#### else if
- making a school grading system for better understanding of branching
- `else if` is there for branching of different values 

```cpp
int marks = 65;
if (marks > 100)
	cout << "Invalid marks";
else if (marks > 80)
	cout << "A";
else if (marks > 60)
	cout << "B";
else if (marks > 50)
	cout << "C";
else if (marks > 45)
	cout << "D";
else if (marks >= 25)
	cout << "E";
else
	cout << "F";
```
```txt
B
```


#### Nested if else statements 
- writing `if else` inside other `if else` statements
- nested means statements inside other statements 

```cpp
 int age = 56;
if (age < 18)
	cout << "Not eligible for job" << endl;
else if (age <= 60)
{
	cout << "Eligible for job" << endl;
	if (age >= 55)
		cout << ", but retirement soon" << endl;
}
else
	cout << "Not eligible for job" << endl;
```
```txt
Eligible for job, but retirement soon
```




<hr>



### Switch statements 
- switch also takes a condition and works on the case 
- the condition here is called case 
- `switch (condition){}` is the base one 
- `break` used after every case to make others stop execution
- if `break` is removed all the other cases after the current will be executed
- `default` is give like the last `else` statement for final fallout option

```cpp
int day = 6;
switch (day)
{
case 1:
	cout << "Monday";
	break;
case 2:
	cout << "Tuesday";
	break;
case 3:
	cout << "Wednesday";
	break;
case 4:
	cout << "Thursday";
	break;
case 5:
	cout << "Friday";
	break;
case 6:
	cout << "Saturday";
	break;
case 7:
	cout << "Sunday";
	break;
default:
	cout << "Invalid day";
}
```
```txt
Saturday
```




<hr>




### Arrays 
- if a lot of data is taken then we can define multiple variables 
- for getting a variable that can store multiple values
- `array` is a set of __consecutive__ space
- space one after another (after the sizeof(variable)) 
- so we can jump `index * sizeof(variable)` to get the value of the data 

| 0x16 | 0x17 | 0x18 | 0x19 | 0x1A | 0x1B | 0x1C |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 1    | 2    | 3    | 4    | 5    | 6    | 7    |

Explanation:
- The first element is stored at address `0x16`.
- Each subsequent element is stored at the next consecutive byte address 
- (incrementing by 1 in hex).
- This is typical for arrays where elements are stored contiguously in memory.

| index | address | element |
| ----- | ------- | ------- |
| 0     | `0x16`  | 1       |
| 1     | `0x17`  | 2       |
| 2     | `0x18`  | 3       |
| 3     | `0x19`  | 4       |
| 4     | `0x1A`  | 5       |
| 5     | `0x1B`  | 6       |
| 6     | `0x1C`  | 7       |

- index takes the formula of `index * sizeof(datatype)`
- `arr[index]` jumps by that many contiguous locations and finds the value of the variable



```cpp
int arr[7] = {1, 2, 3, 4, 5, 6, 7};
cout << arr[0] << endl;
cout << arr[1] << endl;
cout << arr[2] << endl;
cout << arr[3] << endl;
cout << arr[4] << endl;
cout << arr[5] << endl;
cout << arr[6] << endl;
```
```txt
1
2
3
4
5
6
7
```



- making array of zeros, do the first one zero and rest will be zero, `int arr[10] = {0}`;
- automatically getting size, `int arr[] = {1, 2, 3, 4, 5};`, arr gets size 5 automatically


### 2D array
- array inside the array 
- if 3 or more array - multi dimensional array 
- rows are the horizontal ones `__`
- columns are the vertical ones `|`
- `int arr[row][col]` is used to make the array or rows, columns
- indexing always starts from 0,0

example of indexing for `int arr[4][5]`

|       |  `j=0`  |  `j=1`  |  `j=2`  |  `j=3`  |  `j=4`  |
| :---: | :-----: | :-----: | :-----: | :-----: | :-----: |
| `i=0` | `(0,0)` | `(0,1)` | `(0,2)` | `(0,3)` | `(0,4)` |
| `i=1` | `(1,0)` | `(1,1)` | `(1,2)` | `(1,3)` | `(1,4)` |
| `i=2` | `(2,0)` | `(2,1)` | `(2,2)` | `(2,3)` | `(2,4)` |
| `i=3` | `(3,0)` | `(3,1)` | `(3,2)` | `(3,4)` | `(3,4)` |

`int arr[1][2] = 16;`, makes the element on that location
`cout << int arr[1][2];`, shows the element on terminal

|       | `j=0` | `j=1` | `j=2` | `j=3` | `j=4` |
| :---: | :---: | :---: | :---: | :---: | :---: |
| `i=0` |   2   |   4   |   6   |   8   |  10   |
| `i=1` |  12   |  14   |  16   |  18   |  20   |
| `i=2` |   3   |   6   |   9   |  12   |  15   |
| `i=3` |  18   |  21   |  24   |  27   |  30   |

- unassigned locations will have garbage values 
- used to solve a lot of matrix and graph problems
-  later on it will be in depth covered 




<hr>



### strings 
- string stores the characters in array
- so strings are basically array of characters 
- but strings have some functions that are predefined and useful
- `char arr[]` is the array of characters, than is string
- `string s = "Sumit"` makes a string of s variable with `Sumit` value
- `int len = s.size()`, gives the length of the string 
- then access the value in different positions using the `len`
	- `s[0]` first index value of string, `s[1]`, `s[2]`, ... , `s[len-1]` gives last element
	- since `len` gives number of values in string, and `len-1` is the last element (`0 indexed`)




<hr>



### loops 
- doing an operation a number of times 
- like printing a thing 10 times, we do `cout<<"something"` 10 times 
- what about 500 times, we do it 500 times
- but there comes pros that use loop, helps do a set of operations in `{}` multiple times
- loops follow three things 
	- **initialization** : get a starting value (variable), that is manipulated to run the loop
	- **Condition** : check the value in the loop every iteration to run or stop 
	- **Increment/Decrement** : to change the intermediate values of the condition variable
- so now just take a variable `i`, put some check on it for `25` or `500` or whatever `#iterations`
- which makes the loop work for that many number of iterations 

```cpp
// for loop
for (int i = 0; i <= 10; i++) {
	cout << "Sumit" << endl;
}
```

```cpp
// while loop
int i = 10;
while (i) { // checks for i everytime (if i>0 -> True), so loop runs
	cout << "Sumit" << endl;
	i--;
}
```

- for executing minimum of 1 times 
- no matter what the condition the loop is executed for 1 time
```cpp
// do while 
int i = 1;
do {
	cout << "Sumit" << endl;
	i++;
} while (i > 10);
```

```txt
Sumit
Sumit
Sumit
Sumit
Sumit
Sumit
Sumit
Sumit
Sumit
Sumit
```




<hr>



### Functions pass by reference and pass by value
- function are set of code that performs some task
- modularization of the code, and increase readability
- used to call same set of code multiple times 
- **types** : 
	- `void` : does not return anything
	- `parameterized` : some parameters in the function definition 
	- `Non-parametrized` : no parameters, so generic tasks, without parameters/arguments
- parameters are the variables in the function definition
- arguments are written while calling the function (in function call)

##### general format of the function
```cpp
returntype/void functionName(datatype params...){ // no params can also be passed
	// some block of code that has to be performed
	// return or not-return(if void type)
}
```

##### some examples of the functions 
```cpp
void greet() { cout << "hello" << endl; }
void printName(string name) { cout << "Hi" << name << endl; }
void printName(string name, int age) { cout << "Hi" << name << endl; }
int sum(int a, int b) { return a + b; }
int maximum(int a, int b) { return a > b ? a : b; }
```


### pass by value 
- pass by value is simple calling where no reference is used 
- a copy of the values are passed to the function 
- any changes to the values in the functions are not reflected in the original variable 
- so the original variable remains unchanged *just the function values are changed*

```cpp
#include <bits/stdc++.h>
using namespace std;

string capitalize(string str) {
    str[0] = toupper(str[0]);
    return str;
}

int main() {
    string str = "hello";
    cout << capitalize(str); // Hello
    cout << str;             // hello
}
```


### pass by reference
- reference is taken using the `&` operator
- `void doSomething(string &str){}`
- in this if any changes are done then it reflects in the original point 
- the point which calls the function also gets effected
- the variables get changed after passing
- **NOTE**: arrays always go with reference even without `&`
- since `int arr[]` is a pointer `*` 
- in reality `int *arr` as the base pointer for array 
- so any change in array changes the real values 

```cpp
#include <bits/stdc++.h>
using namespace std;

void capitalize(string &str) { str[0] = toupper(str[0]); }

int main() {
    string str = "hello";
    capitalize(str);
    cout << str; // Hello
}
```
