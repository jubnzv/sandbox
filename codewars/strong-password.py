'''
https://www.codewars.com/kata/strong-password

Your users passwords were all stole in the Yahoo! hack, and it turns out they have been lax in creating secure passwords.  Create a function that checks their new password (passed as a string) to make sure it meets the following requirements:


Between 8 - 20 characters

Contains only the following characters: (and at least one character from each category): uppercase letters, lowercase letters, digits, and the special characters !@#$%^&*?




Return "valid" if passed or else "not valid"
'''
import re
def check_password(s):
    checks = [r'[a-z]', r'[A-Z]', r'\d', r'[!@#$%^&*?]']
    return 'valid' if all([re.search(p, s) for p in checks]) \
                   and not re.search(r'[^a-zA-Z\d!@#$%^&*?]', s) \
                   and 8 <= len(s) < 20 else 'not valid'

if __name__ == '__main__':
    print(check_password('1231232'))
    print(check_password('sdfsfds123123'))
    print(check_password('SDDSF#D#@$#@'))
    print(check_password('sS#2?'))
    print(check_password('2090jsdfSDSD#2?'))
