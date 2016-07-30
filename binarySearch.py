def buscaBinaria(lista, elemento):
	inicio = 0
	fim = len(lista) - 1
	while (inicio <= fim):
		meio = (inicio + fim) / 2
		if (lista[meio] == elemento):
			while (meio - 1 >= 0 and lista[meio - 1] == elemento):
				meio -= 1
			return meio
		elif (elemento < lista[meio]):
			fim = meio - 1
		else:
			inicio = meio + 1
	
	
	return -1


n = 1
while True:
	entrada = map(int, raw_input().split())
	if (entrada[0] == 0 and entrada[1] == 0):
		break
	
	print "CASE# %d:" % (n)
	n += 1 
	
	
	total = entrada[0]
	consultas = entrada[1]
	
	lista = []
	for i in range(total):
		num = int(raw_input())
		lista.append(num)
	
	lista.sort()
	
	for j in range(consultas):
		consultado = int(raw_input())
		indice = buscaBinaria(lista, consultado)
		
		if (indice == -1):
			print "%d not found" % (consultado)
		else:
			print "%d found at %d" % (consultado, indice + 1)
