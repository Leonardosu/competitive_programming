n = int(raw_input())
 
for k in xrange(n):
	x = int(raw_input())
	if x % 4 == 0:
		print x/2, x/2/2, x/2/2
	elif x % 3 == 0:
		print x/3, x/3, x/3
 
	else:
		print "IMPOSSIBLE"