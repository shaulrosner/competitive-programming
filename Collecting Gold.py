from math import inf
import heapq
primes = [2, 3, 5, 7, 11, 13 ,17 ,19, 23, 29, 31, 37, 41, 43, 47, 53]
def val(key):
    res = 1
    for i in range(17):
        res = res*primes[i]
        if res>key:
            return i

l = input().split()
n = int(l[0])
m = int(l[1])

adj = [[] for _ in range(n)]
mapping = []
values = []
keys = {}
for i in range(n):
    mapping.append(int(input()))
    values.append(val(mapping[i]))
    keys[mapping[i]] = i

for i in range(m):
    l = input().split()
    x = int(l[0])
    y = int(l[1])
    d = int(l[2])
    adj[keys[x]].append((keys[y], d))
    adj[keys[y]].append((keys[x], d))
distance = [inf for _ in range(n)]
processed = [False for _ in range(n)]
distance[keys[min(mapping)]] = 0
q = []
heapq.heappush(q, (0, -values[keys[min(mapping)]], keys[min(mapping)]))
while len(q)>0:
    p = heapq.heappop(q)
    c = p[1]
    a = p[2]
    if processed[a]:
        continue
    if a == keys[max(mapping)]:
        print (-c)
        break
    processed[a] = True;
    for u in adj[a]:
        b, w = u
        if distance[a] + w < distance[b]:
            distance[b] = distance[a] + w
            heapq.heappush(q, (distance[b], c - values[b], b))