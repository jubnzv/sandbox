# https://www.codewars.com/kata/love-vs-friendship
#
# If　a = 1, b = 2, c = 3 ... z = 26
# Then l + o + v + e = 54
# and f + r + i + e + n + d + s + h + i + p = 108
# So friendship is twice stronger than love :-)
#
# The input will always be in lowercase and never be empty.
#!/usr/local/bin/python3.6
def words_to_marks(s): return sum([ord(c)-ord('a')+1 for c in s])
