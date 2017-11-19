'''
https://www.codewars.com/kata/return-negative

In this simple assignment you are given a number and have to make it negative. But maybe the number is already negative?

**Example:**
``` csharp
Kata.MakeNegative(1); // return -1
Kata.MakeNegative(-5); // return -5
Kata.MakeNegative(0); // return 0
```
``` java
Kata.makeNegative(1); // return -1
Kata.makeNegative(-5); // return -5
Kata.makeNegative(0); // return 0
```
```python
make_negative(1);  # return -1
make_negative(-5); # return -5
make_negative(0);  # return 0
```
``` javascript
makeNegative(1); // return -1
makeNegative(-5); // return -5
makeNegative(0); // return 0
```
``` typescript
makeNegative(1); // return -1
makeNegative(-5); // return -5
makeNegative(0); // return 0
```
``` cpp
makeNegative(1); // return -1
makeNegative(-5); // return -5
makeNegative(0); // return 0
```
``` haskell
makeNegative    1 -- return -1
makeNegative (-5) -- return -5
makeNegative    0 -- return 0
makeNegative 0.12 -- return -0.12
```
``` ruby
makeNegative(1); # return -1
makeNegative(-5); # return -5
makeNegative(0); # return 0
```
``` coffeescript
makeNegative 1    # return -1
makeNegative -5   # return -5
makeNegative 0    # return 0
```
``` elixir
make_negative 1    # return -1
make_negative -5   # return -5
make_negative 0    # return 0
```

**Notes:**

- The number can be negative already, in which case no change is required.
- Zero (0) can't be negative, see examples above.

'''
make_negative = lambda n: -1*abs(n)
