def bfs(no):
	aux = [no]
	fila = [no]
	lista[no] = True
	while (len(fila) > 0):
		atual = fila.pop(0)
		for vis in adj[atual]:
			if (lista[vis] == False):
				fila.append(vis)
				aux.append(vis)
				lista[vis] = True
		
	print aux
