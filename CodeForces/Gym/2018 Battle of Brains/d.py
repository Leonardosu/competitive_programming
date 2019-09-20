n = int(raw_input())
 
for k in xrange(n):
	x = raw_input()
	print "Case %d: %s" % ( (k+1), (x  + (x[0:len(x)-1])[::-1]))