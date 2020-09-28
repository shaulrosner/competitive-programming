import random
n = int(input())
ans = ''
ans = ''
count = 1
for _ in range(n):
    curr = ['y' for _ in range(count)]
    ans += ''.join(curr)
    curr = ['Y' for _ in range(count)]
    ans += ''.join(curr)
    count += 1
    if len(ans) > n:
        break
print(ans[:n])