l = input().split(' ')
n = int(l[0])
m = int(l[1])
c = int(l[2])
mat = [[0 for _ in range(m)] for _ in range(n)]
for i in range(n):
    l = input()
    for j, a in enumerate(l):
        if a !='-':
            mat[i][j] = 1
            

def step(mat):
    new_mat =[[1 for _ in range(m)] for _ in range(n)]
    for i in range(n):
        for j in range(m):
            b = 0
            for x in [-1, 0, 1]:
                for y in [-1, 0, 1]:
                    if x == y and x == 0:
                        continue
                    if mat[(i+x)%n][(j+y)%m] ==1:
                        b += 1
            if mat[i][j] == 1:
                if b<2 or b > 3:
                    new_mat[i][j] = 0
            elif b==3:
                new_mat[i][j] = 1
            else:
                new_mat[i][j] = mat[i][j]
    return new_mat
            
co = 0
diff = -1
hist = []
items = {}
while co<c:
    h = hash(str(mat))
    if h in items:
        diff = items[h]
        break
    hist.append(mat)
    items[h] = co
    co += 1
    mat = step(mat)
if diff == -1:
    hist.append(mat)
    diff = co
def printall(mat_out):
    for x in mat_out:
        s = ''.join(['*' if y==1 else '-' for y in x ])
        print(s)
printall(hist[diff+ (c - diff)%(len(hist)-diff)])
    
