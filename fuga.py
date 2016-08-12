LIVRE = "."
SAIDA = "E"
FOGO = "F"
INICIO = "S"
PAREDE = "#"

var = [(-1,0), (1,0), (0,1), (0, -1)]

def isValido(x,y):
	if ((x >= 0 or x < M) and (y >= 0 or y < M)):
		return True
	else:
		return False

def getFogos():
	aux = []
	for i in range(N):
		for j in range(M):
			if (adj[i][j] == -1 or adj[i][j] == FOGO):
				aux.append((i,j))
	
	return aux

def dfs(x,y):
	fogos = getFogos()
	for i in range(len(fogos)):
		x = fogos[i][0]
		y = fogos[i][1]
		for j in range(4):
			if (isValido(x + var[j][0], y + var[j][1])):
				adj[x + var[j][0]][y + var[j][1]] = -1
	
	
	print adj
				
			

consultas = int(raw_input())

for i in range(consultas):
	N, M = map(int, raw_input().split())
	adj = [["." for x in range(M)] for y in range(N)]
	for i in range(N):
		linha = raw_input().split()
		for j in range(len(linha)):
			adj[i] = linha[j]
	
	
	for i in range(N):
		for j in range(M):
			if (adj[i][j] == INICIO):
				dfs(i,j)
		
	
	
