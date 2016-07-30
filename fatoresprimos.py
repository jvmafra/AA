from math import sqrt

def fatoraNumero(N):
	resto = N
	divisor = 2
	maior = 1
	novo = True
	while resto >= 0 and divisor <= int(sqrt(N)):
		if (resto % divisor == 0):
			if novo:
				maior *= divisor
				novo = False
			
			resto = resto / divisor
		else:
			divisor += 1
			novo = True
			
	if (resto > 1):
		maior *= resto
		
	return maior


N = int(raw_input())

print fatoraNumero(N)
		
