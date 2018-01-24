'''
https://www.codewars.com/kata/minimize-sum-of-array-array-series-number-1/train/python

We are given an array of even size.

Our task is to find the minimum sum which is obtained from summing each Two integers product .
Input :: Output Examples ::

minSum({5,4,2,3}) // return 22

Explanation ::
5*2 +3*4 = 22

minSum({12,6,10,26,3,24}) // return 342

Explanation ::
26*3 + 24*6 + 12*10 = 342

minSum({9,2,8,7,5,4,0,6}) // return 74

Explanation ::
9*0 + 8*2 +7*4 +6*5 = 74
Note :

1- Natural numbers only passed to the vector (No  Negatives) .
Hope you enjoy it .. Awaiting for crafting best Practice and Clever Codes ..

If you feel Enjoyed this Kata , Then How About (Monkey With) Numbers in this Series ::

Balanced Number

STRNOGN - Strong Number

Disarium Number

Jumping Number

Special Number

Enjoy Learning !!!

Wish you all the Best .. Regards

Zizou
'''
def min_sum(l):
    s = 0
    while l:
        lmin, lmax = min(l), max(l)
        s += lmin * lmax
        l.remove(lmin)
        l.remove(lmax)
    return s
