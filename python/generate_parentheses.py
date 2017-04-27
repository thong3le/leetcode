def gen(n, open=0):
    if n > 0 and open >= 0:
        return ['(' + p for p in gen(n-1, open+1)] + [')' + p for p in gen(n, open-1)]
    return [')' * open] * (not n)

print gen(input())