from math import sqrt

rodadas = int(raw_input())

for i in range(rodadas):
	par = map(int, raw_input().split())
	a = par[0]
	b = par[1]
	
	diferenca = a - b
	
	aux = a
	N = 1
	while (diferenca > 0):
		N *= aux
		aux -= 1
		diferenca -= 1
	
	
	resto = N
	divisor = 2
	cont = 0
	
	while (resto >= 0 and divisor <= int(sqrt(N))):
		if (resto % divisor == 0):
			cont += 1
			resto = resto/divisor
		else:
			divisor += 1
	
	if (resto > 1):
		cont += 1 
	
	print cont 
	
	
	
	
	
	
	
		
		
