import math


def calc(n):
    if (n == 0):
        return 0
    n = int(n)
    d = math.floor(math.log10(n)) + 1
    return int((d*n) + 1 - ((10**d) - 1)//9)


K = int(input())

L, R = [int(x) for x in input().split()]

K = min(K, R - L + 1)

l = 1
r = 1000000000000000000
ans = 1000000000000000000

while (l <= r):
    m = (l + r) // 2

    pos = calc(m)

    if (pos >= L):
        ans = m
        r = m - 1
    else:
        l = m + 1

ans -= 1

curr = ans
ini = calc(ans)

ss = str(curr)[L - ini:]

curr += 1

while True:
    ss += str(curr)
    curr += 1

    if (len(ss) > R - L + 1):
        break

ss = ss[:R - L + 1]

best = 0

for i in range(K, len(ss) + 1):
    best = max(best, int(ss[i - K: i]))

if (len(ss) <= K):
    print(max(best, int(ss)))
else:
    print(best)
