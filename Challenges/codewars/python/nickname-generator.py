'''
https://www.codewars.com/kata/nickname-generator

Nickname Generator

Write a function, `nicknameGenerator` that takes a string name as an argument and returns the first 3 or 4 letters as a nickname.

If the 3rd letter is a consonant, return the first 3 letters.

```javascript
nickname("Robert") //=> "Rob"
nickname("Kimberly") //=> "Kim"
nickname("Samantha") //=> "Sam"
```

If the 3rd letter is a vowel, return the first 4 letters. 

```javascript
nickname("Jeannie") //=> "Jean"
nickname("Douglas") //=> "Doug"
nickname("Gregory") //=> "Greg"
```

If the string is less than 4 characters, return "Error: Name too short".

**Notes:**

- Vowels are "aeiou", so discount the letter "y".
- Input will always be a string.
- Input will always have the first letter capitalised and the rest lowercase (e.g. Sam).
- The input can be modified

'''
def nickname_generator(name):
    if len(name) < 4: return "Error: Name too short"
    else: return name[:3] if name[2] not in 'aeiou' else name[:4]

if __name__ == '__main__':
    print(nickname_generator('Robert'))
    print(nickname_generator('Jimmy'))
    print(nickname_generator('Kayne'))
    print(nickname_generator('Melissa'))
    print(nickname_generator('Sam'))
    print(nickname_generator('Gregory'))
