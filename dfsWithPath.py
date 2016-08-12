## DFS :D!
 
# n = numero de vertices/nos
# m = numero de arestas
# vertices sao de 1 a n
n, m = map(int, raw_input().split())
 
# lista de adjacencia eh uma lista de listas
#adj = [[] for i in xrange(n)]
# a lista começa vazia porque nao temos arestas :(
adj = []
for i in xrange(n+1): adj.append([])
 
BLACK = 1 # ja foi visitado (e terminou!!!)
GRAY = 0 # to visitando, ta no meu caminhozinho
WHITE = -1 # nao visitei :(
 
vis = [WHITE] * (n+1)
 
def dfs(vertice):
 
	print 'Estou fazendo DFS no vertice %d :D!' % vertice
 
	vis[vertice] = GRAY
 
	for vizinho in adj[vertice]:
		if vis[vizinho] == WHITE:
			dfs(vizinho)
		elif vis[vizinho] == GRAY: print 'CICLO!'
	print 'Terminei a dfs :( de %d' % vertice
 
	vis[vertice] = BLACK
