def calc(i ,j , n):
    if n<0:
        return 0
    if save[n][i] != -1:
        return save[n][i]
    if i==j:
        if n == 1:
            return 25
        elif n==0:
            return 1
        else:
            return 0
    if i+1 == j:
        if s[i] == s[j]:
            if n==0:
                return 1
            elif n==2:
                return 25
            else:
                return 0
        if n==1:#s[i] != s[j]
            return 2
        elif n == 2:
            return 24
        else:
            return 0
    if s[i] == s[j]:
        res = ((calc(i+1, j-1, n))%mod + (25*calc(i+1, j-1, n-2)) % mod)% mod
    else:
        res =  ((2*calc(i+1, j-1, n-1))%mod + (24*calc(i+1, j-1, n-2))% mod)% mod
    save[n][i] = res
    return res
    
t = int(input())
for _ in range(t):
    line = input().split()
    save = [[-1 for i in range(300)] for j in range(500)]
    n = int(line[0])
    s = line[1]
    l = len(s)
    mod = 10**9 + 7
    print(calc(0, len(s)-1, n)%mod)
    
    

    