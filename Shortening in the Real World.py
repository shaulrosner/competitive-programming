burl = input()
butf = [ord(c) for c in burl]
letters = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'
l = len(burl)
n = int(input())
for _ in range(n):
    curl = input()
    txt = ''
    for i in range(8):
        x = ord(curl[-8 + i]) ^ butf[(len(curl) - 8+ i) % l]
        txt += hex(x)[2:].zfill(2)
    num = int('0x' + txt, 0)
    ans = ''
    while (num >0):
        ans += letters[num%62]
        num = num //62
    print(burl + '/'+ans[::-1])
    