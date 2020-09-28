n = int(input())
text = input().strip().split(' ')
ps = [int(p) for p in text]
q = int(input())
allf = 0xFFFFFFFFFFFFFFFF
for _ in range(q):
    s = True
    g = int(input())
    newg = g
    for p in ps:
        if (p & allf)|(g &  allf) == g:
            newg = ((newg) & allf)&((~p) & allf)
    if s:
        if newg==0:
            print("YES")
        else:
            print("NO")