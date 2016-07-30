from math import sqrt


n = 1000000
mapa = [1]*(n+2)
mapa[1] = 0
mapa[0] = 0

for i in xrange(2, int(sqrt(n)) + 1):
	if (mapa[i] == 1):
		for j in xrange(i**2, n + 1, i):
			mapa[j] = 0


acumulada = [0] * (n+2)

soma = 0
for num in xrange(2, n + 1):
	if (mapa[num] == 1) and (mapa[num+2] == 1 or mapa[num-2] == 1):
		soma += 1
	
	acumulada[num] = soma
	

loop = int(raw_input())

for i in range(loop):
	par = map(int, raw_input().split())
	if (par[0] > par[1]):
		a = par[1]
		b = par[0]
	
	else:
		a = par[0]
		b = par[1]
	
	
	print acumulada[b] - acumulada[a-1]


