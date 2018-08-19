'''
https://www.codewars.com/kata/invert-values

Given a set of numbers, return the additive inverse of each.  Each positive becomes negatives, and the negatives become positives.

```javascript
invert([1,2,3,4,5]) == [-1,-2,-3,-4,-5]
invert([1,-2,3,-4,5]) == [-1,2,-3,4,-5]
invert([]) == []
```

```if:javascript,python,ruby,php,elixir
You can assume that all values are integers.
```

```if:c,cpp
### Notes:
- All values are greater than `INT_MIN`
- The input should be modified, not returned.
```
'''
invert = lambda lst: [-i for i in lst]

if __name__ == '__main__':
    print(invert([1,2,3,-4,5]))
    print(invert([]))
