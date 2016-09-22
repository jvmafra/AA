while True:
	try:
		N = int(raw_input())
		custo = int(raw_input())
		max_atual = 0
		acum = 0
		atual = acum
		lista = []
		for i in range(1,N+1):
			valor = int(raw_input())
			acum += valor
			atual = valor - custo
			lista.append(atual)
			if (atual > max_atual):
				max_atual = atual
		
		
		print lista
			
	
	except EOFError:
		break
