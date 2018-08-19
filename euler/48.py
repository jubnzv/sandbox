# https://projecteuler.net/problem=48
# The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.
# Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.

# Returns array that contains the last N digits of num.
# If length of num < N, we'll fill missing values with zeros. 
def lnd(num, N):
    digs = [int(x) for x in str(num)]
    if len(digs) < N:
        return [0]*(N-len(digs)) + digs  
    else:
        return digs[-N:]

# Alias that returns list contains last 10 digits of number
def l10d(num):
    return lnd(num, 10)

# Last digits of (ds**n) operation 
# Returns result of operation ds**n where ds is list that contains digits, and n is natural number represents power
def powd(ds, n):
    dpow = ds
    for i in range(1, n):
        dpow =  prodd(dpow, ds)
    return dpow

# (*) operation for two lists of digis.
# Returns last 10 digits of product ds1 and ds2.
def prodd(ds1, ds2):
    S = [0]*10
    for i in reversed(range(len(ds2))):
        val = [ds2[i]*d1 for d1 in ds1]
        S = sumd(S, val[(-i-1):] + [0]*(len(ds2) - i))
    return S

# (+) operation for two lists of digits
def sumd(ds1, ds2):
    return sld([d1+d2 for d1, d2 in zip(ds1, ds2)])

# Shifts to left digits representation.
# For example, input list [13, 12, 3, 41, 9] should returns [4, 2, 7, 1 , 9]
def sld(ds=[]):
    if len(ds) == 1:
        return [ds[0] % 10]
    else:
        elm = ds[-1]%10
        eld = ds[-1]//10
        return sld(ds[:-2] + [ds[-2] + eld]) + [elm]    

if __name__ == '__main__':
    S = [0]*10;
    for n in range(1,1001):
        dn = l10d(n)
        S = sumd(S, powd(dn, n))

    print(S) # Answer: [9, 1, 1, 0, 8, 4, 6, 7, 0, 0]
        
