'''
https://www.codewars.com/kata/find-out-whether-the-shape-is-a-cube

To find the volume (centimeters cubed) of a cuboid you use the formula;

```volume = Length * Width * Height```
    
But someone forgot to use proper record keeping, so we only have the volume, and a length of a single side!

It's up to you to find out whether the cuboid has equal sides.

Return `true` for it having equal sides, return `false` for otherwise.

Return `false` for invalid numbers too. 
E.g volume is less than or equal to 0;
'''
cube_checker_1 = lambda v,a:  True if (a**3 == v) and a > 0 and v > 0  else False
cube_checker = lambda v,a:  (a**3 == v) and a > 0 and v > 0

if __name__ == '__main__':
    print(cube_checker(-12,2))
    print(cube_checker(8,3))
    print(cube_checker(8,2))
