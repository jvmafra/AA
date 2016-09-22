
while True:
	pilha = [0 for x in range(100005)]
	top = -1

	N, D = map(int, raw_input().split())
	if (N == 0 and D == 0):
		break
		
	backupD = D

	lista = map(int, list(raw_input()))
	
	for i in range(len(lista)):
		atual = lista[i]
		while (top > -1 and pilha[top] < lista[i] and D > 0):
			top -= 1
			D -= 1
		
		top += 1
		pilha[top] = atual
	
	resp = ""
	for i in range(N-backupD):
		resp += str(pilha[i])
		
	
	print resp 
	
	
	
