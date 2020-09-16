# https://www.codewars.com/kata/51b6249c4612257ac0000005/solutions/python
def solution(r):
    v = {
        'M': 1000,
        'D': 500,
        'C': 100,
        'L': 50,
        'X': 10,
        'V': 5,
        'I': 1
    }
    p, a = 0, 0
    for i in range(len(r)-1, -1, -1):
        if v[r[i]] >= p:
            a += v[r[i]]
        else:
            a -= v[r[i]]
        p = v[r[i]]
    return a
