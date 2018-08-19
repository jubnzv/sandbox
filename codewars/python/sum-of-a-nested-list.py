'''
https://www.codewars.com/kata/sum-of-a-nested-list

Implement a function to calculate the sum of the numerical values in a nested list. For example :

```python
sum_nested([1, [2, [3, [4]]]]) -> 10
```
'''
sum_nested = lambda lst: sum([sum_nested(i) if isinstance(i, list) else i for i in lst])

if __name__ == '__main__':
    print(sum_nested([1, [2, [3, [4]]]]))
