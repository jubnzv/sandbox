'''
https://www.codewars.com/kata/stop-the-loop-after-n-seconds

Sam wants to know how many times the variable `i` gets incremented after `n` seconds,
but he has no idea how to stop the loop.

Help him so that the function can return `i` after `n` seconds. 

```
0 <= n <= 3

(Artifacts for the delay is allowed up to 0.5 seconds)
```

NB: The value `i` is not so important in this kata 
because it is dependent on the state of server in practice.

But if `n==0`, the expected value for `i` is `0`.
'''
import time

def increment_loop(n):
    if n == 0:
        return 0
    i=0
    start = time.time()
    while True:
        if (time.time() - start) > n:
            break
        i+=1
    return i

if __name__ == '__main__':
    print(increment_loop(5))
