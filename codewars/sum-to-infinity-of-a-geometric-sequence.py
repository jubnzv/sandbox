'''
https://www.codewars.com/kata/sum-to-infinity-of-a-geometric-sequence

Hello everyone.

I have a simple challenge for you today. In mathematics, the formula for finding the sum to infinity of a geometric sequence is: 

<img src="http://d2fhka9tf2vaj2.cloudfront.net/tuts/122_physics/tutorial/sum-geometric-series.jpg" alt="Sum to infinity of a geometric sequence">

**ONLY IF** `-1 < r < 1`

where:

* `a` is the first term of the sequence
* `r` is the common ratio of the sequence (calculated by dividing one term in the sequence by the previous term)

For example: `1 + 0.5 + 0.25 + 0.125 + ... = 2`

Your challenge is to calculate the sum to infinity of the given sequence. The solution must be rounded to 3 decimal places.

If there are no solutions, for example if `r` is out of the above boundaries, return `"No Solutions"`.

Hope you enjoy, let me know of any issues or improvements!
'''
def sum_to_infinity(sequence):
    if len(sequence) == 1:
        return sequence[0]
    else:
        r = sequence[1] / sequence[0]
        print(r)
        if not -1 < r < 1:
            return 'No Solutions'
        else:
            return round(sequence[0]/(1 - r), 3)
