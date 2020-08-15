# https://www.codewars.com/kata/find-the-vowels/train/python

def vowel_indices(s):
    res = list()
    for i, c in enumerate(s):
        if c.lower() in {'a', 'e', 'i', 'o', 'u', 'y'}:
           res.append(i+1)
    return res
