'''
https://www.codewars.com/kata/posix-command/train/python

As you see in Example test cases, the os running this service is posix.

Return the output by executing the command given as the string on posix os.

See the example test cases for the expected data format.
'''
from subprocess import check_output

def get_output(s): return check_output(s.split(' ')).decode('utf-8')

if __name__ == '__main__':
    print(get_output('ls -l'))
