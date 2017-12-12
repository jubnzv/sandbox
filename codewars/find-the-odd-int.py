'''
https://www.codewars.com/kata/find-the-odd-int

Given an array, find the int that appears an odd number of times.

There will always be only one integer that appears an odd number of times.

'''
find_it = lambda s: (i for i in s if s.count(i) % 2 != 0).next()

if __name__ == '__main__':
    print(find_it([20,1,-1,2,-2,3,3,5,5,1,2,4,20,4,-1,-2,5]))
