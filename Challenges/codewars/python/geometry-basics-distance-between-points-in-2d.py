'''
https://www.codewars.com/kata/geometry-basics-distance-between-points-in-2d

This series of katas will introduce you to basics of doing geometry with computers.

`Point` objects have `x` and `y` attributes.

Write a function calculating distance between `Point a` and `Point b`.

Tests round answers to 6 decimal places.
'''
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

distance_between_points_1 = lambda a,b: round(((a.x-b.x)**2 + (a.y-b.y)**2)**0.5, 6)

import math
distance_between_points = lambda a,b: math.hypot(a.x-b.x, a.y-b.y)

if __name__ == '__main__':
    print(distance_between_points(Point(3,3), Point(3,3)))
    print(distance_between_points(Point(1,6), Point(4,2)))
