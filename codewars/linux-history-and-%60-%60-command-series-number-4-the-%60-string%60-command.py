'''
https://www.codewars.com/kata/linux-history-and-%60-%60-command-series-number-4-the-%60-string%60-command

All Unix user know the command line `history`. This one comes with a set of useful commands know as the `bang` command. 

For more information about the history command line you can take a look at: 

- The man page -> simply type `man history` in your terminal.
- The online man page [here](https://linux.die.net/man/3/history).
- And for more information about the `bang` command you can read [this article](http://jaysoo.ca/2009/09/16/unix-history-and-bang-commands/)

For this 4th kata we will explore the `!string` command, according to the man page this one refer to command the most recent command preceding the current position in the history list starting with string.

In this kata you should complete a function that take in an string that correspond to `s`, and an `history` with the following format: 

```
  1  cd /pub
  2  more beer
  3  lost
  4  ls 
  5  touch me 
  6  chmod 000 me 
  7  more me
  8  history
```

and that should return the most recent command line that start with `s`, for example with `s`="more" and the above history it should return `more me`. If user ask for a `s` without any know entry for example `n=mkdir` here, the function should return `!mkdir: event not found`.

**Note**: Lot of the command line comes form some geeky t-shirt and form this [excellent page](http://langevin.univ-tln.fr/cours/UPS/extra/unix-qshell-jokes.txt).



'''
import re

def bang_start_string(cmd, history):
    pattern = re.compile(r'^\ *\d+\ {{2}}{}.*'.format(cmd), re.M)
    found = re.findall(pattern, history)
    print found
    return found[-1].split('  ')[-1] if found else "!{}: event not found".format(cmd)


if __name__ == '__main__':
    history="   1  cd /pub\n  2  more beer\n  3  lost\n  4  ls\n  5  touch me\n  6  chmod 000 me \n  7  more me\n  8  history"
    print(bang_start_string("more", history))
    history="   1  cd /pub\n  1  cd /234\n  2  more beer\n  4  cd ..\n  3  lost\n  4  ls\n  5  touch me\n  6  chmod 000 me \n  7  history\n  8  more me"
    print(bang_start_string("more", history))
    print(bang_start_string("cd /234", history))
    print(bang_start_string("touch", history))
    print(bang_start_string("mkdir", history))
