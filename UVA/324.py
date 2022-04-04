while True:
	n = int(input())
	if n == 0:
		break

	freq = {str(digit): 0 for digit in range(10)}
	number = 1
	for i in range(2, n + 1):
		number *= i

	for digit in str(number):
		freq[digit] += 1

	ans = "   "
	for digit in range(4):
		ans += f"({digit}) {freq[str(digit)]:4}    "
	ans += f"(4) {freq['4']:4}\n   "

	for digit in range(5, 9):
		ans += f"({digit}) {freq[str(digit)]:4}    "
	ans += f"(9) {freq['9']:4}"
	print(f'{n}! --')
	print(ans)

