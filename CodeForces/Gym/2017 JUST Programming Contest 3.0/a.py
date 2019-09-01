n = int(raw_input())
 
for k in xrange(n):
	y, x = map(int, raw_input().split())
	print int(y*100/(100 +  x))
