N, M = map(int, raw_input().split())

adj = [[0 for x in range(N+1)] for y in range(N+1)]

for i in range(M):
	u, v = map(int, raw_input().split())
	adj[u][v] = 1
	adj[v][u] = 1

vis = [0]*(N+1)

def dfs(vertice):
	vis[vertice] = 1
	for j in range(N+1):
		if (adj[vertice][j] == 1):
			if (vis[j] == 0):
				dfs(j)


cont = 0
for i in range(1, N+1):
	if (vis[i] == 0):
		cont += 1
		dfs(i)


print cont
	
