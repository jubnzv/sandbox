'''
https://www.codewars.com/kata/eliminate-the-intruders-bit-manipulation

# Task

You are given a string representing a number in binary. Your task is to delete all the **set** bits in this string and return the corresponding number (after keeping only the '1's). 

In practice, you should implement this function:

## C

```C
long eliminate_set_bits(const char* number);
```

## Python 
```python
def eliminate_set_bits(string):
```

## Java
```java
public long eliminateSetBits(String number);
```

## Examples

```c
* eliminate_set_bits("11010101010101") ->  255 (= 11111111)

* eliminate_set_bits("111") ->  7

* eliminate_set_bits("1000000") -> 1
```

'''
eliminate_set_bits = lambda s: int(s.translate(None, '0'), 2) if s else None
