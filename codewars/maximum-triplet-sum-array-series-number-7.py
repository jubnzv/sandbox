#  https://www.codewars.com/kata/maximum-triplet-sum-array-series-number-7
#
#  We are Given an array [] of n integers,
#
#  We Need To Find Maximum Triplet Sum In The Array Without duplication .
#  Notes
#  1- Vector Size is at least 3 .
#  2- The Vector's Numbers could be a mixture of Positives and Negatives also Zeros .
#  3- Repeatition of Numbers in the Vector Could Occur ,
#  So (Duplications Is NOT Included When Summing).
#
#  If Any Of The Previous Points (Notes) Is Not Clear , Pay Attention To The Examples Clarify Everything .
#  Input , Output Examples
#  1- maxTriSum ({3,2,6,8,2,3}) // return (17)
#
#  Explanation ::
#  As The Triplet that Maximize THe Sum {6,8,3} In Order , Note : "Duplications Is NOT Included When Summing" , (i.e) The Number added Only Once .
#  2- maxTriSum ({2,1,8,0,6,4,8,6,2,4}) // return (18)
#
#  Explanation ::
#  As The Triplet that Maximize THe Sum {8,6,4} In Order , Note : "Duplications Is NOT Included When Summing" , (i.e) The Number added Only Once .
#  3- maxTriSum ({-7,12,-7,29,-5,0,-7,0,0,29}) // return (41)
#
#  Explanation ::
#  As The Triplet that Maximize THe Sum WITHOUT DUPLICATIONS {12,29,0} .

def max_tri_sum(nums): return sum(sorted(set(nums))[-3:])
