'''
https://www.codewars.com/kata/combine-objects/train/python

Your task is to write a function that takes two or more objects and returns a new object which combines all the input objects.

All input object properties will have only numeric values. Objects are combined together so that the values of matching keys are added together.

An example:


const objA = { a: 10, b: 20, c: 30 }

const objB = { a: 3, c: 6, d: 3 }

combine(objA, objB) // Returns { a: 13, b: 20, c: 36, d: 3 }
The combine function should be a good citizen, so should not mutate the input objects.
'''
def combine(d, *args):
    result = d.copy()
    for i in args:
        for k, v in i.iteritems():
            if result.has_key(k):
                result.update({k: result[k] + v})
            else:
                result.update({k: v})
    return result

if __name__ == '__main__':
    objA = { 'a': 10, 'b': 20, 'c': 30 }
    objB = { 'a': 3, 'c': 6, 'd': 3 }
    objC = { 'a': 5, 'd': 11, 'e': 8 }
    objD = { 'c': 3 }
    print(combine(objA, objB))
    print(combine(objA, objC))
