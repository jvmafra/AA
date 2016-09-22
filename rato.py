from Queue import Queue

dist = {}
adj = {}
INF = 1000000;

def zeraDists():
	for vertice in adj.keys():
		dist[vertice] = INF

def bfs(origem, destino):
	fila = Queue()
	fila.put(origem)
	dist[origem] = 0
	
	while not fila.empty():
 
		vertice = fila.get()
 
		for vizinho in adj[vertice]:
			if dist[vizinho] > dist[vertice] + 1:
				dist[vizinho] = dist[vertice] + 1
				fila.put(vizinho)
 
	
	return dist[destino]


n, m = map(int, raw_input().split())

for i in range(m):
	u, v = map(str, raw_input().split())
	if u not in adj:
		adj[u] = []
	if v not in adj:
		adj[v] = []
	adj[u].append(v)
	adj[v].append(u)

zeraDists()
dist1 = bfs("Entrada", "*");
zeraDists()
dist2 = bfs("*", "Saida");

print dist1 + dist2










