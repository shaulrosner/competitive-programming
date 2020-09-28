import sys


length = int(input())
answer = [None] * length

def query_(arr):
    print("Q " + " ".join(str(x) for x in arr))
    sys.stdout.flush()
    return int(input())

def query(i):
    return query_([1] * i + [0] * (length-i))


sys.stdout.flush()
zeros = query(0)
last_res = zeros
i = 1
while i <= length:
    res = query(i)
    answer[i-1] = int(res > last_res)
    last_res = res
    i += 1

# answer
print("A " + " ".join(str(s) for s in answer))
sys.stdout.flush()