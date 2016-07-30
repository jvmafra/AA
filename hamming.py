a = raw_input()
b = raw_input()

tamanho = len(a)

def calculaDistancia(a, b):
	soma = 0
	for i in range(len(a)):
		soma += abs(int(a[i]) - int(b[i]))
	
	return soma


i = 0
j = len(a)
sum = 0
while (j <= len(b)):
	string = b[i:j]
	sum += calculaDistancia(string, a)
	i += 1
	j += 1


print sum
	
	
	
