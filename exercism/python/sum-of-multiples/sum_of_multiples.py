def sum_of_multiples(limit, multiples):
    res = set()
    for m in multiples:
        res.update(set(range(0, limit, m)))
    return sum(res)
