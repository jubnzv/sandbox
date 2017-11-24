'''
https://www.codewars.com/kata/ip-validation

Write an algorithm that will identify valid IPv4 addresses in dot-decimal format. IPs should be considered valid if they consist of four octets, with values between `0..255` (included).

Input to the function is guaranteed to be a single string.

### Examples

```js
// valid inputs:
1.2.3.4
123.45.67.89

// invalid inputs:
1.2.3
1.2.3.4.5
123.456.78.90
123.045.067.089
```

**Note:** leading zeros (e.g. `01.02.03.04`) are considered ***not valid*** in this kata!
'''
import re

def is_valid_IP(s):
    print s
    ip_digit = r'([1-9]|([1-9][0-9])|(1[0-9][0-9])|(2[0-4][0-9])|(25[0-5]))'
    pattern = re.compile(r'^{0}\.{0}\.{0}\.{0}$'.format(ip_digit))
    return pattern.match(s) is not None

if __name__ == '__main__':
    print(is_valid_IP('12.255.56.1'))
    print(is_valid_IP('abc.def.ghj.ghs'))
    print(is_valid_IP('219.72.123.136'))
    print(is_valid_IP('256.1.2.3'))
    print(is_valid_IP('17.149.125.252'))
    print(is_valid_IP('1.2.3'))
    print(is_valid_IP('1.2.3.4'))
    print(is_valid_IP('209.82.34.22'))
