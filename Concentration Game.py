n = int(input())
a = [0]*n
for i in range(n):
    print('{0} {1}'.format(1+2*i, 2*i + 2), flush=True)
    x = input()
    if x == 'MATCH':
        continue
    if x == '-1':
        print (-1)
    x1, x2 = x.split()
    x1 = int(x1)-1
    x2 = int(x2)-1
    if a[x1] == 0:
        a[x1] = 2*i + 1
    else:
        print('{0} {1}'.format(a[x1], 2*i + 1), flush=True)
        input()
    if a[x2] == 0:
        a[x2] = 2*i+2
    else:
        print('{0} {1}'.format(a[x2], 2*i + 2), flush=True)
        input()
print (-1)