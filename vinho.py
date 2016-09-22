
while True:
	N = int(raw_input())
	if (N == 0):
		break
	
	lista = map(int, raw_input().split())
	
	cont = 0
	aux = 0
	
	for i in range(len(lista)):
		aux += lista[i]
		cont += abs(aux)
	
	print cont
					
						
					
