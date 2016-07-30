N = int(raw_input())
entradas = map(int, raw_input().split())
juicys = int(raw_input())
m = map(int, raw_input().split())
total = sum(entradas)


mapa = {}
pilha = 1
n = 0
fim = entradas[n]
for i in range(total):
	numero = i + 1
	if (numero <= fim):
		mapa[numero] = pilha
	else:
		pilha += 1
		n += 1
		fim = fim + entradas[n]
		mapa[numero] = pilha
	

for i in range(juicys):
	print mapa[m[i]]
