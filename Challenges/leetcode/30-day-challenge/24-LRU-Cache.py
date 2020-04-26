# Design and implement a data structure for Least Recently Used (LRU) cache. It
# should support the following operations: get and put.
#
# get(key) - Get the value (will always be positive) of the key if the key
# exists in the cache, otherwise return -1.
# put(key, value) - Set or insert the value if the key is not already present.
# When the cache reached its capacity, it should invalidate the least recently
# used item before inserting a new item.
#
# The cache is initialized with a positive capacity.
#
# Follow up:
# Could you do both operations in O(1) time complexity?
#
# Example:
#
# LRUCache cache = new LRUCache( 2 /* capacity */ );
#
# cache.put(1, 1);
# cache.put(2, 2);
# cache.get(1);       // returns 1
# cache.put(3, 3);    // evicts key 2
# cache.get(2);       // returns -1 (not found)
# cache.put(4, 4);    // evicts key 1
# cache.get(1);       // returns -1 (not found)
# cache.get(3);       // returns 3
# cache.get(4);       // returns 4
from collections import OrderedDict


class LRUCache:

    def __init__(self, capacity: int):
        self.values = OrderedDict()
        self.remain = capacity

    def get(self, key: int) -> int:
        if key not in self.values:
            return -1
        val = self.values.pop(key)
        self.values[key] = val
        return val

    def put(self, key: int, value: int) -> None:
        if key in self.values:
            self.values.pop(key)
        else:
            if self.remain > 0:
                self.remain -= 1
            else:
                self.values.popitem(last=False)
        self.values[key] = value


if __name__ == '__main__':
    cache = LRUCache(2)
    cache.put(1, 1)
    cache.put(2, 2)
    print(cache.get(1))
    cache.put(3, 3)
    print(cache.get(2))
    cache.put(4, 4)
    print(cache.get(1))
    print(cache.get(3))
    print(cache.get(4))
