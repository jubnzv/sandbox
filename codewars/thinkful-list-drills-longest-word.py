#!/usr/bin/python3
# https://www.codewars.com/kata/thinkful-list-drills-longest-word

# Write a function longest() that takes one argument, a list of words, and returns the length of the longest word in the list.
def longest(words): return len(max(words, key=len))
