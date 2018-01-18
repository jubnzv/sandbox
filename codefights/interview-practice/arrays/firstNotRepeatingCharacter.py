'''
https://codefights.com/interview-practice/task/uX5iLwhc6L5ckSyNC

Given a string s, find and return the first instance of a non-repeating character in it. If there is no such character, return '_'.
'''
from string import ascii_lowercase

def firstNotRepeatingCharacter(s):
    seen = {k: -1 for k in ascii_lowercase}
    for i, c in enumerate(s):
        if c in seen:
            if seen[c] == -1:
                seen[c] = i
            else:
                seen.pop(c)
    seen = {k: v for k, v in seen.items() if v != -1}
    if not seen:
        return '_'
    else:
        return min(seen, key=seen.get)

if __name__ == '__main__':
    print(firstNotRepeatingCharacter('abacabad'))
    print(firstNotRepeatingCharacter('bacabaabacaba'))
