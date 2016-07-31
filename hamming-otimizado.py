a = raw_input()
b = raw_input()
diferenca = len(b) - len(a)

matrix = [[0]*2 for i in range(len(b) + 1)]


matrix[0][0] = 0
matrix[0][1] = 0

num0s = 0
num1s = 0

for i in range(len(b)):
	if (b[i] == "0"):
		num0s += 1
	else:
		num1s += 1
	
	matrix[i+1][0] = num0s
	matrix[i+1][1] = num1s

soma = 0
for i in range(len(a)):
	for c in range(2):
		soma += abs((int(a[i]) - c)) * (matrix[diferenca + i + 1][c] - matrix[i][c])


print soma
	
	
