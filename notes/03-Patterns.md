# Patterns 

- all the patterns has nested loops 
- there are two loops 
	- outer loop is for the `#lines`, or `#rows` `__`, horizontal
	- inner loops are for the `#columns` `|`, vertical
- some rules 
	- count the `#lines`
	- for the inner loops focus on `#columns`,  connect `#columns` and `#rows` somehow
	- print the printable `x` inside the inner loops 
	- observe symmetry 


## Pattern 1
```txt
x x x x x 
x x x x x 
x x x x x 
x x x x x 
x x x x x 
```

- total `#rows` = 5, `#columns` = 5
- so `#rows` = `#cols` => `i = j`
- print `x` inside the inner for loop

```cpp
for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++)
		cout << "x ";
	cout << endl;
}
```




<hr>



## Pattern 2

### variant 1

```txt
x
x x 
x x x 
x x x x 
x x x x x 
```

- total `#rows` = 5 
- `#cols` = 1, for `i = 1`, 
- `#cols` = 2, for `i = 2`, 
- `#cols` = 3, for `i = 3`,
- so `#cols` = n for `i = n`
- so `#cols <= i` for `i = n`

```cpp
for (int i = 0; i < n; i++) {
	for (int j = 0; j <= i; j++)
		cout << "x ";
	cout << endl;
}
```



### variant 2

```txt
1
1 2 
1 2 3 
1 2 3 4 
1 2 3 4 5 
```

- `#cols <= i` for `i = n`
- but instead of `x` the printable is some number and the number starts with 1 everytime
- and for every row the `col#` starts with 0 so make it `j+1`
```cpp
for (int i = 0; i < n; i++) {
	for (int j = 0; j <= i; j++)
		cout << j + 1 << " ";
	cout << endl;
}
```



### variant 3

```txt
1
2 2
3 3 3 
4 4 4 4 
5 5 5 5 5 
```

- `#cols <= i` for `i = n`
- printable is some number and the number starts with some definite number
- This definite number is same as the `row#`.

```cpp
for (int i = 0; i < n; i++) {
	for (int j = 0; j <= i; j++)
		cout << i + 1 << " ";
	cout << endl;
}
```




### variant 4

```txt
1
2  3 
4  5  6
7  8  9  10
11 12 13 14 15
```

- `#cols <= i` for `i = n`
- printable is a number that is always increasing
- so take a number and increase it in every iteration

```cpp
int num = 0;
for (int i = 0; i < n; i++) {
	for (int j = 0; j <= i; j++)
		cout << ++num << " ";
	cout << endl;
}
```



### variant 5

```txt
A 
A B 
A B C 
A B C D 
A B C D E
```

- `#cols <= i` for `i = n`
- printable is some character and that starts with A every time.
- so start with `A` and add `col#` in iteration to increase it 

```cpp
for (int i = 0; i < n; i++) {
	for (int j = 0; j <= i; j++)
		cout << char('A' + j) << " ";
	cout << endl;
}
```




### variant 6

```txt
A 
B B
C C C
D D D D
E E E E E
```

- `#cols <= i` for `i = n`
- printable is some character that resembles `row# + A`.

```cpp
for (int i = 0; i < n; i++) {
	for (int j = 0; j <= i; j++)
		cout << char('A' + i) << " ";
	cout << endl;
}
```




### variant 7

```txt
E
D E 
C D E
B C D E
A B C D E
```

- `#cols <= i` for `i = n`
- stars with `E`, or `n + A`, where n is `#row`
- and in the inner loop for every column it is decreasing till `j` runs
- or in other way make the initial as `n + A - j - 1` so starts with lower character
- and then increase the character till the end of the columns 
	- - `n - 1` fixes the “end at last letter”
	- `- j` moves the start point back each row
	- `j` counting down ensures printing goes left → right in each row

- `n + A - j - 1`
	- The last letter in the pattern is always **`'A' + n - 1`**.
	- For `n = 5`, that is `'A' + 4 = 'E'`.
	- So every row must **end at `E`**.
	- `i` controls the row number (0-based).
	- Row 0 → 1 letter, Row 1 → 2 letters, … Row 4 → 5 letters.
	- `j` runs **backward** from `i` down to `0`.
	- Because the starting letter of the row should move leftward (back in the alphabet) as i increases.
	  - `n - 1` = index of the last letter (`E` → index 4).
	- Subtract `j` to move left from `E`.
	- Example:
	    - Row 0: `i=0`, `j=0` → `'A' + 4 - 0 = 'E'`.
	    - Row 1: `j=1 → 'D'`, `j=0 → 'E'`.
	    - Row 2: `j=2 → 'C'`, `j=1 → 'D'`, `j=0 → 'E'`.
	    - And so on.
	    - So the inner loop always prints **from the correct leftmost letter up to `E`**.

### Row by row expansion

- **Row 0 (`i=0`):**  
    `j=0 → 'E'`  
    → prints `E`
    
- **Row 1 (`i=1`):**  
    `j=1 → 'D'`, `j=0 → 'E'`  
    → prints `D E`
    
- **Row 2 (`i=2`):**  
    `j=2 → 'C'`, `j=1 → 'D'`, `j=0 → 'E'`  
    → prints `C D E`
    
- **Row 3 (`i=3`):**  
    `j=3 → 'B'`, `j=2 → 'C'`, `j=1 → 'D'`, `j=0 → 'E'`  
    → prints `B C D E`
    
- **Row 4 (`i=4`):**  
    `j=4 → 'A'`, `j=3 → 'B'`, `j=2 → 'C'`, `j=1 → 'D'`, `j=0 → 'E'`  
    → prints `A B C D E`

```cpp
for (int i = 0; i < n; i++) {
	for (int j = i; j >= 0; j--)
		cout << char('A' + n - 1 - j) << " ";
	cout << endl;
}
```




### variant 8

```txt
1
0 1
1 0 1
0 1 0 1
1 0 1 0 1
```

- `#cols <= i` for `i = n`
- printable is some character always `0` or `1`
- odd `row#` starts with 1, even `row#` starts with 0
- then toggle the bit every time

- using bit toggling
```cpp
for (int i = 0; i < n; i++) {
	bool bit = !(i & 1);
	for (int j = 0; j <= i; j++) {
		cout << bit << " ";
		bit = !bit;
	}
	cout << endl;
}
```


using parity of position 
- The meaning of `(i + j) % 2`
	- `i` = row index
	- `j` = column index
When you add them together
- If `i + j` is **even**, `(i + j) % 2 = 0`
- If `i + j` is **odd**, `(i + j) % 2 = 1`
So this naturally makes a **checkerboard pattern** of 0 and 1.

Example (`(i + j) % 2`):
- Row 0 → `(0+0)=0 → 0`  
- Row 1 → `(1+0)=1 → 1, (1+1)=2 → 0`  
- Row 2 → `(2+0)=2 → 0, (2+1)=3 → 1, (2+2)=4 → 0`

now flip the switch since that is the pattern in the question 
that can be done by adding `1`

```cpp
for (int i = 0; i < n; i++) {
	for (int j = 0; j <= i; j++)
		cout << (i + j + 1) % 2 << " ";
	cout << endl;
}
```




<hr>



## Pattern 3

### variant 1

```txt
x x x x x 
x x x x 
x x x  
x x  
x 
```

- total `#rows` = 5, `#col` = 5
- total `#rows` = 4, `#col` = 4
- total `#rows` = 3, `#col` = 3
- total `#rows` = n, `#col` = n
- but here the value of the rows start with 5 or `n` and reduces eventually 
- so we start from `i = n`,  `i > 0` and for the condition it should reduce so `i--`
- so `#rows` = `#cols` => `i = j`
- print `x` inside the inner for loop

```cpp
for (int i = n; i > 0; i--) {
	for (int j = 0; j < i; j++)
		cout << "x ";
	cout << endl;
}
```




### variant 2

```txt
1 2 3 4 5 
1 2 3 4
1 2 3
1 2
1
```

- total `#rows` = n, `#col` = n, so `#rows` = `#cols` => `i = j`
- so we start from `i = n`,  `i > 0` and for the condition it should reduce so `i--`
- for the printable it starts with `1` and ends till `#col` value since it is starting with `n`

```cpp
for (int i = n; i > 0; i--) {
	for (int j = 1; j <= i; j++)
		cout << j << " ";
	cout << endl;
}
```



### variant 3

```txt
A B C D E
A B C D
A B C
A B
A 
```

- total `#rows` = n, `#col` = n, so `#rows` = `#cols` => `i = j`
- for the printable it starts with `A` and ends till `#col` value since it is starting with `n`

```cpp
for (int i = n; i > 0; i--) {
	for (int j = 0; j < i; j++)
		cout << char(j + 'A') << " ";
	cout << endl;
}
```




<hr>



## Pattern 4 
combining the triangles 
```
_ _ _ _ x _ _ _ _
_ _ _ x x x _ _ _
_ _ x x x x x _ _
_ x x x x x x x _
x x x x x x x x x
```

- `_` represent space 

| row# | spaces | stars |             |         |
| ---- | ------ | ----- | ----------- | ------- |
| 0    | 4      | 1     | row + 1     | `2*i+1` |
| 1    | 3      | 3     | row + 1 + 2 | `2*i+1` |
| 2    | 1      | 5     | row + 1 + 4 | `2*i+1` |
| 3    | 2      | 7     | row + 1 + 6 | `2*i+1` |
| 4    | 0      | 9     | row + 1 + 8 | `2*i+1` |

- spaces and row number are inverted so make row start from end `n`
- this makes n and space same times so print the spaces till `i`
- stars start from `1` and in every row `+2` is done

```cpp
for (int i = 0; i < n; i++) {
	// spaces
	for (int k = 0; k < n - i - 1; k++)
		cout << "_ ";

	// stars
	for (int j = 0; j < 2 * i + 1; j++)
		cout << "x ";

	// stars
	for (int k = 0; k < n - i - 1; k++)
		cout << "_ ";
	cout << endl;
}
```




<hr>



## Pattern 5
combining the triangles 
```
x x x x x x x x x
_ x x x x x x x _
_ _ x x x x x _ _
_ _ _ x x x _ _ _
_ _ _ _ x _ _ _ _
```

| row# | spaces | stars |             |               |
| ---- | ------ | ----- | ----------- | ------------- |
| 0    | 0      | 9     | row + 1 + 8 | `2*(n - i)-1` |
| 1    | 1      | 7     | row + 1 + 6 | `2*(n - i)-1` |
| 2    | 2      | 5     | row + 1 + 4 | `2*(n - i)-1` |
| 3    | 3      | 3     | row + 1 + 2 | `2*(n - i)-1` |
| 4    | 4      | 1     | row + 1 + 0 | `2*(n - i)-1` |

- spaces and row number are inverted so make row start from end `n`
- this makes n and space same times so print the spaces till `i`
- stars start from `1` and in every row `+2` is done

```cpp
for (int i = 0; i < n; i++) {
	// spaces
	for (int k = 0; k < n - i - 1; k++)
		cout << "_ ";

	// stars
	for (int j = 0; j < 2 * i + 1; j++)
		cout << "x ";

	// stars
	for (int k = 0; k < n - i - 1; k++)
		cout << "_ ";
	cout << endl;
}
```




<hr>




## Pattern 6
top and bottom triangles combined 

```txt
_ _ _ _ x _ _ _ _
_ _ _ x x x _ _ _
_ _ x x x x x _ _
_ x x x x x x x _
x x x x x x x x x
x x x x x x x x x
_ x x x x x x x _
_ _ x x x x x _ _
_ _ _ x x x _ _ _
_ _ _ _ x _ _ _ _
```


- combine both the above code 

```cpp
for (int i = 0; i < n; i++)
{
	// spaces
	for (int k = 0; k < n - i - 1; k++)
		cout << "_ ";

	// stars
	for (int j = 0; j < 2 * i + 1; j++)
		cout << "x ";

	// stars
	for (int k = 0; k < n - i - 1; k++)
		cout << "_ ";
	cout << endl;
}
for (int i = 0; i < n; i++)
{
	// spaces
	for (int k = 0; k < i; k++)
		cout << "_ ";

	// stars
	for (int j = 0; j < 2 * (n - i) - 1; j++)
		cout << "x ";

	// spaces
	for (int k = 0; k < i; k++)
		cout << "_ ";
	cout << endl;
}
```





<hr>




## Pattern 7
Halved triangles 

```txt
x
x x
x x x
x x x x 
x x x x x
x x x x
x x x 
x x
x
```

This can be broken into two parts 
```txt
x
x x
x x x
x x x x 
x x x x x
```

```cpp
for (int i = 0; i < n; i++) {
	for (int j = 0; j <= i; j++)
		cout << "x ";
	cout << endl;
}
```

```txt
x x x x
x x x 
x x
x
```

```cpp
for (int i = n - 1; i > 0; i--) {
	for (int j = 0; j < i; j++)
		cout << "x ";
	cout << endl;
}
```

combining the code for upper and lower triangles 

```cpp
for (int i = 0; i < n; i++) {
	for (int j = 0; j <= i; j++)
		cout << "x ";
	cout << endl;
}

for (int i = n - 1; i > 0; i--) {
	for (int j = 0; j < i; j++)
		cout << "x ";
	cout << endl;
}
```




<hr>



## Pattern 8
```txt
1 _ _ _ _ _ _ _ _ 1
1 2 _ _ _ _ _ _ 2 1 
1 2 3 _ _ _ _ 3 2 1 
1 2 3 4 _ _ 4 3 2 1
1 2 3 4 5 5 4 3 2 1
```


| row# | spaces | set 1 | set2    |
| ---- | ------ | ----- | ------- |
| 0    | 8      | 1     | 1 (rev) |
| 1    | 6      | 2     | 2 (rev) |
| 2    | 4      | 3     | 3 (rev) |
| 3    | 2      | 4     | 4 (rev) |
| 4    | 0      | 5     | 5 (rev) |

```cpp
for (int i = 0; i < n; i++) {
	for (int j = 0; j <= i; j++)
		cout << j + 1 << " ";

	int spaces = 2 * (n - i - 1);
	for (int k = 0; k < spaces; k++)
		cout << "_ ";

	for (int j = i + 1; j > 0; j--)
		cout << j << " ";
	cout << endl;
}
```




<hr>





## Pattern 9
```txt
_ _ _ _ A
_ _ _ A B A 
_ _ A B C B A
_ A B C D C B A
A B C D E D C B A
```

| row# | spaces | set 1 | set2    |
| ---- | ------ | ----- | ------- |
| 0    | 4      | 0     | 1 (rev) |
| 1    | 3      | 1     | 2 (rev) |
| 2    | 2      | 2     | 3 (rev) |
| 3    | 1      | 3     | 4 (rev) |
| 4    | 0      | 4     | 5 (rev) |

```cpp
for (int i = 0; i < n; i++) {
	for (int k = 0; k < n - i - 1; k++)
		cout << "_ ";

	for (int j = 0; j < i; j++)
		cout << char('A' + j) << " ";
	
	for (int j = i; j >= 0; j--)
		cout << char('A' + j) << " ";
	cout << endl;
}
```




<hr>




## Pattern 10
```txt
x x x x x x x x x x
x x x x _ _ x x x x
x x x _ _ _ _ x x x
x x _ _ _ _ _ _ x x
x _ _ _ _ _ _ _ _ x
x _ _ _ _ _ _ _ _ x
x x _ _ _ _ _ _ x x
x x x _ _ _ _ x x x
x x x x _ _ x x x x
x x x x x x x x x x
```

```txt
x x x x x x x x x x
x x x x _ _ x x x x
x x x _ _ _ _ x x x
x x _ _ _ _ _ _ x x
x _ _ _ _ _ _ _ _ x
```


| row `n-1 to 0` | stars1 `i to 0` | spaces `2*(n-i-1)` | stars2 |
| -------------- | --------------- | ------------------ | ------ |
| 0              | 5               | 0                  | 5      |
| 1              | 4               | 2                  | 4      |
| 2              | 3               | 4                  | 3      |
| 3              | 2               | 6                  | 2      |
| 4              | 1               | 8                  | 1      |

```txt
x _ _ _ _ _ _ _ _ x
x x _ _ _ _ _ _ x x
x x x _ _ _ _ x x x
x x x x _ _ x x x x
x x x x x x x x x x
```

| row `0 to n` | stars1 `i to 0` | spaces `2*(n-i-1)` | stars2 |
| ------------ | --------------- | ------------------ | ------ |
| 0            | 1               | 0                  | 1      |
| 1            | 2               | 2                  | 2      |
| 2            | 3               | 4                  | 3      |
| 3            | 4               | 6                  | 4      |
| 4            | 5               | 8                  | 5      |

```cpp
for (int i = n-1; i >= 0; i--) {
	for (int j = i; j >= 0; j--)
		cout << "x ";

	int spaces = 2 * (n - i - 1);
	for (int k = 0; k < spaces; k++)
		cout << "_ ";

	for (int j = i; j >= 0; j--)
		cout << "x ";
	cout << endl;
}

for (int i = 0; i < n; i++) {
	for (int j = i; j >= 0; j--)
		cout << "x ";

	int spaces = 2 * (n - i - 1);
	for (int k = 0; k < spaces; k++)
		cout << "_ ";

	for (int j = i; j >= 0; j--)
		cout << "x ";
	cout << endl;
}
```





<hr>




## Pattern 11

```txt
x _ _ _ _ _ _ _ _ x
x x _ _ _ _ _ _ x x 
x x x _ _ _ _ x x x 
x x x x _ _ x x x x
x x x x x x x x x x
x x x x _ _ x x x x
x x x _ _ _ _ x x x 
x x _ _ _ _ _ _ x x 
x _ _ _ _ _ _ _ _ x
```

- the upper part is same as pattern 8 and the blow one is inverted pattern 8
- or in another way it is same as pattern 10 pattern 10 was having 2 parts 
- here in this figure the top part is part 2 of pattern 10

```cpp
for (int i = 0; i < n; i++) {
	for (int j = i; j >= 0; j--)
		cout << "x ";

	int spaces = 2 * (n - i - 1);
	for (int k = 0; k < spaces; k++)
		cout << "_ ";

	for (int j = i; j >= 0; j--)
		cout << "x ";
	cout << endl;
}

for (int i = n - 2; i >= 0; i--) {
	for (int j = i; j >= 0; j--)
		cout << "x ";

	int spaces = 2 * (n - i - 1);
	for (int k = 0; k < spaces; k++)
		cout << "_ ";

	for (int j = i; j >= 0; j--)
		cout << "x ";
	cout << endl;
}
```




<hr>




## Pattern 12

```txt
x x x x x
x _ _ _ x
x _ _ _ x
x _ _ _ x
x x x x x
```


- on the first and last put all the `x`
- other wise first and last `x`

```cpp
for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++)
		if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
			cout << "x ";
		else
			cout << "_ ";
	cout << endl;
}
```




<hr>
