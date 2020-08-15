'''
https://www.codewars.com/kata/real-password-cracker

## Story

You are a h4ck3r n00b: you "acquired" a bunch of password hashes, and you want to decypher them. Based on the length, you already guessed that they must be SHA-1 hashes. You also know that these are weak passwords: maximum 5 characters long and use only lowercase letters (`a-z`).

Happy hacking!

*Note on performance:* pre-generating the full hash table is not advised, due to the limitations of the CW platform

---

## My other katas

If you enjoyed this kata, then please try my other katas:

| Title | Difficulty | Languages
|-|-|-
| [Isogram Cipher](https://www.codewars.com/kata/isogram-cipher/) | beta, ~6 kyu | python
| [Count the Domain Names](https://www.codewars.com/kata/count-the-domain-names/) | 5 kyu | python
| [SMS Lottery Bet Validator](https://www.codewars.com/kata/sms-lottery-bet-validator/) | 6 kyu| python, C#, JS
| [Sinus Scroller](https://www.codewars.com/kata/sinus-scroller/) | 6 kyu | python

Your ranking, rating, feedback and translation is greatly appreciated. Thanks!
'''
from datetime import datetime

import hashlib
from string import ascii_lowercase
from itertools import imap, product

def cracker(f):
    d = [{hashlib.sha1(w).hexdigest(): w for w in map(''.join, product(ascii_lowercase, repeat=i))} for i in xrange(1, 6)]

    def sha_cracker(sha):
        return filter(None, [i.get(sha) for i in d])[0]

    return sha_cracker

@cracker
def password_cracker(sha):
    pass

if __name__ == '__main__':
    start_time = datetime.now()
    print(password_cracker('27d5482eebd075de44389774fce28c69f45c8a75'))  # 'h'
    print("Execution time: {} s".format(datetime.now()-start_time))

    start_time = datetime.now()
    print(password_cracker('e6fb06210fafc02fd7479ddbed2d042cc3a5155e'))  # 'code'
    print("Execution time: {} s".format(datetime.now()-start_time))

    start_time = datetime.now()
    print(password_cracker('a94a8fe5ccb19ba61c4c0873d391e987982fbbd3'))  # 'test'
    print("Execution time: {} s".format(datetime.now()-start_time))

    start_time = datetime.now()
    print(password_cracker('bf3f6e65daa76dde92612355478885eb52473854'))  # 'fooba'
    print("Execution time: {} s".format(datetime.now()-start_time))

    start_time = datetime.now()
    print(password_cracker('da39a3ee5e6b4b0d3255bfef95601890afd80709'))  # 'fooba'
    print("Execution time: {} s".format(datetime.now()-start_time))
