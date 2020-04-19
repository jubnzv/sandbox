from functools import reduce

l1 = [1, 2, 3, 4]
l2 = [42, 3, 19, 2]
(reduce(lambda l, x: l + [x] if x not in l else l, l1, l2))
