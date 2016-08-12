
def dfs (v, aux):
        lista[v] = True
        aux.append(chr(v + ord('a')))
        for u in adj[v]:
        	if lista[u] == False:
        		dfs(u, aux)
        
        return aux
 
consultas = int(raw_input())
 
for i in range(consultas):
	par = map(int, raw_input().split())
	vertices = par[0]
	adj = [[] for x in xrange(vertices)]
	lista = [False]*vertices
	arestas = par[1]
	for y in range(arestas):
		aresta = raw_input().split()
		adj[ord(aresta[0]) - 97].append(ord(aresta[1]) - 97)
		adj[ord(aresta[1]) - 97].append(ord(aresta[0]) - 97)
	
	print "Case #%d:" % (i + 1)
 	cont = 0
	for j in range(len(lista)):
		if lista[j] == False:
			cont += 1
			auxList = dfs(j, [])
			auxList.sort()
			string = ""
			for elem in auxList:
				string += elem + ","
			
			print string
			
	
	print "%d connected components" % cont
	print ""
