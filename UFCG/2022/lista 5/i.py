l = input().split()
n,m,k = l

ans = 0
n = int(n)
m = int(m)
k = int(k)
mod = 1000000007
if k == -1 and ((n%2==0) ^ (m%2==0)):
	ans = 0
else:
	ans = pow(2, (n-1)*(m-1), mod)
print(ans)
# print(n, m, k)