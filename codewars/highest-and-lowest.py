'''
https://www.codewars.com/kata/highest-and-lowest

In this little assignment you are given a string of space separated numbers, and have to return the highest and lowest number.

**Example:**
``` csharp
Kata.HighAndLow("1 2 3 4 5"); // return "5 1"
Kata.HighAndLow("1 2 -3 4 5"); // return "5 -3"
Kata.HighAndLow("1 9 3 4 -5"); // return "9 -5"
```
```fsharp
highAndLow "1 2 3 4 5"  // return "5 1"
highAndLow "1 2 -3 4 5" // return "5 -3"
highAndLow "1 9 3 4 -5" // return "9 -5"
```
```javascript
highAndLow("1 2 3 4 5"); // return "5 1"
highAndLow("1 2 -3 4 5"); // return "5 -3"
highAndLow("1 9 3 4 -5"); // return "9 -5"
```
```typescript
highAndLow("1 2 3 4 5"); // return "5 1"
highAndLow("1 2 -3 4 5"); // return "5 -3"
highAndLow("1 9 3 4 -5"); // return "9 -5"
```
```coffeescript
highAndLow("1 2 3 4 5") # return "5 1"
highAndLow("1 2 -3 4 5") # return "5 -3"
highAndLow("1 9 3 4 -5") # return "9 -5"
```
```python
high_and_low("1 2 3 4 5")  # return "5 1"
high_and_low("1 2 -3 4 5") # return "5 -3"
high_and_low("1 9 3 4 -5") # return "9 -5"
```
```ruby
high_and_low("1 2 3 4 5")  # return "5 1"
high_and_low("1 2 -3 4 5") # return "5 -3"
high_and_low("1 9 3 4 -5") # return "9 -5"
```
```java
HighAndLow("1 2 3 4 5") // return "5 1"
HighAndLow("1 2 -3 4 5") // return "5 -3"
HighAndLow("1 9 3 4 -5") // return "9 -5"
```
```haskell
highAndLow "1 2 3 4 5")  # return "5 1"
highAndLow "1 2 -3 4 5") # return "5 -3"
highAndLow "1 9 3 4 -5") # return "9 -5"
```

**Notes:**

- All numbers are valid ```Int32```, no *need* to validate them.
- There will always be at least one number in the input string.
- Output string must be two numbers separated by a single space, and highest number is first.
'''
def high_and_low(numbers):
    nl = [int(i) for i in numbers.split(' ')]
    return "{} {}".format(max(nl), min(nl))
