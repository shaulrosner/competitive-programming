from math import inf
from sys import stdin, exit
def val(topics):
    res = 0
    for topic in topics:
        res += 2**a[topic]
    return res
a = {}
books = []
c = 0
b = 0
for l in stdin:
    if l =='':
        break
    l = l.split()
    b += 1
    t = int(l[0])
    topics = l[1:]
    names = []
    if len(a) < 20:
        for topic in topics:
            if topic not in a:
                a[topic] = c
                c += 1
    books.append((t, val(topics)))
tl = 2**len(a)
arr = [inf for _ in range(tl)]
arr[0] = 0
for i in range(1, len(books)+1):
    book = books[i-1]
    arr[book[1]] = min(arr[book[1]], book[0])
    #arr1 = arr.copy()
    for j in range(len(arr)):
        v = book[1] |j
        arr[v] = min(arr[v], arr[j] + book[0])
    #arr = arr1
    #print(arr)
    
print(arr[(tl)-1])


            
    
            
    
        
    