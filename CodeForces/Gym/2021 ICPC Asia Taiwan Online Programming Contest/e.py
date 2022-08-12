def sumFirstN(n):
	return (n**2) *((2*(n**4) + 6*(n**3) + 5*(n**2) - 1) )// 12

def profitNDays(days, p, q, initial):
	return x + q * sumFirstN(days) - p * days

p, q = input().split()
p = int(p)
q = int(q)

# print(p + q)
x = 0
day = 1
while True:
	x += p
	changes = q*day**5
	if p <= changes:
		break
	x -= changes
	day += 1

target = 10 ** 99
l = 0
r = 10 ** 99
while l <= r:
	mid = (l+r)//2
	if profitNDays(mid, p, q, x) >= target:
		r = mid - 1
		y = mid
	else:
		l = mid + 1
print(x)
print(y)