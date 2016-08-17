n = int(raw_input())
adj = []
vis = []
 
for i in xrange(n+1): 
	adj.append([])
	vis.append(0)
 
def isLeaf(vertice):
	if len(adj[vertice]) == 1 and vertice != 0:
		return True
	else:
		return False
 
def dfs(no, prob = 0):
	vis[no[0]] = 1
 
	if (no[1] == 2):
			prob += 1
 
	if (isLeaf(no[0])):
		if (prob > 0):
			aux.append(no[0])
 
	for viz in adj[no[0]]:
		if (vis[viz[0]] == 0):
			dfs(viz, prob)
 
 
aux = []
 
for i in xrange(n-1):
	u, v, z = map(int, raw_input().split())
	lista1 = (v, z)
	lista2 = (u, z)
	adj[u].append(lista1)
	adj[v].append(lista2)
 
dfs((1,1))
 
print len(aux)
for elem in aux: 
	print elem,
