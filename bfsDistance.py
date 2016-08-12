from Queue import Queue
 
INF = 10**9 # 10^9

n, m = map(int, raw_input().split())
adj = []
dist = []
 
for i in xrange(n+1): 
	adj.append([])
	dist.append(INF)
 
def bfs(vertice):
 
	q = Queue()
 
	q.put(vertice)
	dist[vertice] = 0
 
	while not q.empty():
 
		vertice = q.get()
 
		print 'visitando %d' % vertice
 
		for vizinho in adj[vertice]:
			if dist[vizinho] > dist[vertice] + 1:
				dist[vizinho] = dist[vertice] + 1
				q.put(vizinho)
 
	print dist
