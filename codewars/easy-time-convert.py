'''
https://www.codewars.com/kata/easy-time-convert

This challenge requires you to convert an integer. If the input is 78, then your program should output the string '01:18' because 78 minutes converts to 1 hour and 18 minutes. If the input is 0 or negative value, then your program should output the string '00:00'

We will use the modulo operation to solve this challenge. The modulo operation simply returns the remainder after a division, so for example, the remainder of 5 / 2 is 1, so the modulo of 5 / 2 is 1.

Good luck :D
'''
timeConvert = lambda n: "{:02d}:{:02d}".format(*divmod(max(int(n), 0), 60))

if __name__ == '__main__':
    print(timeConvert(51))
    print(timeConvert(123))
    print(timeConvert(63))
    print(timeConvert(1000))
