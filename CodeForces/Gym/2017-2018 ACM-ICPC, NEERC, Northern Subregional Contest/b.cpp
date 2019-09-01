import sys
 
sys.stdout = open('boolean.out', 'w')
sys.stdin = open('boolean.in', 'r')
 
ar = raw_input().split("|")
dici = {}
 
tartaruga = False
 
for k in ar:
	if len(k) == 2:
		if k[-1] in dici:
			tartaruga = True
		else:
			dici[k] = True
	else:
		if ("~" + k) in dici:
			tartaruga = True
		else:
			dici[k] = True
 
if tartaruga:
	print pow(2, len(dici))
else:
	print pow(2, len(dici)) - 1