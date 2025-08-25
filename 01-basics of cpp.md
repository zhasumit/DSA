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



### Data-types

- variables are the block to store some data 
- they can be of different types 
- main ones are `int`, 