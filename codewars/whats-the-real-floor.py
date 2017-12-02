'''
https://www.codewars.com/kata/whats-the-real-floor

# Task Overview
Americans are odd people: in their buildings, the first floor is actually the ground floor and there is no 13th floor ('cause of superstition).

Write a function that given an American floor (passed as an integer) returns the real floor.</br>
Moreover, your function should work for basement floors too: just return the same value as the passed one.

# Usage Examples
```javascript
getRealFloor(1) == 0 
getRealFloor(0) == 0 // Special case to please Europeans
getRealFloor(5) == 4
getRealFloor(15) == 13
getRealFloor(-3) == -3
```
```coffeescript
getRealFloor(1) == 0 
getRealFloor(0) == 0 // Special case to please Europeans
getRealFloor(5) == 4
getRealFloor(15) == 13
getRealFloor(-3) == -3
```
```ruby
get_real_floor(1) == 0 
get_real_floor(0) == 0 # Special case to please Europeans
get_real_floor(5) == 4
get_real_floor(15) == 13
get_real_floor(-3) == -3
```
```python
get_real_floor(1) == 0 
get_real_floor(0) == 0 # Special case to please Europeans
get_real_floor(5) == 4
get_real_floor(15) == 13
get_real_floor(-3) == -3
```
```csharp
GetRealFloor(1) == 0 
GetRealFloor(0) == 0 // Special case to please Europeans
GetRealFloor(5) == 4
GetRealFloor(15) == 13
GetRealFloor(-3) == -3
```
'''
def get_real_floor(n):
    if n <= 0: return n
    if n < 13: return n-1
    if n > 13: return n-2
