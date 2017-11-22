'''
https://www.codewars.com/kata/linux-history-and-%60-%60-command-series-number-3-the-%60-n%60-command

All Unix user know the command line `history`. This one comes with a set of useful commands know as the `bang` command. 

For more information about the history command line you can take a look at: 

- The man page -> simply type `man history` in your terminal.
- The online man page [here](https://linux.die.net/man/3/history).
- And for more information about the `bang` command you can read [this article](http://jaysoo.ca/2009/09/16/unix-history-and-bang-commands/)

For this third kata we will explore the `!-n` command, according to the man page this one refer to command line -n.

In this kata you should complete a function that take in an integer that correspond to `n`, and an `history` with the following format: 

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

and that should return the `n`th executed command line, for example with `n`=4 and the above history it should return `touch me`. If user ask for a `n` without any know entry for exampl `n=12` here, the function should return `!12: event not found`.

**Note**: Lot of the command line comes form some geeky t-shirt and form this [excellent page](http://langevin.univ-tln.fr/cours/UPS/extra/unix-qshell-jokes.txt).



'''
def bang_minus_n(n, history):
    lines = history.split('\n')
    if n > len(lines):
        return "!-{}: event not found".format(n)
    else:
        return lines[len(lines)-n].split('  ')[-1]

if __name__ == '__main__':
    history="   1  cd /pub\n  2  more beer\n  3  lost\n  4  ls\n  5  touch me\n  6  chmod 000 me \n  7  more me\n  8  history"
    print(bang_minus_n(4, history))
    history="   1  cd /pub\n  2  more beer\n  3  lost\n  4  ls\n  5  touch me\n  6  chmod 000 me \n  7  history\n  8  more me"
    print(bang_minus_n(2, history))
    print(bang_minus_n(12, history))
