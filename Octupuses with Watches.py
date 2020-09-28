import numpy as np
l1 = input().split(' ')
n = int(l1[0])
m = int(l1[1])
arr = []
for i in range(n):
    arr.append([])
    row = input().split()
    for j in range(m):
        arr[i].append(int(row[j]))
best = 0
for i in range(3**n):
    choice = []
    arr_copy = [a.copy() for a in arr]
    temp =i
    for _ in range(n):
        choice.append(temp%3)
        temp = temp//3
    count = 0
    for j in range(n):
        for k in range(m):
            arr_copy[j][k] +=choice[j]
    for k in range(m):
        counts = [0, 0, 0]
        for j in range(n):
            counts[arr_copy[j][k]%3] += 1
        count += max(counts)
    if count > best:
        best = count
print(best)
    
    

