def analisa(string, letras_favoritas):
	cont = 0
	for i in string:
		if i in letras_favoritas:
			cont += 1
	
	
	return cont

entrada = map(int, raw_input().split())

letras_favoritas = raw_input()
nome = raw_input()

melhor_nome = nome
num = analisa(nome, letras_favoritas)

for i in range(entrada[2]):
	troca = raw_input().split()
	nome.replace(troca[1], troca[0])
	print nome
	analise = analisa(nome, letras_favoritas)
	
	if (analise > num):
		melhor_nome = nome
		num = analise

print num
print melhor_nome
