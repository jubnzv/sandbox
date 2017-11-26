'''
https://www.codewars.com/kata/interactive-dictionary

In this kata, your job is to create a class Dictionary which you can add words to and their entries. Example:
```python
>>> d = Dictionary()
>>> d.newentry('Apple', 'A fruit that grows on trees')
>>> print(d.look('Apple'))
A fruit that grows on trees
>>> print(d.look('Banana'))
Cant find entry for Banana
```

```java
Dictionary d = new Dictionary();

d.newEntry("Apple", "A fruit that grows on trees");

System.out.println(d.look("Apple"));
>>> A fruit that grows on trees

System.out.println(d.look("Banana"));
>>> Cant find entry for Banana
```

Good luck and happy coding!
'''
class Dictionary():
    def __init__(self):
        self.d = ((),)
    def newentry(self, word, definition):
        self.d = (word, definition)
    def look(self, key):
        if key == self.d[0]:
            return self.d[1]
        else:
            return "Can't find entry for " + key
