
N = int(raw_input())
objetos = map(int, raw_input().split())
caminhos = map(int, raw_input().split())
 
vizinhos = [0] * (N+1)

for i in xrange(N):
	if caminhos[i] == 0: caminhos[i] = -1
	
for i in xrange(N): 
	if caminhos[i] != -1: vizinhos[caminhos[i]] += 1
		
 
visitados = [-1] * N
maior_caminho = 0
ultimo_vertice = 0
for i in xrange(N):
	
	if objetos[i] == 1:
		hotel = i
		cont = 1
		vertice_atual = hotel
		#enquanto for um vertice valido
		while ((caminhos[vertice_atual] > -1) and (vizinhos[caminhos[vertice_atual]] < 2) and (visitados[caminhos[vertice_atual] - 1]) != hotel):
			
			cont += 1
			visitados[vertice_atual] = hotel
			vertice_atual = caminhos[vertice_atual]-1
			
 
 
		if (cont > maior_caminho):
			maior_caminho = cont
			ultimo_vertice = hotel
			
 


percorrido = []

for i in xrange(maior_caminho):
	percorrido.append(ultimo_vertice + 1)
	ultimo_vertice = caminhos[ultimo_vertice] - 1

print maior_caminho


for elemento in percorrido[::-1]: print elemento,
