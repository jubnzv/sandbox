#  https://www.codewars.com/kata/5939ab6eed348a945f0007b2/


def longest_word(s):
    last_longest_word = ''
    for w in s.split(' '):
        if len(w) >= len(last_longest_word):
            last_longest_word = w
    return last_longest_word
