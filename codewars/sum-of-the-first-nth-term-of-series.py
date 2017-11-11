# Your task is to write a function which returns the sum of following series upto nth term(parameter).
# Series: 1 + 1/4 + 1/7 + 1/10 + 1/13 + 1/16 +...
#
# Rules:
# You need to round the answer to 2 decimal places and return it as String.
# If the given value is 0 then it should return 0.00
# You will only be given Natural Numbers as arguments.
def series_sum(n):
    return "{:.2f}".format(sum([1/(1+(3*el)) for el in range(n)]))


if __name__ == '__main__':
    print(series_sum(1))
    print(series_sum(2))
    print(series_sum(3))
    print(series_sum(4))
    print(series_sum(5))
    print(series_sum(6))
    print(series_sum(15))
