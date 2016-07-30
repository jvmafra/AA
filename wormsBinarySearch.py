def buscaBinaria(lista, elemento):
	inicio = 0
	fim = len(lista) - 1
	
	while (inicio <= fim):
		meio = (inicio + fim) / 2
		if elemento == lista[meio]:
			return meio
		
		elif (elemento < lista[meio] and meio == 0):
			return meio
		elif (elemento < lista[meio] and elemento > lista[meio-1]):
			return meio
			
		elif (elemento < lista[meio]):
			fim = meio - 1
		else:
			inicio = meio + 1
	
	
	return -1
	


N = int(raw_input())
entradas = map(int, raw_input().split())
juicys = int(raw_input())
m = map(int, raw_input().split())

vetor = [0]*N
acumulada = 0
for i in range(N):
	acumulada += entradas[i]
	vetor[i] = acumulada


for i in range(juicys):
	print buscaBinaria(vetor, m[i]) + 1
