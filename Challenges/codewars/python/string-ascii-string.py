#!/usr/bin/python3
# https://www.codewars.com/kata/string-ascii-string
# You are given a string. Your job is to convert that string to upper case , then find the sum o each character converted to its ASCII value , then divide the sum by the string's length and then convert that to its equivalent character in ASCII.
# Twist : Do it in less than 55 characters.
# Examples :
# test.assert_equals(solution('abc') , 'B')
# test.assert_equals(solution('asd') , 'H')
# test.assert_equals(solution('iamareallyreallylongstringthatiscompletelyworthlessandisheretostophardcoders') , 'L')
solution=lambda s:chr(sum(map(ord,s.upper()))//len(s))
