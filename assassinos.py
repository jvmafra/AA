
mapa_assassinos = {}
mortos = []

while True:
	
	try:
		entrada = raw_input().split()
		
		mortos.append(entrada[1])
		
		if (entrada[0] in mapa_assassinos):
			mapa_assassinos[entrada[0]] += 1
		else:
			mapa_assassinos[entrada[0]] = 1

	except EOFError:
		break


for morto in mortos:
	if (morto in mapa_assassinos):
		mapa_assassinos[morto] = 0

assassinos_ordered = list(mapa_assassinos.keys())

assassinos_ordered.sort()
print "HALL OF MURDERERS"
for chave in assassinos_ordered:
	if (mapa_assassinos[chave] != 0):
		print "%s %d" % (chave, mapa_assassinos[chave])
		
	
