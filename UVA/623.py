N = 1001
facto = [1]*N
for i in range(2, N):
	facto[i] = facto[i-1] * i

while True:
	try:
		n = int(input())
		print(f'{n}!')
		print(facto[n])
	except EOFError:
		break
