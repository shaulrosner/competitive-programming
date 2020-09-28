from math import floor
n = int(input())
for i in range(n):
    s,m,r,b = [int(x) for x in input().split(' ')]
    types = sorted([m,r,b])
    if types[2] > types[1] + types[0]:
        result = types[1] + types[0]
    else:
        result = floor(sum(types)/2)
    print(min(s, result))